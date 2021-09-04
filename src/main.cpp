#include <trabalho1/Preprocess.hpp>
#include <trabalho1/Montador.hpp>

int main(int argc, char* argv[]){ 

    trabalho1::Preprocess preprocess;
    trabalho1::Montador montador;

    
    // preprocess.show_arg_name(argv[1]);

    preprocess.read_code_file(argv[1]);

    preprocess.section_text_first();

    montador.recive_code(preprocess.get_code());



    // for (auto code_line: montador.vector_code_line){
            
    //   std::cout << code_line << std::endl;
            
    // }

    montador.get_instru_rot_dire();

    // m.show_table();
    // std::cout << montador.get_simble_idx("RET") << std::endl;




    
  	return 0;
} 