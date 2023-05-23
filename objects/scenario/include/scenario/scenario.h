

#ifndef EVOLVING_WORLD_2023_Q2_SCENARIO
#define EVOLVING_WORLD_2023_Q2_SCENARIO

#include<creature/creature.h>
#include"imgui.h"
#include<array>
#include<vector>
#include<random>
#include<omp.h>
namespace cellworld {
    class Scenario: public Field {
        friend void saveWorld(const char* path, Scenario* current_field, unsigned int seed);
        friend void loadWorld(const char* path, Scenario* current_field, unsigned int& seed);
    public:
        Scenario();
        Scenario(int size_x, int size_y);


        void makeNew();
        void makeOneStep();
        void spawnCreatures(int amount);//использовать только на пустом поле
        void makeRewards(Position,Position, float strength);//за нахожение на прямоугольнике, заданный двумя позициями, существо каждый ход получает энергию=strength
        void rewardsEditor(ImVec2 window_pos, ImVec2 window_size, float strength, ImTextureID texture);
        void giveRewards();

        void makeCycle(int len);
        void newCycle();
        void CancelRewardsChange(){ std::swap(rewards_, rewards_backup_); }
        void resetRewards();
        void updateRewardsTexture();

        int getInitialPopulation(){return initial_population_;}
        
    private:
        Position convertInput(ImVec2 begin, ImVec2 input, int square_size);

        bool is_cycle_;
        int initial_population_;
        int cycle_len_;
        long long iteraion_;
        std::vector<float> rewards_;
        std::vector<float> rewards_backup_;
        
    };
    
    
}

#endif