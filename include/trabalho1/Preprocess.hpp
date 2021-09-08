#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <fstream>

namespace trabalho1{


    class Preprocess{
        public:
            Preprocess();
            ~Preprocess() {};

            struct conde_struct
                {
                    std::vector<std::string> code_line;
                    std::vector<int> line; 
                };
        
            void show_arg_name(std::string arg);
            void load_code_file(std::string file_name);
            void stf(); 
            conde_struct get_code();
            std::string upper(std::string code_line);
            std::string get_file_name();

        private:
            void initialize();

            std::string file_name_;
            conde_struct vector_code_line_, vector_code_line_stf_;
                    
    };

}

#endif
