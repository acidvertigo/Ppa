/*
 * File: FSystem.cpp
 * ---------------
 * This file implements the FSystem.h interface.
 */
#include "os/FSystem.h"

using namespace Ppa::Os;
using namespace std;

   FSystem::FSystem(string filenamec) {}
   ~ FSystem::FSystem() = default;

   void FSystem::Open(const char* filename, ios::openmode mode) const {
   }
   void FSystem::Close () const {}
   bool FSystem::IsOpen () const {}
   bool FSystem::Exists () const {}
   void WriteContent ( const char* filename, std::vector<BYTE> data) const {}
   vector<BYTE> ReadContent (const char* filename) const {}