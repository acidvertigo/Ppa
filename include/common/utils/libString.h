/*
 * File: libString.h
 * -------------
 * This interface exports the libStr utility functions to work with strings
 */
#ifndef _LIBSTR_H_
#define _LIBSTR_H_

#include <sstream>

template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

#endif /* _LIBSTR_H_ */