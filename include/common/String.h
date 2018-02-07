/*
 * File: libString.h
 * -------------
 * This interface exports the libStr utility functions to work with strings
 */
#ifndef _LIBSTR_H_
#define _LIBSTR_H_

#include <sstream>

namespace Ppa {
namespace Common {

/* Usage: NumberToString(Number)
 * -------------
 * Template to comvert integer to string
 */
template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

/* Usage: StringToNumber<Type> ( string );
 * -------------
 * Template to comvert integer to string
 */
template <typename T> 
  T StringToNumber(const std::string & text)
  {
    std::stringstream ss(text);
    T number;
	return (ss >> number)?number:0;
  }

} // namespace Common end
} // namespace Ppa end

#endif /* _LIBSTR_H_ */
