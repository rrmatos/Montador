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

        for (const auto directive:  default_directive_){
            if (directive_.find(directive.first) == directive_.end()){
                directive_.insert(directive);
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
        std::vector<std::string> line_tokens;
        
        int eddress_counter = 0;



        for (auto code_line : vector_code_line_.code_line){

            line_tokens = get_tokens_in_line(code_line);

            if (line_tokens.front().back() == ':'){

                line_tokens.front().pop_back();
                
                label_found(line_tokens.front(), eddress_counter);

                eddress_counter++;

                line_tokens.erase(line_tokens.begin());

                if(!(opcodes_.find(line_tokens.front()) == opcodes_.end())){

                    code_obj.push_back(opcodes_[line_tokens.front()][0]);
 
                    line_tokens.erase(line_tokens.begin()); // erase opcode

                    for (auto token : line_tokens){

                        if(!check_sim_table(token)){
                            
                            add_sim_in_list(token, eddress_counter);
                            eddress_counter++;
                            code_obj.push_back("-");

                        }else{
                            

                            code_obj.push_back(std::to_string(get_simble_idx(token)));
                            eddress_counter++;

                        }
                    }

                }else if(!(directive_.find(line_tokens.front()) == directive_.end())){

                    // std::cout << "directive: " << line_tokens.front() <<std::endl;
                    // // line_tokens.erase(line_tokens.begin());

                    // std::cout << "directive: " << line_tokens.front().front() <<std::endl;


                    switch (line_tokens.front().front()){

                        case('C'):  

                            code_obj.push_back(line_tokens.back());
                            break;

                        case('S'):
                         
                            code_obj.push_back("0");
                            break;

                        default:
                            std::cout <<  colouredString("Invalid String command.", RED, BOLD)<<std::endl;
                            break;
                    }
            
                }else{

                    std::cout << "erro " <<std::endl;
                    std::cout << "opcode "<< line_tokens.front() <<std::endl;


                }


            }else if(!(opcodes_.find(line_tokens.front()) == opcodes_.end())){
                
                code_obj.push_back(opcodes_[line_tokens.front()][0]);
                eddress_counter++;

                line_tokens.erase(line_tokens.begin()); // erase opcode

                for (auto token : line_tokens){
 
                    if(!check_sim_table(token)){
                        code_obj.push_back("-");
                        add_sim_in_list(token, eddress_counter);
                        eddress_counter++;

                    }else{

                        code_obj.push_back(std::to_string(get_simble_idx(token)));
                        eddress_counter++;

                    }
                }

                

            }else if(!(directive_.find(line_tokens.front()) == directive_.end())){

                std::cout << "directive: " << line_tokens.front() <<std::endl;
            
            }else{

                std::cout << "erro " <<std::endl;
                std::cout << "opcode "<< line_tokens.front() <<std::endl;


            }
 
        }
        
    }

    int Montador::get_simble_idx(std::string sim)
    {
        for (auto line_table : SimTable_){

            if (line_table.simble == sim){
                return line_table.value;
            }
        }

        return -1;
    }

    std::vector<std::string> Montador::get_tokens_in_line(std::string code_line){

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

        return tokens;        
    }

    void  Montador::label_found(std::string sim, int eddress_counter){

        bool has_reached = false;

        if (SimTable_.empty()){

            line_table_.list.clear();
            line_table_.simble = sim;
            line_table_.value= eddress_counter;
            line_table_.def = true;

            SimTable_.push_back(line_table_);

        }else{

            for (int k = 0; k < SimTable_.size(); k++){
     
                if (SimTable_[k].simble == sim){
                    
                    SimTable_[k].simble = sim;
                    SimTable_[k].value= eddress_counter;
                    SimTable_[k].def = true;

                    solve_pendency(sim);
                    has_reached = true;
                    break;

                }

            }

            if (!has_reached){

                    line_table_.simble = sim;
                    line_table_.value= eddress_counter;
                    line_table_.list.clear();
                    line_table_.def = true;
                    
                    SimTable_.push_back(line_table_);

                }

        }  

    }

    void  Montador:: solve_pendency(std::string sim){

        for (auto line_table : SimTable_){

            if (line_table.simble == sim){

                for (auto idx : line_table.list){

                    code_obj[idx] = std::to_string(line_table.value);
                }

            }
        }

    }

    void  Montador::add_sim_in_list(std::string sim, int eddress_counter){

        bool has_reached = false;

        if (SimTable_.empty()){

            line_table_.list.push_back(eddress_counter);
            line_table_.simble = sim;
            line_table_.def = false;

            SimTable_.push_back(line_table_);

        }else{

            for (int k = 0; k < SimTable_.size(); k++){
            
                if (SimTable_[k].simble == sim){

                    SimTable_[k].list.push_back(eddress_counter);

                    has_reached = true;
                    break;
                }
            }

            if (!has_reached){

                    line_table_.simble = sim;
                    line_table_.list.push_back(eddress_counter);
                    line_table_.def = false;
                    
                    SimTable_.push_back(line_table_);

                }

        }

        line_table_.list.clear();

    }

    bool Montador::check_sim_table(std::string sim){

        for (auto table_line : SimTable_){
            
            if (table_line.simble == sim and table_line.def == true){

                return true;
            }
        }

        return false;

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

        for (auto y : code_obj){

            std::cout << y << " ";

        }
        std::cout << std::endl;
    }

}   