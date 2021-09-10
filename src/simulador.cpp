#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <fstream>



std::vector<int> load_code_obj(std::string file_name){

  std::vector<int> vector_code;
  std::string code_line, word;

  std::ifstream ReadFile(file_name);

  getline(ReadFile, code_line);

  for (auto code : code_line){

    if (code != ' '){

      word.push_back(code);

    }else{

      vector_code.push_back( std::stoi(word));
      word.clear();

    }

  }
  return  vector_code;

}


int main(int argc, char* argv[]){ 

  std::vector<int> vector_code;
  int eddress_counter = 0;
  int accumulator = 0;
  // std::string opcode = "00";

  vector_code = load_code_obj(argv[1]);


  
  while(vector_code.at(eddress_counter) != 14){


    switch (vector_code.at(eddress_counter)){

      //  std::cout << vector_code.at(eddress_counter)<< std::endl;


        case(1):

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " ADD"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(2):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " SUB"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;
        
        case(3):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " MULT"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(4):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " DIV"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;
            

        case(5):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " JMP"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(6):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << "JMPN"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;
        
        case(7):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " JMPP"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(8):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " JMPZ"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(9):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " COPY"<< std::endl;
          eddress_counter = eddress_counter + 3;
          break;

        case(10):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " LOAD"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(11):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " STORE"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(12):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " INPUT"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(13):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " OUTPUT"<< std::endl;
          eddress_counter = eddress_counter + 2;
          break;

        case(14):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " STOP"<< std::endl;
          eddress_counter = eddress_counter + 1;
          break;

        default:
            std::cout << "default"<<std::endl;
          break;
    }


  }

  std::cout << "code len: " <<vector_code.size() << std::endl;
  
  return 0;

} 