
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#define GL_SILENCE_DEPRECATION
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <creature/creature.h>
#include<chrono>

using namespace cellworld;



enum Scene{
    start_screen,
    creation_of_the_world,
    simulation_of_the_world
};

static void HelpMarker(const char* desc, int width)
{
    ImGui::SameLine();
    ImGui::TextDisabled("(?)"); 
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
    {
        ImGui::BeginTooltip();
        ImGui::SetWindowFontScale(width / 3072.0f);
        ImGui::PushTextWrapPos(ImGui::GetFontSize()*35);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}





int main()
{   
    Eigen::initParallel();
    std::random_device rd;
    int current_mode=start_screen;
    unsigned int seed=0;
    bool pause = 1;
    bool visualise = 1;
    unsigned int size_x=100;
    unsigned int size_y=50;
    const char* file="last_safe";
    unsigned int file_exists = findFile(file);
    ImTextureID texture;
    
    Field test_field;

    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Cool simulation", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    gladLoadGL();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImFontConfig font_cfg;
    font_cfg.SizePixels = 64.0f;
    io.Fonts->AddFontDefault(&font_cfg);
    
    int width,height;
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoScrollbar;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoBackground;
    window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
    clock_t start, end1,end2;
    while (!glfwWindowShouldClose(window))
    {
        
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        float fps=ImGui::GetIO().Framerate;
        glfwGetWindowSize(window, &width, &height);
        if (width==0)
            width=1;
        if (current_mode == start_screen) {

            ImGui::SetNextWindowPos({ width*0.25f,height * 0.2f });
            ImGui::SetNextWindowSize({ width * 0.5f,height * 0.2f });
            ImGui::Begin("Start screen 1", NULL, window_flags);
            ImGui::SetWindowFontScale(width / 2048.0f);
            if (ImGui::Button("Create new world", { width * 0.5f, height*0.2f })) {
                current_mode = creation_of_the_world;
            }
            ImGui::End();


            ImGui::SetNextWindowPos({ width * 0.25f,height * 0.6f });
            ImGui::SetNextWindowSize({ width * 0.5f,height * 0.3f });
            ImGui::Begin("Start screen 2", NULL, window_flags);
            ImGui::SetWindowFontScale(width / 2048.0f);
            if (!file_exists)
                ImGui::BeginDisabled();
            if (ImGui::Button("Continue", { width * 0.5f, height * 0.2f })) {
                loadWorld(file,&test_field,&Creature::coeff_);
                current_mode=simulation_of_the_world;
                texture = test_field.createTexture();
            }
            if (!file_exists)
                ImGui::EndDisabled();
            ImGui::End();


        }
        if (current_mode == creation_of_the_world) {
            ImGui::SetNextWindowPos({ width * 0.15f,height * 0.15f });
            ImGui::SetNextWindowSize({ width * 0.8f,height * 0.8f });
            ImGui::Begin("Creation of a world", NULL, window_flags);
            ImGui::SetWindowFontScale(width / 3072.0f);


            ImGui::InputScalar("Seed", ImGuiDataType_U32, &seed);  HelpMarker("if seed=0, program generates random seed",width);
            ImGui::InputScalar("Width", ImGuiDataType_U32 , &size_x);
            ImGui::InputScalar("Height", ImGuiDataType_U32, &size_y);
            ImGui::NewLine();
            ImGui::Text("Coefficients");
            ImGui::InputFloat("Mutation strength",  &Creature::coeff_[mutation_strength]);
            HelpMarker("defines genome differnce between parent and child \n 0 - child is exact copy of parent \n 1 - child's genome is independent from parent",width);

            ImGui::InputFloat("Change speed module cost", &Creature::coeff_[change_speed_module_cost]);
            HelpMarker("when creature changes speed, creature's energy decreases by coeff*(change_speed_module^2)",width);

            ImGui::InputFloat("Weight capacity", &Creature::coeff_[mass_capacity]);
            HelpMarker("creature's max energy is coeff*creature's mass",width);

            ImGui::InputFloat("Weight into energy", &Creature::coeff_[mass_into_energy]);
            HelpMarker("1*mass <=> coeff*energy \n mass transforms into energy when creature dies \n energy transforms into mass when creature creates child ",width);
            
            ImGui::InputFloat("Starting energy", &Creature::coeff_[starting_energy]);
            HelpMarker("after spawn creature's energy is coeff*max energy",width);

            ImGui::InputFloat("Weight cost", &Creature::coeff_[mass_cost]);
            HelpMarker("every simulation step creature's energy decreases by mass*coeff",width);

            ImGui::InputFloat("Braking force", &Creature::coeff_[braking_force]);
            HelpMarker("every simulation step creature's module speed decreases by coeff",width);

            if (ImGui::Button("Cancel", { width * 0.3f, height * 0.1f })) {
                current_mode = start_screen;
            }
            ImGui::SameLine();
            if (ImGui::Button("Create new world", { width * 0.3f, height * 0.1f })) {
                if (seed == 0) {
                    seed=rd();
                }
                generator_=std::mt19937(seed);
                test_field=Field(size_x,size_y);
                current_mode = simulation_of_the_world;
                texture=test_field.createTexture();
            }
            ImGui::End();
        }
        if (current_mode==simulation_of_the_world){

            ImGui::SetNextWindowPos({ 0,0 });
            ImGui::SetNextWindowSize({ width * 1.f,height * 0.1f });
            ImGui::Begin("Interface", NULL, window_flags);
            ImGui::SetWindowFontScale(width / 3072.0f);
            if (ImGui::Button("Spawn Creature")) {
                Position pos= test_field.generatePosition();
                test_field.spawnCreature(pos);
            }
            ImGui::SameLine();
            if (ImGui::Button("Spawn Food")) {
                Position pos = test_field.generatePosition();
                std::uniform_real_distribution<float> dis(-1000.0, 1000.0);
                test_field.spawnFood(dis(generator_),pos);
            }
            ImGui::SameLine();
            if (ImGui::Button("Save")) {
                saveWorld(file, &test_field, &Creature::coeff_);
                file_exists = findFile(file);
            }
            ImGui::SameLine();
            
            if (ImGui::Button("Clear")) {
                test_field.clear();
            }

            ImGui::SameLine();

            if (ImGui::Button("Make one step")) {
                test_field.updatePositions();
                test_field.updateStates();
            }

            ImGui::SameLine();
            if (ImGui::Button("Return")) {
                current_mode=start_screen;
                test_field.deleteTexture();
            }
            ImGui::SameLine();
            ImGui::Checkbox("Paused", &pause);
            if (!pause) {
                test_field.updatePositions();
                test_field.updateStates();
            }
            ImGui::SameLine();
            ImGui::Checkbox("Visualise", &visualise);
            ImGui::SameLine();
            ImGui::Text("FPS: %f ",fps);
            ImGui::End();

            if (visualise) {
                ImGui::SetNextWindowPos({ width * 0.01f,height * 0.1f });
                ImGui::SetNextWindowSize({ width * 0.99f,height * 0.9f });
                ImGui::Begin("Field", NULL, window_flags);
                test_field.updateTexture();
                ImGui::Image(texture, { width * 0.98f,height * 0.85f });
                ImGui::End();
            }
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();


	return 0;
}
