/*
 * File: FSystem.cpp
 * ---------------
 * This file implements the FSystem.h interface.
 */
#include "fsystem/FSystem.h"

using namespace Ppa::FSystem;
using namespace std;

   void FSystem::Open(const char* filename, ios::openmode mode = ios::in | ios::out) const {
   }
   void FSystem::Close () const {};
   bool FSystem::IsOpen () const {};
   bool FSystem::Exists () const = {};
