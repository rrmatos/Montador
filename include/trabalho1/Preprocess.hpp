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
        
            void show_arg_name(std::string arg);
            void read_code_file(std::string file_name);
            void section_text_first();
            std::vector<std::string> get_code();
            std::string to_capital_letter(std::string code_line);

        private:
            void initialize();
            std::string file_name_;
            std::vector<std::string> vector_code_line_, vector_code_line_stf_;
                    
    };

}

#endif
