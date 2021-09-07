#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map> 
#include <cstring>
#include<bits/stdc++.h>
#include <trabalho1/Preprocess.hpp>



namespace trabalho1{

    using Param = std::unordered_map<std::string, std::vector<std::string>>;

    class Montador{
        public:
            Montador();
            ~Montador() {};

            

            void show_table();
            void populate_simble_table();
            void recive_code(Preprocess::conde_struct code_line);
            int get_simble_idx(std::string simble);
            std::string get_instru_rot_dire();
            std::vector<std::string> get_tokens_in_line(std::string code_line);
            void label_found(std::string sim, int eddress_counter);
            bool check_sim_table(std::string sim);
            void add_sim_in_list(std::string sim, int eddress_counter);

            void montar();


            Preprocess::conde_struct vector_code_line;


        private:

            std::vector<std::string> op_word_len;
            Param opcodes_;
            const Param default_opcodes_ = {  
                    std::make_pair("ADD",    (op_word_len = {"01", "2"})),
                    std::make_pair("ADD",    (op_word_len = {"01", "2"})),
                    std::make_pair("SUB",    (op_word_len = {"02", "2"})),
                    std::make_pair("MULT",   (op_word_len = {"03", "2"})),
                    std::make_pair("DIV",    (op_word_len = {"04", "2"})),
                    std::make_pair("JMP",    (op_word_len = {"05", "2"})),
                    std::make_pair("JMPN",   (op_word_len = {"06", "2"})),
                    std::make_pair("JMPP",   (op_word_len = {"07", "2"})),
                    std::make_pair("JMPZ",   (op_word_len = {"08", "2"})),
                    std::make_pair("COPY",   (op_word_len = {"09", "3"})),
                    std::make_pair("LOAD",   (op_word_len = {"10", "2"})),
                    std::make_pair("STORE",  (op_word_len = {"11", "2"})),
                    std::make_pair("INPUT",  (op_word_len = {"12", "2"})),
                    std::make_pair("OUTPUT", (op_word_len = {"13", "2"})),
                    std::make_pair("STOP",   (op_word_len = {"14", "1"}))
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
                  
    };

}

#endif
