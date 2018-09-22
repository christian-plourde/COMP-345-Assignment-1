//fixing the issue with the toString method
#include <string>
#include <sstream>

#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

namespace libString
{
  template <typename T> std::string to_string(const T& n)
  {
    std::ostringstream stream;
    stream << n;
    return stream.str();
  }
}

#endif