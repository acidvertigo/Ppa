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

   }

   FSystem::~FSystem() = default;

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
       std::ifstream in(filename, ios::in | ios::binary);
       if (in)
       {
           vector<char> contents;
           in.seekg(0, ios::end);
           contents.resize(in.tellg());
           in.seekg(0, ios::beg);
           in.read(&contents[0], contents.size());
           in.close();
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
