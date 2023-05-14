

#ifndef EVOLVING_WORLD_2023_Q2_UI
#define EVOLVING_WORLD_2023_Q2_UI

#include "imgui.h"
#include<creature/creature.h>
#include<save_system/save_system.h>
#include "imgui_stdlib.h"
namespace cellworld {

    enum Scene {
        start_screen,
        creation_of_the_world,
        load_world_screen,
        simulation_of_the_world,
    };


    class WindowTemplates {
    public:
        static const ImGuiWindowFlags invisibleWindow = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove
            | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;
        static const ImGuiWindowFlags scrollBarOnly = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove
            | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;
    };


    static void HelpMarker(const char* desc, int width)
    {
        ImGui::SameLine();
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
        {
            ImGui::BeginTooltip();
            ImGui::SetWindowFontScale(width / 4096.0f);
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35);
            ImGui::TextUnformatted(desc);
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }

    
    class UI {
    public:
        UI() : scene_(0), previous_scene_(0), scene_is_changed_(0), width_(1), height_(1), seed_(0) {}
        void updateWindowSize(int width, int height){ width_ =width; height_= height;}
        void loadScene();
        FileSystem file_names_;
    private:
        void sceneUpdate(int scene);
        void startScreen();
        void CreationOfTheWorld();
        void loadWorldScreen(); 
        void SimulationOfTheWorld();

        int scene_;
        int previous_scene_;
        bool scene_is_changed_;
        int width_;
        int height_;
        Field init_field_;
        unsigned int seed_;
    };  
}

#endif