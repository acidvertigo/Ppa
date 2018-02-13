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
   static bool FSystem::FileExists (const string& filenamec) const {
       ifstream in(filenamec);
       return fl.good();
   }

//—————————————————————————————————————————————————————————————————————————-
   void FSystem::WriteContent ( const std::vector<char>& data)  {
     if(fl) 
     {
         fl.write(&data[0], data.size());
     }
     throw(errno);
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
   vector<char> FSystem::ReadContentAt(const char* filename, int byte) {
      if (fl)
       {
           vector<char> contents;
           fl.seekg(byte, ios::end);
           contents.resize(fl.tellg());
           fl.seekg(0, ios::beg);
           fl.read(&contents[0], contents.size());
           return(contents);
       }
       throw(errno);
   }

} // namespace Os end
} // namespace Ppa end
