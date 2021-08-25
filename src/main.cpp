
#include <trabalho1/Montador.hpp>


int main(int argc, char* argv[]){ 

    trabalho1::Montador montador;
    
    // montador.show_arg_name(argv[1]);

    montador.read_code_file(argv[1]);

    montador.section_text_first();
    
  	return 0;
} 