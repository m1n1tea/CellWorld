
/*!
*\file
*\brief Ядро программы, описано поведение мира.
*
*Содержит классы существа и поля, логику взаимодействия между ними.
*/

#ifndef EVOLVING_WORLD_2023_Q2
#define EVOLVING_WORLD_2023_Q2
#define EIGEN_NO_DEBUG
#include <array>
#include <vector>
#include <random>
#define GL_SILENCE_DEPRECATION
#include<glad/glad.h>
#include <fstream>
#include<omp.h>
#include <Eigen/Core>




namespace cellworld
{
    /*!
    *
    *\brief Общий детерминированный генератор случайных чисел.
    *Любая генерация случайного числа должна быть сделана с помощью данного генератора(за исключением генерации сида).
    */
    inline std::mt19937 generator_;
    
    /*!
    *
    *\brief Генератор случайных float в диапозоне [-4,4].
    *Определяет разброс значений у весов нейросети.
    */

    inline std::uniform_real_distribution<float> dis(-4.0f, 4.0f);


/*!
* 
*\brief Все возможные состояния существа.
* 
*/
    enum State {
        not_exist,///< существа нет
        dead,///< мёртвое существо
        alive,///< живое существо
    };


    enum Directions {
        up,
        down,
        left,
        right,
        
    };




/*!
*\defgroup Коэффициенты 
*\brief Набор коэффициентов, которые определяют правила мира.
*@{
*/ 

///Набор коэффициентов, которые определяют правила мира.
    enum Coefficients {
/*!
Коэффициент преобразования массы в энергию.\n
Сколько энергии требуется для создания единица массы.
Используется при:
    - смерти сущности,    \tэнергия трупа+= масса*mass_into_energy.
    - рождении сущности,  \tэнергия родителя-=масса ребёнка*mass_into_energy.
*/
        mass_into_energy,


/*!
Коэффициент вместимости массы.
Сколько энергии может хранить в себе единица массы.\n
Макс энергия = mass_capacity * масса существа.
*/
        mass_capacity,


/*!
Коэффициент начальной энергии.
Определяет сколько энергии имеет существо при спавне(не рождении).\n
Энергия = Макс энергия * starting_energy.
*/
        starting_energy,

/*!
Коэффициент стоимости массы.
Определяет сколько энергии живое существо тратит за ход на поддержание единицы массы.\n
Энергия-=масса*mass_cost.
*/
        mass_cost,


/*!
Коэффициент стоимости изменения модуля скорости.
Определяет сколько энергии существо тратит за ход на изменение модуля скорости.\n
Энергия-=(изменение модуля скорости)^2*change_speed_module_cost.

*/
        change_speed_module_cost,


/*!
Коэффициент силы торможения.
Определяет на сколько уменьшается модуль скорости в конце каждого хода.\n
Модуль скорости-=braking_force.
*/
        braking_force,


/*!
Коэффициент мутации.
Определяет на сколько сильно будет отличатся геном ребёнка от родителя.
    -   <=0 - копия родителя.
    -   >=1 - геном не зависит от родителя совсем.\n
Ген ребёнка=ген родителя*(1-mutation_strength) + случайный ген*mutation_strength.
*/
        mutation_strength,


///количество коэффициентов
        coefficients_count

    };

/**@}*/

/*!
*\defgroup Нейросеть
*\brief Все упоминания нейронных сетей
*@{
*/

/*!
*\brief Основные входные нейроны существа Содержит информацию о внутреннем состоянии существа
*/
    enum InputNeurons {
        /// Координата X
        pos_x,

        /// Координата Y
        pos_y,

        /// Модуль скорости
        speed_module,

        /// Энергия
        energy,

        /// Cмещающий нейрон
        bias,

        /// Количество входных нейронов
        input_neurons_count
    };



/*!
*\brief Выходные нейроны существа
*
*/
    enum OutputNeurons {
        ///Изменить модуль скорости
        change_speed_module,

        ///По какой прямой перемещается существо, вертикальной или горизонтальной
        vertical_or_horizontal,

        ///В какую сторону перемещается существо, по увеличению или уменьшению координаты
        decrease_or_increase,

        ///Желание существа размножиться
        reproduce,
        
        /// Количество выходных нейронов
        output_neurons_count
    };


    /*!
    *\brief Дополнительные входные нейроны существа.
    * 
    *Содержит информацию об внешнем окружении существа.\n
    *Для каждого из 4 направлений(верх,низ,право,лево) существо имеет отдельный набор нейронов. \n
    *Поэтому общее количество входных нейронов равно 4 * look_input_count + input_neurons_count.
    */
    enum LookInput {
        /// расстояние от существа до ближайшего существа в одном из направлений
        distance,
        /// уровень красного цвета ближайшего существа
        color_red,
        /// уровень зелёного цвета ближайшего существа
        color_green,
        /// уровень синего цвета ближайшего существа
        color_blue,


