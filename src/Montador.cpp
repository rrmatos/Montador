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

        for (const auto opcode:  default_opcodes_){
            if (opcodes_.find(opcode.first) == opcodes_.end()){
                opcodes_.insert(opcode);
            }
        }
    }

    void Montador::recive_code(std::vector<std::string> code_line)
    {
        vector_code_line_ = code_line;
        vector_code_line = code_line;
    }


    std::string Montador::get_instru_rot_dire()
    {

        std::string instru_rot_dire;

        for (auto code_line : vector_code_line_){


            for (int i = 0; i <= code_line.size(); i++){
                
                if ((code_line[i] != ' ') and (i != code_line.size())){
                    
                    instru_rot_dire.push_back(code_line[i]);

                }else{

                    if (instru_rot_dire.back() == ':'){

                        instru_rot_dire.pop_back();

                        std::cout << "rotulo --> "<< instru_rot_dire <<std::endl;

                    }else{
                        if (opcodes_.find(instru_rot_dire) == opcodes_.end()){
                            std::cout << colouredString("Error: The ", RED, BOLD) << colouredString(instru_rot_dire, RED, BOLD)<<  colouredString(" is not valid struction", RED, BOLD) <<std::endl;
                        }else{
                        std::cout << "instrucao -->"<< instru_rot_dire << " op: "<< opcodes_[instru_rot_dire][0] << " len: "<< opcodes_[instru_rot_dire][1]<< std::endl;
                        }
                    }
                    // std::cout <<instru_rot_dire << std::endl;
                    instru_rot_dire.clear();

                    break;
                    
                }

            }
            // break;
    
            
        }
        return "test";
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