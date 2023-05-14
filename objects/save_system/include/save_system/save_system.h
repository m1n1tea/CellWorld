
#ifndef EVOLVING_WORLD_2023_Q2_FILESYSYTEM
#define EVOLVING_WORLD_2023_Q2_FILESYSYTEM


#include<fstream>
#include<vector>
#include<string>
#include<cstdio>
#include<utility>

namespace cellworld {
    class FileSystem {
    public:
        FileSystem(const char* name) : store_names_file_(name) { store_names_file_+=".txt"; }
        FileSystem() : store_names_file_("file_names.txt") {}
        void addFileName(const char* file_name);
        void removeFileName(int index);
        void saveFileNames();
        void loadFileNames();
        void checkFileNames();
        void checkFileName(int index);
        bool findFileName(const char* file_name);
        std::string getValidFileName(std::string file_name);
        const std::vector<std::string>& getFileNames() { return files_; }
    private:
        std::string store_names_file_;
        std::vector<std::string> files_;
    };
}

#endif