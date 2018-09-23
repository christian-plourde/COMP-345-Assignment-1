#include <string>
#include "Characters.h"

#ifndef CHARACTER_METHODS_H
#define CHARACTER_METHODS_H

namespace CharacterMethods
{
  std::string characterToString(enum Characters character)
  {
    std::string output = "";
    switch(character)
    {
      case CaptainFish: output = "Captain Fish";
      break;
      case Sheriff: output = "Sheriff";
      break;
      case Mantis: output = "Mantis";
      break;
      case Rob: output = "Rob";
      break;
      case Drakonis: output = "Drakonis";
      break;
      case Kong: output = "Kong";
      break;
      default: output = "";
    }

    return output;
  }
}

#endif