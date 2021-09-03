#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <iostream>
#include <vector>
#include <array>
#include <boost/algorithm/string.hpp> 
#include <cctype>
#include <fstream>
#include <unordered_map> 

namespace trabalho1{

    using Param = std::unordered_map<std::string, std::vector<std::string>>;

    class Preprocess{
        public:
            Preprocess();
            ~Preprocess() {};

            void show_arg_name(std::string arg);
            void read_code_file(std::string file_name);
            void section_text_first();
            std::string to_capital_letter(std::string code_line);

        private:
            std::vector<std::string> op_word_len;
            Param opcodes_;
            const Param default_opcodes_ = {  
                    std::make_pair("ADD",    (op_word_len = {"01", "2"})),
                    std::make_pair("ADD",    (op_word_len = {"01", "2"})),
                    std::make_pair("SUB",    (op_word_len = {"02", "2"})),
                    std::make_pair("MULT",   (op_word_len = {"03", "2"})),
                    std::make_pair("DIV",    (op_word_len = {"04", "2"})),
                    std::make_pair("JNP",    (op_word_len = {"05", "2"})),
                    std::make_pair("JNPN",   (op_word_len = {"06", "2"})),
                    std::make_pair("JNPP",   (op_word_len = {"07", "2"})),
                    std::make_pair("JNPZ",   (op_word_len = {"08", "2"})),
                    std::make_pair("COPY",   (op_word_len = {"09", "3"})),
                    std::make_pair("LOAD",   (op_word_len = {"10", "2"})),
                    std::make_pair("STORE",  (op_word_len = {"11", "2"})),
                    std::make_pair("INPUT",  (op_word_len = {"12", "2"})),
                    std::make_pair("OUTPUT", (op_word_len = {"13", "2"})),
                    std::make_pair("STOP",   (op_word_len = {"14", "1"}))

                };

            void initialize();
            std::string file_name_;
            std::vector<std::string> vector_code_line_, vector_code_line_stf_;
            struct sim_table_uni_
            {
                std::string simble;
                int value;
                bool def;
                std::vector<int> list; 
            };

            std::vector<sim_table_uni_> SimTable_;

                    
    };

}

#endif
