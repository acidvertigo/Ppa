/*
 * File: FSystem.cpp
 * ---------------
 * This file implements the FSystem.h interface.
 */
#include "os/FSystem.h"

using namespace Ppa::Os;
using namespace std;

   FSystem::FSystem(string filenamec) {
       filename = filenamec;
   }

   ~ FSystem::FSystem() = default;

//————————————————————————————————————
   bool FSystem::FileIsOpen () const {
       std::ifstream ifs (filename);
       return ifs.is_open();
   }

//————————————————————————————————————
   bool FSystem::FileExists () const {

   }

//—————————————————————————————————————————————————————————————————————————-
   void WriteContent ( const std::vector<char>& data) const {

   }

//———————————————————————————————————————————————————————-
   vector<BYTE> ReadContent (const char* filename) const {

   }

//————————————————————————————————————————————————————————————————————————-
   void FSystem::OpenFile(const char* filename, ios::openmode mode) const {

   }

//———————————————————————————————————
   void FSystem::CloseFile () const {

   }