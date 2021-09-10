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
    }

    void Montador::montar()
    {
        std::vector<std::string> line_tokens;
        
        int eddress_counter = 0;

        for (int idx = 0; idx < vector_code_line_.code_line.size(); idx++){

            const_ = "0";
            auto code_line = vector_code_line_.code_line[idx];
            int line_number = vector_code_line_.line[idx];
            std::string imediate;

            line_tokens = get_tokens_in_line(code_line, line_number);

            // for (auto t : line_tokens){
            //     std::cout<<t <<std::endl;
            // }

            detect_error(line_tokens, line_number);

            // break;
          
                
            if (line_tokens.front().back() == ':'){

               
                line_tokens.front().pop_back();
                
                label_found(line_tokens.front(), eddress_counter);

                // eddress_counter++;

                line_tokens.erase(line_tokens.begin());

                if (!line_tokens.empty()){

                    eddress_counter++;

                    if(!(opcodes_.find(line_tokens.front()) == opcodes_.end())){


                        imediate = imediate_;

                        code_obj.push_back(opcodes_[line_tokens.front()][0]);
    
                        line_tokens.erase(line_tokens.begin()); // erase opcode

                        for (auto token : line_tokens){

                            if(!check_sim_table(token)){
                                
                                if (token == line_tokens.back()){
                                    code_obj.push_back(imediate);
                                }else{
                                    code_obj.push_back("0"); 
                                }
                                add_sim_in_list(token, eddress_counter);
                                eddress_counter++;

                            }else{
                                
                                code_obj.push_back(std::to_string(get_simble_idx(token)));
                                eddress_counter++;
                            }
                        }

                    }else if(!(directive_.find(line_tokens.front()) == directive_.end())){

                        switch (line_tokens.front().front()){

                            case('C'):  

                                code_obj.push_back(const_);
                                break;

                            case('S'):

                                    for (int i = 0; i < std::stoi(const_) - 1; i++){
                                        code_obj.push_back("0");
                                        eddress_counter++;

                                    }

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
                }

            }else if(!(opcodes_.find(line_tokens.front()) == opcodes_.end())){

                imediate = imediate_;
                
                code_obj.push_back(opcodes_[line_tokens.front()][0]);
                eddress_counter++;

                line_tokens.erase(line_tokens.begin()); // erase opcode


                for (auto token : line_tokens){
               
 
                    if(!check_sim_table(token)){

                        if (token == line_tokens.back()){
                            code_obj.push_back(imediate);
                        }else{
                            code_obj.push_back("0"); 
                        }
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
          
        semantic_analyzer();
    }

    void Montador::semantic_analyzer(){

        for (auto table_line : SimTable_){
            
            if (table_line.def == false){
                
                (std::cout <<  colouredString("Semantic error detected: ", RED, BOLD)
                << colouredString(table_line.simble, RED, BOLD)
                <<  colouredString(" has not been defined", RED, BOLD) <<std::endl);
                
            }
        }

    }


    bool Montador::detect_error(std::vector<std::string> tokens, int line){

    
        if (!tokens.empty()){
            scanner(tokens, line);

        }
        if(tokens.size()>1){
            parser(tokens, line);

        }
        

        return true;

    }

    bool Montador::scanner(std::vector<std::string> tokens, int line){

        
        for (auto token : tokens){

            std::string str( 1, token.front());


            if (find_element_vector_str(invalchar_front_, str)){

                (std::cout <<  colouredString("Lexical error detected in : ", RED, BOLD)
                    << colouredString(token, RED, BOLD)
                    <<  colouredString(" Line ", RED, BOLD) 
                    <<   colouredString(std::to_string(line), RED, BOLD) <<std::endl);

                return false;
                
            }

            if (find_element_vector_str(invalchar_, token)){

                (std::cout <<  colouredString("Lexical error detected in : ", RED, BOLD)
                    << colouredString(token, RED, BOLD)
                    <<  colouredString(" Line ", RED, BOLD) 
                    <<   colouredString(std::to_string(line), RED, BOLD) <<std::endl);

                return false;

            }

        }
        

        return true;

    }

    bool Montador::parser(std::vector<std::string> tokens, int line){

        if (tokens.front().back() == ':'){
  
            tokens.erase(tokens.begin());

        }

        if((opcodes_.find(tokens.front()) == opcodes_.end())){

            if((directive_.find(tokens.front()) == directive_.end())){
             (std::cout <<  colouredString("Sintaxe error detected in ", RED, BOLD)
                <<  colouredString(" Line ", RED, BOLD) 
                <<   colouredString(std::to_string(line), RED, BOLD)
                << colouredString(" ", RED, BOLD)
                << colouredString(tokens.front(), RED, BOLD)
                <<  colouredString(" is node a valid diretive ", RED, BOLD)  <<std::endl);

                return false;

            }else{

                switch (tokens.front().front()){

                    case('C'):  
                        if (std::stoi(directive_[tokens.front()][1]) != tokens.size()){

                            (std::cout <<  colouredString("Sintaxe error detected in ", RED, BOLD)
                            <<  colouredString(" Line ", RED, BOLD) 
                            <<   colouredString(std::to_string(line), RED, BOLD)
                            << colouredString(" ", RED, BOLD)
                            << colouredString(tokens.front(), RED, BOLD)
                            <<  colouredString(" 1 args", RED, BOLD)  <<std::endl);

                            return false;
            
                        }

                    case('S'):
    
                        if (std::stoi(directive_[tokens.front()][1]) < tokens.size()){

                            (std::cout <<  colouredString("Sintaxe error detected in ", RED, BOLD)
                            <<  colouredString(" Line ", RED, BOLD) 
                            <<   colouredString(std::to_string(line), RED, BOLD)
                            << colouredString(" ", RED, BOLD)
                            << colouredString(tokens.front(), RED, BOLD)
                            <<  colouredString(" 0 ou 1 args", RED, BOLD)  <<std::endl);

                            return false;
                    
                        }
                }

                return true;
            }

            (std::cout <<  colouredString("Sintaxe error detected in ", RED, BOLD)
                <<  colouredString(" Line ", RED, BOLD) 
                <<   colouredString(std::to_string(line), RED, BOLD)
                << colouredString(" ", RED, BOLD)
                << colouredString(tokens.front(), RED, BOLD)
                <<  colouredString(" is node a valid struction ", RED, BOLD)  <<std::endl);

            return false;

        }else{

            if (!(std::stoi(opcodes_[tokens.front()][1]) <= tokens.size())){

                (std::cout <<  colouredString("Sintaxe error detected in ", RED, BOLD)
                <<  colouredString(" Line ", RED, BOLD) 
                <<   colouredString(std::to_string(line), RED, BOLD)
                << colouredString(" ", RED, BOLD)
                << colouredString(tokens.front(), RED, BOLD)
                <<  colouredString(" 2 args", RED, BOLD)  <<std::endl);

                return false;
        
            }
        }


        return true;


    }

    bool Montador::find_element_vector_str(std::vector<std::string> vector_str, std::string str){

        for (auto elem : vector_str){

            if (str.find(elem) != std::string::npos){

                std::cout <<  colouredString(elem, RED, BOLD) << colouredString(" is a invalid character ", RED, BOLD)<<std::endl;
                return true;
            }
        }

        return false;

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

    std::vector<std::string> Montador::get_tokens_in_line(std::string code_line, int line){

        std::vector<std::string> tokens;
        std::string mais = "+", space = " ", comma = ",", token;

        size_t pos;
        

        if((pos = code_line.find(space)) != std::string::npos){

            if ((code_line.at(pos-1) == ' ') or (code_line.at(pos+1) == ' ')){

                (std::cout <<  colouredString("Sitaxe error detected in : ", RED, BOLD)
                << colouredString(code_line, RED, BOLD)
                << colouredString(" Line ", RED, BOLD) 
                << colouredString(std::to_string(line), RED, BOLD) <<std::endl
                << colouredString("More then one space", RED, BOLD) <<std::endl);
           
            
            }else{
                
                token = code_line.substr(0, pos);
                code_line.erase(0, pos + space.length());
                tokens.push_back(token);
                
            }

        }


        if ((pos = code_line.find(comma)) != std::string::npos){

            if ((code_line.at(pos-1) == ' ') or (code_line.at(pos+1) == ' ')){
            
                (std::cout <<  colouredString("Sitaxe error detected in : ", RED, BOLD)
                << colouredString(code_line, RED, BOLD)
                << colouredString(" Line ", RED, BOLD) 
                << colouredString(std::to_string(line), RED, BOLD) <<std::endl
                << colouredString("More then one space", RED, BOLD) <<std::endl);

            }else{

                token = code_line.substr(0, pos);
                code_line.erase(0, pos + comma.length());
                tokens.push_back(token);
            }

        }

        

        if((pos = code_line.find(space)) != std::string::npos){

            if ((code_line.at(pos-1) == ' ') or (code_line.at(pos+1) == ' ')){

                (std::cout <<  colouredString("Sitaxe error detected in : ", RED, BOLD)
                << colouredString(code_line, RED, BOLD)
                << colouredString(" Line ", RED, BOLD) 
                << colouredString(std::to_string(line), RED, BOLD) <<std::endl
                << colouredString("More then one space", RED, BOLD) <<std::endl);
           
            
            }else{

                token = code_line.substr(0, pos);
                code_line.erase(0, pos + space.length());
                tokens.push_back(token);

                if (tokens.back() == "SPACE" or tokens.back() == "CONST"){

                    token = code_line.substr(0, pos);
                    code_line.erase(0, pos + space.length());

                    const_ = token;

                }else{
                    const_ = "0";
                }

            }

        }

        if ((pos = code_line.find(mais)) != std::string::npos){

            if ((code_line.at(pos-1) == ' ') or (code_line.at(pos+1) == ' ')){
            
                (std::cout <<  colouredString("Sitaxe error detected in : ", RED, BOLD)
                << colouredString(code_line, RED, BOLD)
                << colouredString(" Line ", RED, BOLD) 
                << colouredString(std::to_string(line), RED, BOLD) <<std::endl
                << colouredString("More then one space", RED, BOLD) <<std::endl);

            }else{

                token = code_line.substr(0, pos);
                code_line.erase(0, pos + mais.length());
                tokens.push_back(token);
                // imadiate_ = std::stoi(token);
            }
            imediate_ = code_line;

            code_line.clear();


        }else{
            imediate_ = "0";

        }

        if (!code_line.empty()){
            tokens.push_back(code_line);
        }

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
                    code_obj[idx] = std::to_string(std::stoi(code_obj[idx]) + line_table.value);
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

    void Montador::set_file_name(std::string file_name){
        file_name.pop_back();
        file_name.pop_back();
        file_name.pop_back();
        file_name_ = file_name;
    }

    void Montador::generete_obj_file(){

        std::ofstream MyFile( file_name_ + "obj");

        for (auto y : code_obj){
            MyFile << y << " ";
        }
    }

    void Montador::show_table(){
        
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