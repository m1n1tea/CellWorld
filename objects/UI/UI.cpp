#include "UI/UI.h"
namespace cellworld{
    
    void UI::loadScene()
    {
        switch (scene_)
        {
        case start_screen:
            startScreen();
            break;
        case creation_of_the_world:
            CreationOfTheWorld();
            break;
        case load_world_screen:
            loadWorldScreen();
            break;
        case simulation_of_the_world:
            SimulationOfTheWorld(); 
            break;
        
        default:
            scene_= start_screen;
            break;
        }
        if (scene_is_changed_)
            sceneUpdate(scene_);
        scene_is_changed_ = (scene_ != previous_scene_);
    }
    void UI::sceneUpdate(int scene)
    {
        previous_scene_=scene_;
        scene_=scene;
    }
    void UI::startScreen()
    {
        ImGui::SetNextWindowPos({ width_ * 0.25f,height_ * 0.2f });
        ImGui::SetNextWindowSize({ width_ * 0.5f,height_ * 0.2f });
        ImGui::Begin("Start screen 1", NULL, WindowTemplates::invisibleWindow);
        ImGui::SetWindowFontScale(width_ / 2048.0f);
        if (ImGui::Button("Create new world", { width_ * 0.5f, height_ * 0.2f })) {
            sceneUpdate(creation_of_the_world);
        }
        ImGui::End();

        ImGui::SetNextWindowPos({ width_ * 0.25f,height_ * 0.6f });
        ImGui::SetNextWindowSize({ width_ * 0.5f,height_ * 0.3f });
        ImGui::Begin("Start screen 2", NULL, WindowTemplates::invisibleWindow);
        ImGui::SetWindowFontScale(width_ / 2048.0f);
        if (ImGui::Button("Load world", { width_ * 0.5f, height_ * 0.2f })) {
            sceneUpdate(load_world_screen);
        }
        ImGui::End();

    }

    void UI::CreationOfTheWorld()
    {
        static int size_x=100;
        static int size_y =50;
        static std::random_device rd;
        static int initial_population=0;
        static float strenght=0;
        if (scene_is_changed_) {
            size_x=scenario_.sizeX();
            size_y = scenario_.sizeY();
            initial_population = scenario_.getInitialPopulation();
            scenario_.makeNew();
            scenario_.createTexture();
            scenario_.updateRewardsTexture();
        }
        if (scenario_.sizeX() != size_x || scenario_.sizeY() != size_y) {
            scenario_.deleteTexture();
            scenario_=Scenario(size_x,size_y);
            scenario_.createTexture();
            scenario_.updateRewardsTexture();
        }


        ImGui::SetNextWindowPos({ width_ * 0.15f,height_ * 0.05f });
        ImGui::SetNextWindowSize({ width_ * 0.8f,height_ * 0.9f });
        ImGui::Begin("Creation of a world", NULL, WindowTemplates::scrollBarOnly);
        ImGui::SetWindowFontScale(width_ / 3072.0f);

        ImGui::Indent(width_ * 0.2f);
        if (ImGui::Button("Reset all", { width_ * 0.3f,height_ * 0.1f })) {
            size_x = 100;
            size_y = 50;
            seed_ = 0;
            initial_population = 0;
            strenght = 0;
            for (int i = 0; i < coefficients_count; ++i)
                Creature::coeff_[i] = 0;
            scenario_.resetRewards();
            scenario_.updateRewardsTexture();
        }
        ImGui::Unindent(width_ * 0.2f);
        ImGui::NewLine();
        
        ImGui::Checkbox("breed", &Creature::is_breedable);
        ImGui::InputScalar("seed", ImGuiDataType_U32, &seed_);  HelpMarker("if seed_=0, program generates random seed_", width_);
        ImGui::InputScalar("width", ImGuiDataType_U32, &size_x);
        ImGui::InputScalar("height", ImGuiDataType_U32, &size_y);
        ImGui::InputScalar("initial polulation", ImGuiDataType_U32, &initial_population);
        ImGui::NewLine();
        ImGui::Text("Coefficients");

        ImGui::InputFloat("Mutation strength", &Creature::coeff_[mutation_strength]);
        HelpMarker("defines genome differnce between parent and child \n 0 - child is exact copy of parent \n 1 - child's genome is independent from parent", width_);

        ImGui::InputFloat("Change speed module cost", &Creature::coeff_[change_speed_module_cost]);
        HelpMarker("when creature changes speed, creature's energy decreases by coeff*(change_speed_module^2)", width_);

        ImGui::InputFloat("Weight capacity", &Creature::coeff_[mass_capacity]);
        HelpMarker("creature's max energy is coeff*creature's mass", width_);

        ImGui::InputFloat("Weight into energy", &Creature::coeff_[mass_into_energy]);
        HelpMarker("1*mass <=> coeff*energy \n mass transforms into energy when creature dies \n energy transforms into mass when creature creates child ", width_);

        ImGui::InputFloat("Starting energy", &Creature::coeff_[starting_energy]);
        HelpMarker("after spawn creature's energy is coeff*max energy", width_);

        ImGui::InputFloat("Weight cost", &Creature::coeff_[mass_cost]);
        HelpMarker("every simulation step creature's energy decreases by mass*coeff", width_);

        ImGui::InputFloat("Braking force", &Creature::coeff_[braking_force]);
        HelpMarker("every simulation step creature's module speed decreases by coeff", width_);

        ImGui::NewLine();
        ImGui::InputFloat("Strength", &strenght);
        if (ImGui::Button("Cancel", { width_ * 0.3f,height_ * 0.1f })) {
            scenario_.CancelRewardsChange();
            scenario_.updateRewardsTexture();
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset rewards", { width_ * 0.3f,height_ * 0.1f })) {
            scenario_.resetRewards();
            scenario_.updateRewardsTexture();
        }
        ImGui::BeginChild("Rewards editor", { width_ * 0.99f,height_ * 0.9f },0,WindowTemplates::invisibleWindow);
        scenario_.rewardsEditor(ImGui::GetWindowPos(), ImGui::GetWindowSize(),strenght,scenario_.getTexture());
        ImGui::EndChild();
        ImGui::NewLine();

        if (ImGui::Button("Return", { width_ * 0.3f, height_ * 0.1f })) {
            scenario_.deleteTexture();
            sceneUpdate(start_screen);
        }
        ImGui::SameLine();
        if (ImGui::Button("Create new world", { width_ * 0.3f, height_ * 0.1f })) {
            if (seed_ == 0) {
                seed_ = rd();
            }
            generator_ = std::mt19937(seed_);
            scenario_.spawnCreatures(initial_population);
            scenario_.deleteTexture();
            sceneUpdate(simulation_of_the_world);
        }
        ImGui::End();
    }

