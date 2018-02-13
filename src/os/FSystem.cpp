/*
 * File: FSystem.cpp
 * ---------------
 * This file implements the FSystem.h interface.
 */
#include "os/FSystem.h"

using namespace std;

namespace Ppa {
namespace Os {

   FSystem::FSystem(string filenamec) : filename(filenamec) {
       file(filenamec, ios::in | ios::binary);
   }

   FSystem::~FSystem() {
       file.close();
   }

//————————————————————————————————————
   bool FSystem::FileIsOpen () const {
       ifstream ifs (filename);
       return ifs.is_open();
   }

//————————————————————————————————————
   bool FSystem::FileExists () const {

   }

//—————————————————————————————————————————————————————————————————————————-
   void FSystem::WriteContent ( const std::vector<char>& data) const {

   }
   
//------------------------------------------------------------------------------
   void FSystem::WriteContentAt(const std::vector<char>& data, int byte) const {
      
   }

//———————————————————————————————————————————————————————----------
   vector<char> FSystem::ReadContent (const char* filename) const {
       if (file)
       {
           vector<char> contents;
           file.seekg(0, ios::end);
           contents.resize(file.tellg());
           file.seekg(0, ios::beg);
           file.read(&contents[0], contents.size());
           return(contents);
       }
       throw(errno);
   }

//----------------------------------------------------------------------------
   vector<char> FSystem::ReadContentAt(const char* filename, int byte) const {
      
   }
   
//————————————————————————————————————————————————————————————————————————-
   void FSystem::OpenFile(const char* filename, ios::openmode mode) const {

   }

//———————————————————————————————————
   void FSystem::CloseFile () const {

   }

} // namespace Os end
} // namespace Ppa end
