#include <trabalho1/Preprocess.hpp>
#include <trabalho1/Montador.hpp>

int main(int argc, char* argv[]){ 

    trabalho1::Preprocess preprocess;
    trabalho1::Montador montador;

    
    // preprocess.show_arg_name(argv[1]);

    preprocess.read_code_file(argv[1]);

    preprocess.section_text_first();

    montador.recive_code(preprocess.get_code());



    // for (int i = 0; i < montador.vector_code_line.code_line.size(); i++){
            
    //     std::cout << montador.vector_code_line.code_line[i] << " :"<< montador.vector_code_line.line[i]<<std::endl;
            
    // }

    //  std::cout << "--------------------------------------------------------------------"<<std::endl;
            
    montador.montar();

     std::cout << "--------------------------------------------------------------------"<<std::endl;
    

    montador.show_table();
    // std::cout << montador.get_simble_idx("RET") << std::endl;




    
  	return 0;
} 