    void UI::loadWorldScreen()
    {   
        const std::vector<std::string>& file_names= file_names_.getFileNames();
        ImGui::Begin("Choose world", NULL, WindowTemplates::scrollBarOnly);
        if (scene_is_changed_) {
            file_names_.checkFileNames();
            file_names_.saveFileNames();
        }

        if (ImGui::Button("Return")) {
            sceneUpdate(start_screen);
        }

        ImGui::SetWindowFontScale(width_ / 3072.0f);
        for (int i=file_names.size()-1; i>=0 ; --i) {
            ImGui::PushID(i);
            ImGui::Text(file_names[i].c_str());
            ImGui::SameLine();
            if (ImGui::Button("Load")) {
                loadWorld(file_names[i].c_str(), &scenario_, seed_);
                sceneUpdate(simulation_of_the_world);
            }
            ImGui::SameLine();
            if (ImGui::Button("Delete")) {
                file_names_.removeFileName(i);
                scene_is_changed_ = 1;
            }
            ImGui::PopID();
            
        }
        ImGui::End();
        
    }

    void UI::SimulationOfTheWorld()
    {

        static bool pause;
        static bool visualise;
        static bool show_rewards;
        static std::string file_name;
        static ImTextureID rewards_texture_;
        if (scene_is_changed_) {
            pause=1;
            visualise=1;
            show_rewards=0;

            scenario_.createTexture();
            scenario_.updateRewardsTexture();
            rewards_texture_ =scenario_.getTexture();
            scenario_.deleteTexture();

            scenario_.createTexture();
            file_name="New world";
        }  
        float fps = ImGui::GetIO().Framerate;
        ImGui::SetNextWindowPos({ 0,0 });
        ImGui::SetNextWindowSize({ width_ * 1.f,height_ * 0.1f });
        ImGui::Begin("Interface", NULL, WindowTemplates::invisibleWindow);
        ImGui::SetWindowFontScale(width_ / 3584.0f);
        ImGui::SameLine();


        if (ImGui::Button("Save as")) {
            if (file_names_.findFileName(file_name.c_str())) {
                std::string new_name= file_names_.getValidFileName(file_name);
                saveWorld(new_name.c_str(), &scenario_, seed_);
                file_names_.addFileName(new_name.c_str());
                file_names_.saveFileNames();
            }
            else{
                saveWorld(file_name.c_str(), &scenario_, seed_);
                file_names_.addFileName(file_name.c_str());
                file_names_.saveFileNames();
            }
        }
        ImGui::SameLine();
        ImGui::InputText("##foo",&file_name);
        ImGui::SameLine();
        if (ImGui::Button("Make one step")) {
            scenario_.makeOneStep();
        }

        ImGui::SameLine();
        if (ImGui::Button("Return")) {
            sceneUpdate(start_screen);
            scenario_.deleteTexture();
        }
        ImGui::SameLine();
        ImGui::Checkbox("Paused", &pause);
        ImGui::SameLine();
        ImGui::Checkbox("Visualise", &visualise);
        ImGui::SameLine();
        ImGui::Checkbox("Show Rewards", &show_rewards);
        //ImGui::SameLine();
        //ImGui::Text("\tFPS: %f",fps);s
        ImGui::End();
        

        if (!pause) {
            scenario_.makeOneStep();
        }

        if (visualise) {
            ImGui::SetNextWindowPos({ width_ * 0.01f,height_ * 0.1f });
            ImGui::SetNextWindowSize({ width_ * 0.99f,height_ * 0.9f });
            ImGui::Begin("Field", NULL, WindowTemplates::invisibleWindow);
            scenario_.updateTexture();
            int square_size= width_ * 0.98f/ scenario_.sizeX();
            if (square_size>height_*0.85f/ scenario_.sizeY())
                    square_size= height_ * 0.85f / scenario_.sizeY();
            ImGui::Image(scenario_.getTexture(), {scenario_.sizeX() * square_size * 1.f,  scenario_.sizeY() * square_size * 1.f});
            if (show_rewards) {
                ImGui::SameLine(0.01f);
                ImGui::Image(rewards_texture_, { scenario_.sizeX() * square_size * 1.f,  scenario_.sizeY() * square_size * 1.f });
            }
            ImGui::End();
        }
    }




}
