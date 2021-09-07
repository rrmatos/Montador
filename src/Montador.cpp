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

    void Montador::recive_code(Preprocess::conde_struct code_line)
    {
        vector_code_line_ = code_line;
        vector_code_line = code_line;
    }


    void Montador::montar()
    {

        std::string buffer, code_obj , instrution, diretive, label;
        
        int idx_line = 0;
        int eddress_counter = 0;

        bool op_code;

        for (auto code_line : vector_code_line_.code_line){

            get_tokens_in_line(code_line);
            break;
            op_code = false;

            for (int i = 0; i <= code_line.size(); i++){
                
                if ((code_line[i] != ' ') and (code_line[i] != ',')and (i != code_line.size())){
                    
                    buffer.push_back(code_line[i]);
                }else{


                    if (!buffer.empty()){

                        if (buffer.back() == ':'){

                            buffer.pop_back();

                            if (SimTable_.empty()){

                                line_table_.list.clear();
                                line_table_.simble = buffer;
                                line_table_.list.push_back(eddress_counter);
                                line_table_.def = true;
                                SimTable_.push_back(line_table_);
                                

                            }else{

                                for (int k = 0; k < SimTable_.size(); k++){
                                    // std::cout << SimTable_.size() <<std::endl;
                                
                                    if (SimTable_[k].simble == buffer){
                                        
                                        SimTable_[k].simble = buffer;
                                        SimTable_[k].value= eddress_counter;
                                        SimTable_[k].def = true;
                                        break;

                                    }
                                    if ((k+1) == SimTable_.size()){

                                        line_table_.simble = buffer;
                                        line_table_.value= eddress_counter;
                                        line_table_.list.clear();
                                        line_table_.def = true;
                                        
                                        SimTable_.push_back(line_table_);

                                    }

                                }

                            }     
                            

                            std::cout << "rotulo --> "<< buffer <<std::endl;
                            buffer.clear();

                        }else{
                            if (opcodes_.find(buffer) == opcodes_.end()){

                                if (op_code){

                                    if (SimTable_.empty()){

                                            line_table_.list.clear();
                                            line_table_.simble = buffer;
                                            line_table_.list.push_back(eddress_counter);
                                            line_table_.def = false;
                                            SimTable_.push_back(line_table_);

                                    }else{

                                        for (int k = 0; k < SimTable_.size(); k++){
                                
                                            if (SimTable_[k].simble == buffer){
                                                
                                                if (SimTable_[k].def != true){

                                                    SimTable_[k].list.push_back(eddress_counter);

                                                }
                                                //  colocar o endereco
                                                break;

                                            }

                                            if ((k+1) == SimTable_.size()){
                                                
                                                line_table_.list.clear();
                                                line_table_.simble = buffer;
                                                line_table_.list.push_back(eddress_counter);
                                                line_table_.def = false;
                                                SimTable_.push_back(line_table_);

                                                break;

                                            }
                                        }
                                    }
                                    eddress_counter = eddress_counter + 1;
                                    buffer.clear();


                                }else{

                                    (std::cout << colouredString("Error in line ", RED, BOLD)
                                    <<colouredString(std::to_string(vector_code_line_.line[idx_line]), RED, BOLD)
                                    <<colouredString(": ", RED, BOLD)
                                    << colouredString(buffer, RED, BOLD) 
                                    <<  colouredString(" is not valid struction", RED, BOLD) <<std::endl);
                                    buffer.clear();

                                }

                                

                            }else{
                                std::cout << "instrucao -->"<< buffer << " op: "<< opcodes_[buffer][0] << " len: "<< opcodes_[buffer][1]<< std::endl;
                                
                                eddress_counter = eddress_counter + 1; //stoi(opcodes_[buffer][1]);

                                op_code = true;

                                code_obj.push_back(opcodes_[buffer][0][0]);
                                code_obj.push_back(opcodes_[buffer][0][1]);
                                code_obj.push_back(' ');
                                buffer.clear();

                                
                            }
                        }

                    }
                    
                      
                }  
            }
            
            idx_line++;
 
        }
        
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

    void Montador::get_tokens_in_line(std::string code_line){

        std::vector<std::string> tokens;
        std::string space = " ", comma = ",", token;
        size_t pos = 0;
        size_t pos1 = 0;

        while (((pos = code_line.find(space)) != std::string::npos) or (pos = code_line.find(comma)) != std::string::npos) {

            token = code_line.substr(0, pos);
            
            if ((token.compare(space)!= std::string::npos)  and (token.compare(comma)!= std::string::npos)){

                if ((pos1 = token.find(comma)) != std::string::npos){
                    token.erase(pos1);
                }

                if ((pos1 = token.find(space)) != std::string::npos){
                    token.erase(pos1);
                }
                if (!token.empty()){
                tokens.push_back(token);

                }
            }
  
            code_line.erase(0, pos + space.length());
        }

        tokens.push_back(code_line);
        
        std::cout << "--------" << std::endl;

        for (auto t: tokens){
            std::cout << t << std::endl;  
        }
        
    }

    void Montador::show_table()
    {
        
        for (auto line_table : SimTable_){

            std::cout << "sim: " << line_table.simble <<" vlr: " <<line_table.value << " def: "<<line_table.def << " list: ";
            for (auto x : line_table.list){
                std::cout << x << " ";
            }
            std::cout << std::endl;


        }

    }

}   