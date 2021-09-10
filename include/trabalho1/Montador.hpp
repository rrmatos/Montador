#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map> 
#include <cstring>
#include <trabalho1/Preprocess.hpp>



namespace trabalho1{

    using Param = std::unordered_map<std::string, std::vector<std::string>>;
    using Param_d = std::unordered_map<std::string, std::string>;

    class Montador{
        public:
            Montador();
            ~Montador() {};

            

            void show_table();
            void recive_code(Preprocess::conde_struct code_line);
            int get_simble_idx(std::string simble);
            std::vector<std::string> get_tokens_in_line(std::string code_line);
            void label_found(std::string sim, int eddress_counter);
            bool check_sim_table(std::string sim);
            void add_sim_in_list(std::string sim, int eddress_counter);
            bool detect_error(std::vector<std::string> tokens, int line);
            
            bool scanner(std::vector<std::string> tokens, int line);
            bool parser(std::vector<std::string> tokens, int line);
            void semantic_analyzer();
        
            void solve_pendency(std::string sim);
            void generete_obj_file();
            void set_file_name(std::string file_name);
            bool find_element_vector_str(std::vector<std::string> vector_str, std::string str);


            void montar();

        private:

            std::string file_name_;
            std::vector<std::string> op_word_len, code_obj;
            Param opcodes_;
            Param directive_;

            const Param default_opcodes_ = {
                std::make_pair("ADD",    (op_word_len = {"1", "2"})),
                std::make_pair("SUB",    (op_word_len = {"2", "2"})),
                std::make_pair("MULT",   (op_word_len = {"3", "2"})),
                std::make_pair("DIV",    (op_word_len = {"4", "2"})),
                std::make_pair("JMP",    (op_word_len = {"5", "2"})),
                std::make_pair("JMPN",   (op_word_len = {"6", "2"})),
                std::make_pair("JMPP",   (op_word_len = {"7", "2"})),
                std::make_pair("JMPZ",   (op_word_len = {"8", "2"})),
                std::make_pair("COPY",   (op_word_len = {"9", "3"})),
                std::make_pair("LOAD",   (op_word_len = {"10", "2"})),
                std::make_pair("STORE",  (op_word_len = {"11", "2"})),
                std::make_pair("INPUT",  (op_word_len = {"12", "2"})),
                std::make_pair("OUTPUT", (op_word_len = {"13", "2"})),
                std::make_pair("STOP",   (op_word_len = {"14", "1"}))
                
            };

            const Param default_directive_ = {  
                std::make_pair("CONST", (op_word_len = {"0", "2"})),
                std::make_pair("SPACE", (op_word_len = {"0", "2"}))
            };

            void initialize();

            Preprocess::conde_struct vector_code_line_;
            

            struct sim_table_uni_
                {
                    std::string simble;
                    int value;
                    bool def = false ;
                    std::vector<int> list; 
                };

            sim_table_uni_ sim_table_test_;
            sim_table_uni_ line_table_;
            std::vector<sim_table_uni_> SimTable_;
            std::vector<std::string> invalchar_front_ = {"0", "1","2","3","4","5" "6", "7", "8", "9", "#", "," , ":", "/", "\\", "*", "-", "+", ":"};
            std::vector<std::string> invalchar_ = {"#", "," , "/", "\\", "*", "-", "+"};
                  
    };

}

#endif
