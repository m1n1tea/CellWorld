

#ifndef EVOLVING_WORLD_2023_Q2
#define EVOLVING_WORLD_2023_Q2
#define EIGEN_NO_DEBUG
#include <array>
#include <vector>
#include <random>
#define GL_SILENCE_DEPRECATION
#include<glad/glad.h>
#include <fstream>
#include<iostream>
#include<omp.h>
#include<chrono>
#include <Eigen/Core>





namespace cellworld
{
    inline std::mt19937 generator_;
    inline std::uniform_real_distribution<float> dis(-4.0f, 4.0f);

    enum State {
        not_exist,
        dead,
        alive,
    };

    enum Directions {
        up,
        down,
        left,
        right,
        
    };
    
    enum Coefficients {
        mass_into_energy,
        mass_capacity,
        starting_energy,
        mass_cost,
        change_speed_module_cost,
        braking_force,
        mutation_strength,

        coefficients_count

    };

    enum InputNeurons {

        pos_x,
        pos_y,
        speed_module,
        energy,
        bias,

        input_neurons_count
    };
    enum OutputNeurons {
        change_speed_module,
        vertical_or_horizontal,
        decrease_or_increase,
        reproduce,
        
        output_neurons_count
    };

    enum LookInput {
        distance,
        color_red,
        color_green,
        color_blue,

        look_input_count
    };


using NeuronNetwork = Eigen::Matrix<float,output_neurons_count , (4 * look_input_count + input_neurons_count)>;
using Position = std::pair<int,int>;
constexpr Position bad_position={-1,-1};

struct Genome {
    Genome() :color(),mass(),neuron_network() {}
    explicit Genome(unsigned int in_color):color(in_color),mass(),neuron_network() {}
    unsigned int color;
    unsigned int mass;
    NeuronNetwork neuron_network;
};



class Creature {
public:
    Creature(const Genome& gen, const Position& pos);
    Creature();
    Creature(float energy, const Position& pos);
    

    Creature(const Creature&)=default;
    Creature(Creature&&) = default;
    Creature& operator=(const Creature&) = default;
    Creature& operator=(Creature&&) = default;

    void makeAlive(Creature& ancestor, const Position& pos);
    
    
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
    bool wantToReproduce()const {return (output_neurons_.size()!=0) && (output_neurons_.coeff(reproduce)>0); }
    const unsigned int& getColor() const { return (creatures_genome_.color); }
    unsigned int getRed() const { return (getColor() & 0xff); }
    unsigned int getGreen() const { return ((getColor()>>8) & 0xff); }
    unsigned int getBlue() const { return((getColor() >> 16) & 0xff); }
    
    void look(Creature&, int direction);
    void getInfo();
    void reverseInput();
    void prepare();
    void think();
    void act();
    void eat(Creature&);
    void addEnergy(const float& energy);
    void die();
    void stopExisting(){state_=not_exist;creatures_genome_.color=base_color_;}

    static Genome generateGenome();
    static void generateGenome(Genome&);
    static void mixGen(float& gen1, const float& gen2);
    static unsigned int mixGen(const unsigned int& gen1, const unsigned int& gen2);
    static Genome createGenome(const Genome& ancestor);
    static unsigned int energyColor(int energy);
    
    inline static std::array<float, coefficients_count> coeff_{0};

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
    Creature& getCreature(const Position& pos);
    const Creature& getCreature(const Position& pos) const;
    const Creature& operator[](const int& index) const {return *zoo_ptr_[index];}
    Creature& operator[](const int& index) { return *zoo_ptr_[index]; }
    unsigned int getColor(const Position& pos)const {return getCreature(pos).getColor();}
    unsigned int getColor(const int& index) const { return zoo_ptr_[index]->getColor(); }
    int sizeX() const { return size_x_; }
    int sizeY() const { return size_y_; }
    bool validX(const int& x) const;
    bool validY(const int& y) const;
    Position generatePosition();
    Position findClosePosition(Creature* ancestor);
    Creature& findCreature(Creature*, int direction);
    void clear();
    void* createTexture();
    void updateTexture();
    void deleteTexture();
    inline static Creature bad_creature=Creature();

private:
    int size_x_;
    int size_y_;
    int size_;
    std::vector<Creature*> zoo_ptr_;
    std::vector<Creature*> empty_zoo_ptr_;
    std::vector<Creature> storage_;
    std::vector<unsigned int> colors;
    
};




void saveWorld(const char* path, Field* current_field, std::array<float, coefficients_count>* coefficents);
bool findFile(const char* path);
void loadWorld(const char* path, Field* current_field, std::array<float, coefficients_count>* coefficents);





};

#endif
