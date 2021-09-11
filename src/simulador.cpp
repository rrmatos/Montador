#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <fstream>
#include <trabalho1/utils.h>


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


void show_data(std::vector<int> vector_code){

  (std::cout <<"data->" <<"DOIS: " <<vector_code.at(28)<<" OLD_DATA: "<<vector_code.at(29)
    <<" NEW_DATA: " <<vector_code.at(30)<<" TMP_DATA: "<<vector_code.at(31)<<std::endl);

}

void log(std::vector<int> vector_code, int accumulator, int eddress_counter){
  int x;

  std::cout <<"linha: " <<vector_code.at(eddress_counter) << " " <<vector_code.at(eddress_counter + 1)<< std::endl;
  std::cout <<"acumulador: " << accumulator<< std::endl;
  std::cout <<"contador de programa: " << eddress_counter<< std::endl;
  show_data(vector_code);
  std::cout << "<----------------------------------------------------------->"<< std::endl;
  std::cin >> x;

}


int main(int argc, char* argv[]){ 

  std::vector<int> vector_code;
  int eddress_counter = 0;
  int accumulator = 0;
  int input;
  

  vector_code = load_code_obj(argv[1]);

  while(vector_code.at(eddress_counter) != 14){

    switch (vector_code.at(eddress_counter)){

        case(1):

          accumulator = accumulator + vector_code.at(vector_code.at(eddress_counter + 1));

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " ADD"<< std::endl;
          log(vector_code, accumulator, eddress_counter);
          eddress_counter = eddress_counter + 2;
          break;

        case(2): 

          accumulator = accumulator - vector_code.at(vector_code.at(eddress_counter + 1));

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " SUB"<< std::endl;
          log(vector_code, accumulator, eddress_counter);
  
          eddress_counter = eddress_counter + 2;
          break;
        
        case(3): 

          accumulator = accumulator*vector_code.at(vector_code.at(eddress_counter + 1));

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " MUL"<< std::endl;
          log(vector_code, accumulator, eddress_counter);
        
          eddress_counter = eddress_counter + 2;
          break;

        case(4):  

          accumulator = accumulator/vector_code.at(vector_code.at(eddress_counter + 1));

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " DIV"<< std::endl;
          log(vector_code, accumulator, eddress_counter);

          eddress_counter = eddress_counter + 2;
          break;
            

        case(5):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " JMP"<< std::endl;
          eddress_counter = vector_code.at(vector_code.at(eddress_counter + 1));
          break;

        case(6):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << "JMPN"<< std::endl;
          if (accumulator < 0){

            eddress_counter = vector_code.at(vector_code.at(eddress_counter + 1));

          }else{
            eddress_counter = eddress_counter + 2;
          }
          log(vector_code, accumulator, eddress_counter);
          break;
        
        case(7):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " JMPP"<< std::endl;

          
          if (accumulator > 0){

            eddress_counter = vector_code.at(vector_code.at(eddress_counter + 1));

          }else{
            eddress_counter = eddress_counter + 2;
          }

          log(vector_code, accumulator, eddress_counter);

          break;

        case(8):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " JMPZ"<< std::endl;
          if (accumulator == 0){

            eddress_counter = vector_code.at(vector_code.at(eddress_counter + 1));

          }else{
            eddress_counter = eddress_counter + 2;
          }

          log(vector_code, accumulator, eddress_counter);

          break;

        case(9):  
          
          vector_code.at(vector_code.at(eddress_counter + 2)) = vector_code.at(vector_code.at(eddress_counter + 1));

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " COPY"<< std::endl;
          log(vector_code, accumulator, eddress_counter);

          eddress_counter = eddress_counter + 3;
          break;

        case(10):  

          accumulator = vector_code.at(vector_code.at(eddress_counter + 1));

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " LOAD"<< std::endl;
          log(vector_code, accumulator, eddress_counter);

          eddress_counter = eddress_counter + 2;
          break;

        case(11):  

          vector_code.at(vector_code.at(eddress_counter + 1)) = accumulator;

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " STORE"<< std::endl;
          log(vector_code, accumulator, eddress_counter);
          
          eddress_counter = eddress_counter + 2;
          break;

        case(12):  
        
          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " INPUT"<< std::endl;
          
          log(vector_code, accumulator, eddress_counter);

          std::cin >> input;

          vector_code.at(vector_code.at(eddress_counter + 1)) = input;
  
          eddress_counter = eddress_counter + 2;

          break;

        case(13):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " OUTPUT"<< std::endl;

          std::cout << colouredString("OUTPUT: ", BLUE, BOLD)<<colouredString(std::to_string(vector_code.at(vector_code.at(eddress_counter + 1))), BLUE, BOLD)<<std::endl;

          log(vector_code, accumulator, eddress_counter);

          eddress_counter = eddress_counter + 2;

          break;

        case(14):  

          std::cout << "opcode: "<<vector_code.at(eddress_counter) << " STOP"<< std::endl;
          // eddress_counter = eddress_counter + 1;
          break;

        default:
          std::cout << colouredString("Opcode error", RED, BOLD)<<std::endl;
          break;
    }

  }

  std::cout << "code len: " <<vector_code.size() << std::endl;
  
  return 0;

} 