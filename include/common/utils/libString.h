/*
 * File: libString.h
 * -------------
 * This interface exports the libStr utility functions to work with strings
 */
#ifndef _LIBSTR_H_
#define _LIBSTR_H_

#include <sstream>

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

#endif /* _LIBSTR_H_ */