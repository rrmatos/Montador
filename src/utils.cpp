#include <trabalho1/utils.h>

std::string colouredString(std::string str, std::string colour, std::string option)
{
  return option + colour + str + RESET;
}
