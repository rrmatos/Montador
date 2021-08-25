#include <trabalho1/Preprocess.hpp>

int main(int argc, char* argv[]){ 

    trabalho1::Preprocess preprocess;
    
    // montador.show_arg_name(argv[1]);

    preprocess.read_code_file(argv[1]);

    preprocess.section_text_first();
    
  	return 0;
} 