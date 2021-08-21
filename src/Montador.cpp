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

    void Montador::show_arg_name(std::string arg)
    {
        file_name_ = arg;
        std::cout <<  file_name_ << std::endl;

    }

    void Montador::read_code_file(std::string arg)
    {   
        std::string code_line; 

        std::ifstream ReadFile("bin.asm");

        while(getline(ReadFile, code_line)) {

            code_line = to_capital_letter(code_line);

            vector_code_lone_.push_back(code_line);
        }
        
        //  std::cout << opcodes_["ADD"][1] << std::endl;
       
        ReadFile.close();
    }

    std::string Montador::to_capital_letter(std::string code_line)
    {
        boost::to_upper(code_line);
        return code_line;
    }

    

}   