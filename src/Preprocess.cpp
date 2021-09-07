#include <trabalho1/Preprocess.hpp>
#include <trabalho1/utils.h>

namespace trabalho1{

    Preprocess::Preprocess()
    {
        initialize();
    }

    void Preprocess::initialize()
    {
        std::cout << colouredString("init Preprocess Class", GREEN, BOLD) << std::endl;
    }

    void Preprocess::show_arg_name(std::string arg)
    {
        file_name_ = arg;
        std::cout <<  file_name_ << std::endl;

    }

    void Preprocess::read_code_file(std::string arg)
    {   
        file_name_ = arg;
        std::string code_line; 
        int line_number = 1;

        std::ifstream ReadFile(arg);

        while(getline(ReadFile, code_line)){

            if (!code_line.empty() and code_line[0] != ';'){

                code_line = to_capital_letter(code_line);
                if (!code_line.empty()){

                    while(code_line.back() == ' '){
                        // std::cout << code_line << std::endl;

                        code_line.pop_back();
                    }

                    vector_code_line_.code_line.push_back(code_line);
                    vector_code_line_.line.push_back(line_number );
                }
            }
            line_number++;
        }
        
        //  std::cout << opcodes_["ADD"][1] << std::endl;
       
        ReadFile.close();
    }

    std::string Preprocess::to_capital_letter(std::string code_line)
    {   
        std::string code_line_uppper;
        int j = 0;
        
        while (code_line[j] == ' '){
            j++;
        }

        for (int i = j; i < code_line.size(); i++) {
            
            if (code_line[i] == ';'){
                break;
            }else{
                code_line_uppper.push_back(toupper(code_line[i]));
            }

        }    
        return code_line_uppper;
    }


    void Preprocess::section_text_first()
    {
        int i = 0;
        int section_text_idx = 0;
        
        for (auto code_line: vector_code_line_.code_line){

            if (code_line == "SECTION TEXT"){
                i++;
                break;
            }else{
                i++;
            }
        }

        section_text_idx = i;

        for ( i; i < vector_code_line_.code_line.size(); i++){

            vector_code_line_stf_.code_line.push_back(vector_code_line_.code_line[i]);
            vector_code_line_stf_.line.push_back(vector_code_line_.line[i]);
        }

        
        for ( int j = 0 ; j < section_text_idx ; j++){

            if (vector_code_line_.code_line[j] != "SECTION DATA" and vector_code_line_.code_line[j] != "SECTION TEXT"){

                vector_code_line_stf_.code_line.push_back(vector_code_line_.code_line[j]);
                vector_code_line_stf_.line.push_back(vector_code_line_.line[j]);


            }     
        }

        // for (int i = 0; i < vector_code_line_stf_.code_line.size(); i++){
            
        //     std::cout << vector_code_line_stf_.code_line[i] << " :"<< vector_code_line_stf_.line[i]<<std::endl;
            
        // }

    }

    Preprocess::conde_struct Preprocess::get_code()
    {
        return vector_code_line_stf_;
    }

    std::string Preprocess::get_file_name(){
        return file_name_;
    }

}   