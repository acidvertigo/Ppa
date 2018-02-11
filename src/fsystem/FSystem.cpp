/*
 * File: FSystem.cpp
 * ---------------
 * This file implements the FSystem.h interface.
 */
#include "fsystem/FSystem.h"

using namespace Ppa::FSystem;
using namespace std::ios;

   void Open (const char* filename, openmode mode = in | out) const {
   }
   void Close () const {};
   bool IsOpen () const {};
   bool Exists () const = {};
