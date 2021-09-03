#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>
#include <vector>
#include <array>

namespace trabalho1{


    class Montador{
        public:
            Montador();
            ~Montador() {};

            void show_table();
            void populate_simble_table();
            int get_simble_idx(std::string simble);

        private:
        void initialize();
        int position_counter = 0;
        int line_counter = 1;

        struct sim_table_uni_
            {
                std::string simble;
                int value;
                bool def ;
                std::vector<int> list; 
            };
        sim_table_uni_ sim_table_test_;
        std::vector<sim_table_uni_> SimTable_;
                  
    };

}

#endif
