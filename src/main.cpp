#include <trabalho1/Preprocess.hpp>
#include <trabalho1/Montador.hpp>

int main(int argc, char* argv[]){ 

  trabalho1::Preprocess preprocess;  
  trabalho1::Montador montador;

  // preprocess.show_arg_name(argv[1]);

  preprocess.read_code_file(argv[1]);

  preprocess.section_text_first();

  montador.set_file_name(preprocess.get_file_name());

  montador.recive_code(preprocess.get_code());
          
  montador.montar();

  std::cout << "--------------------------------------------------------------------"<<std::endl;
  

  montador.show_table();
  montador.generete_obj_file();


  return 0;
} 