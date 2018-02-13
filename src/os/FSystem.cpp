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
       fl.open(filenamec, ios::in | ios::binary);
   }

   FSystem::~FSystem() {
       fl.close();
   }

//————————————————————————————————————
   bool FSystem::FileIsOpen () const {
       return fl.is_open();
   }

//————————————————————————————————————
   bool FSystem::FileExists () const {

   }

//—————————————————————————————————————————————————————————————————————————-
   void FSystem::WriteContent ( const std::vector<char>& data) const {
     if(fl) {
         fl.write(&data[0], data.size());
     }
     throw(errno);
   }
   
//------------------------------------------------------------------------------
   void FSystem::WriteContentAt(const std::vector<char>& data, int byte) const {
      
   }

//———————————————————————————————————————————————————————----------
   vector<char> FSystem::ReadContent () {
       if (fl)
       {
           vector<char> contents;
           fl.seekg(0, ios::end);
           contents.resize(fl.tellg());
           fl.seekg(0, ios::beg);
           fl.read(&contents[0], contents.size());
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
