

#ifndef EVOLVING_WORLD_2023_Q2
#define EVOLVING_WORLD_2023_Q2


#include <array>
#include <vector>
#include <random>
#include "imgui.h"
#include "imgui_internal.h"
#include <fstream>



inline std::mt19937 generator_;

namespace cellworld
{

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



using NeuronNetwork= std::array<float, (4 * look_input_count + input_neurons_count)* output_neurons_count>;//возможно придётся усложнить, но пока как базовый вариант
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

    Creature makeChild(const Position& pos);
    Creature makeLeftover();
    
    int getState() { return state_; }
    int getDirection(){return speed_direction_;}
    int getSpeed(){return speed_module_;}
    int getX() { return pos_x_; }
    int getY() { return pos_y_; }
    float getEnergy() { return energy_; }
    float getEnergyLimit(){return energy_limit_;}
    int getMass(){return (creatures_genome_.mass);}
    bool wantToReproduce() {return output_neurons_[reproduce]>0; }
    unsigned int getColor() { return (creatures_genome_.color); }
    unsigned int getRed() { return (getColor() & 0xff); }
    unsigned int getGreen() { return ((getColor()>>8) & 0xff); }
    unsigned int getBlue() { return((getColor() >> 16) & 0xff); }
    
    void look(Creature&, int direction);
    void getInfo();
    void reverseInput();
    void think();
    void act();
    void eat(Creature&);
    void die();
    void stopExisting(){state_=not_exist;creatures_genome_.color=base_color_;}

    static Genome generateGenome();
    static void mixGen(float& gen1, const float& gen2);
    static unsigned int mixGen(const unsigned int& gen1, const unsigned int& gen2);
    static Genome createGenome(const Genome& ancestor);
    static unsigned int energyColor(int energy);
    
    inline static std::array<float, coefficients_count> coeff_{0};

    inline static unsigned int base_color_= 0xffAfAfAf;
    


    
    int pos_x_;
    int pos_y_;

    
private:

    int state_;
    float energy_;
    float energy_limit_;
    int speed_module_;
    int speed_direction_;

    Genome creatures_genome_;

    std::array<float, 4 * look_input_count + input_neurons_count> input_neurons_;
    std::array<float, output_neurons_count> output_neurons_;
    
};



void conjoin(Creature&, Creature&); //решает, что будет, если два существа встретились

class Field{

public:
    Field(int size_x=0, int size_y=0) : size_x_(size_x), size_y_(size_y), size_(size_x*size_y), zoo_(size_x*size_y, Creature()), empty_zoo_(size_x* size_y, Creature()) {}
    void spawnCreature(const Position& pos);
    void spawnCreature(Creature child);
    void spawnFood(float energy, const Position&);
    void updatePositions();
    void updateStates();
    Creature& getCreature(const Position& pos);
    const Creature& operator[](const int& index) const {return zoo_[index];}
    Creature& operator[](const int& index) { return zoo_[index]; }
    unsigned int getColor(const Position& pos) {return getCreature(pos).getColor();}
    int sizeX() const { return size_x_; }
    int sizeY() const { return size_y_; }
    bool validX(int x);
    bool validY(int y);
    Position generatePosition();
    Position findClosePosition(Creature& ancestor);
    Creature& findCreature(Creature&, int direction);
    void clear();
    void visualise(ImGuiWindow*);
    inline static Creature bad_creature=Creature();

private:
    int size_x_;
    int size_y_;
    int size_;
    std::vector<Creature> zoo_;
    std::vector<Creature> empty_zoo_;
};

void saveWorld(const char* path, Field* current_field, std::array<float, coefficients_count>* coefficents);
bool findFile(const char* path);
void loadWorld(const char* path, Field* current_field, std::array<float, coefficients_count>* coefficents);





};

#endif
