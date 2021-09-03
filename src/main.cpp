#include <trabalho1/Preprocess.hpp>
#include <trabalho1/Montador.hpp>

int main(int argc, char* argv[]){ 

    trabalho1::Preprocess preprocess;
    trabalho1::Montador m;

    
    // preprocess.show_arg_name(argv[1]);

    preprocess.read_code_file(argv[1]);

    preprocess.section_text_first();

    // m.show_table();
    // std::cout << m.get_simble_idx("RET") << std::endl;




    
  	return 0;
} 