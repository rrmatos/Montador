#include <trabalho1/Montador.hpp>
#include <trabalho1/utils.h>

namespace trabalho1{

    Montador::Montador()
    {
        initialize();
    }

    void Montador::initialize()
    {
        std::cout << colouredString("init Montador Class", GREEN, BOLD) << std::endl;

    }

    int Montador::get_simble_idx(std::string simble)
    {
        int idx = 0;
        for (auto line_table : SimTable_){


            if (line_table.simble == simble){
                return idx;
            }

            idx++;

        }

        return -1;

    }



    void Montador::show_table()
    {
        sim_table_test_.simble = "N";
        sim_table_test_.value = 3;
        sim_table_test_.def = false;
        sim_table_test_.list = {1,2,3};
 

        SimTable_.push_back(sim_table_test_);

        sim_table_test_.simble = "FAT";
        sim_table_test_.value = 0;
        sim_table_test_.def = true;
        sim_table_test_.list = {1};
 

        SimTable_.push_back(sim_table_test_);
        
        for (auto line_table : SimTable_){

            std::cout << line_table.simble << line_table.value << line_table.def << line_table.list[0] << std::endl;
        }

    }

}   