        /// Количество входных нейронов
        look_input_count
    };


///Хранит веса нейросети существа
using NeuronNetwork = Eigen::Matrix<float,output_neurons_count , (4 * look_input_count + input_neurons_count)>;

/**@}*/
using Position = std::pair<int,int>;
constexpr Position bad_position={-1,-1};



/*!
*\brief Хранит геном существа.

 В геном входят: 
    - цвет
    - масса
    - веса нейросети существа
*/
struct Genome {
    Genome() :color(),mass(),neuron_network() {}
    explicit Genome(unsigned int in_color):color(in_color),mass(),neuron_network() {}
    unsigned int color;
    unsigned int mass;
    NeuronNetwork neuron_network;
};


/*!
*\brief Класс существа.
*/
class Creature {
public:


/*! @name Специальные конструкторы существа
*По умолчанию модуль скорости равен 0, существо направлено вверх.
*/

///@{
    /*!
    \brief Конструируется живое существо
    \param gen, pos - геном и позиция существа соответсвенно.
    начальная энергия зависит веса(см. \ref Коэффициенты "Коэффициенты")
    */
    Creature(const Genome& gen, const Position& pos);
    ///Конструируется несущетвующее существо
    Creature();
    /*!
    \brief Конструируется неживое существо
    \param energy, pos - энергия и позиция существа соответсвенно.
    */
    Creature(float energy, const Position& pos);
///@}

    Creature(const Creature&)=default;
    Creature(Creature&&) = default;
    Creature& operator=(const Creature&) = default;
    Creature& operator=(Creature&&) = default;


    void makeAlive(Creature& ancestor, const Position& pos);
    void makeAlive(const Position& pos);
    
    
    void buildIO();
    const int& getState() const { return state_; }
    const int& getDirection() const {return speed_direction_;}
    const int& getSpeed() const {return speed_module_;}
    int& getX();
    int& getY();
    float Leftover();
    const float& getEnergy() const  { return energy_; }
    const float& getEnergyLimit() const {return energy_limit_;}
    const int& getMass() const {return (creatures_genome_.mass);}
    bool wantToReproduce()const {return (output_neurons_.size()!=0) && is_breedable && (output_neurons_.coeff(reproduce)>0); }
    const unsigned int& getColor() const { return (creatures_genome_.color); }
    unsigned int getBlue() const { return((getColor() >> 8) & 0xff); }
    unsigned int getGreen() const { return((getColor() >> 16) & 0xff); }
    unsigned int getRed() const { return((getColor() >> 24) & 0xff); }
    const Genome& getGenome(){ return creatures_genome_; }
    
    void look(Creature&, int direction);
    void getInfo();
    void reverseInput();
    void prepare();
    void think();
    void act();
    void eat(Creature&);
    void addEnergy(const float& energy);
    void die();
    void stopExisting(){state_=not_exist;creatures_genome_.color=base_color_; energy_=0; speed_module_=0;}

    static Genome generateGenome();
    static void generateGenome(Genome&);
    static void mixGen(float& gen1, const float& gen2);
    static unsigned int mixGen(const unsigned int& gen1, const unsigned int& gen2);
    static Genome createGenome(const Genome& ancestor);
    static unsigned int energyColor(int energy);
    
    inline static std::array<float, coefficients_count> coeff_{0};
    inline static bool is_breedable=1;

    inline static unsigned int base_color_= 0xAfAfAfff;
    


    
    int pos_x_;
    int pos_y_;

    
private:

    int state_;
    float energy_;
    float energy_limit_;
    int speed_module_;
    int speed_direction_;

    Genome creatures_genome_;
    
    Eigen::MatrixXf input_neurons_;
    Eigen::MatrixXf output_neurons_;
    std::tuple<int,int,float> tmp_;
    
};




void conjoin(Creature*&, Creature*&);
void conjoin(Creature&, Creature&); //решает, что будет, если два существа встретились

class Field{

public:
    Field(int size_x=0, int size_y=0);
    void spawnCreature(const Position& pos);
    void spawnCreature(Creature child);
    void spawnFood(float energy, const Position&);
    void updatePositions();
    void updateStates();

    const Creature& getCreature(const Position& pos) const;
    Creature& getCreature(const Position& pos);

    const Creature& getCreature(const int& index) const { return *zoo_ptr_[index]; }
    Creature& getCreature(const int& index) { return *zoo_ptr_[index]; }

    const Creature& operator[](const int& index) const {return *zoo_ptr_[index];}
    Creature& operator[](const int& index) { return *zoo_ptr_[index]; }

    unsigned int getColor(const Position& pos)const {return getCreature(pos).getColor();}
    unsigned int getColor(const int& index) const { return zoo_ptr_[index]->getColor(); }
    int sizeX() const { return size_x_; }
    int sizeY() const { return size_y_; }
    int size() const { return size_; }
    bool validX(const int& x) const;
    bool validY(const int& y) const;
    Position generatePosition();
    Position findClosePosition(Creature* ancestor);
    Creature& findCreature(Creature*, int direction);
    void clear();
    void createTexture();
    void* getTexture() { return (void*)(texture_); }
    const GLuint& getGLTexture() {return texture_;}
    void updateTexture();
    void unbindTexture();
    inline static Creature bad_creature=Creature();
    
    int countCreatures(int type);

private:
    int size_x_;
    int size_y_;
    int size_;

protected:
    std::vector<Creature*> zoo_ptr_;
    std::vector<Creature*> empty_zoo_ptr_;
    std::vector<Creature> storage_;
    std::vector<unsigned int> colors_;
    GLuint texture_;
    
};










};

#endif
