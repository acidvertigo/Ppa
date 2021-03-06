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
       fl.open(filename, ios::in | ios::binary);
   }

   FSystem::~FSystem() {
       fl.close();
   }

//—————————————————————————————————————-
   string FSystem::GetFilename() const {
       return filename;
   }

//————————————————————————————————————
   bool FSystem::FileIsOpen () const {
       return fl.is_open();
   }

//————————————————————————————————————————————————————-
   bool FSystem::FileExists (const string& filenamec) {
       ifstream in(filenamec);
       return in.good();
   }

//———————————————————————————————————————————————————————————————
   void FSystem::WriteContent ( const std::vector<char>& data)  {
     if(fl) 
     {
         fl.write(&data[0], data.size());
     }
     throw(errno);
   }

//———————————————————————————————————————
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

//----------------------------------------------------------------------
   vector<char> FSystem::ReadContentAt(const long& start = 0) {
      if (fl)
       {
           vector<char> contents;
           fl.seekg(start, ios::beg);
           contents.resize(fl.tellg());
           fl.read(&contents[0], contents.size());
           return(contents);
       }
       throw(errno);
   }

//----------------------------------——————————————————————-

bool operator==(const FSystem& fs1, const FSystem& fs2) {
  return fs1.filename == fs2.filename;
}

//————————————————————————————————————————————————————————-
bool operator!=(const FSystem& fs1, const FSystem& fs2) {
  return !(fs1 == fs2);
}

//———————————————————————————————————————————————————-
ostream& operator<<(ostream& os, const FSystem& fs) {
  return os << fs.GetFilename();
}

} // namespace Os end
} // namespace Ppa end
