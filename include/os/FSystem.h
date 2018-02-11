/*
 * File: FSystem.h
 * -------------
 * This interface exports the FSystem implementation, which is responsable
 * for file I/O operations.
 */
#ifndef _FSYSTEM_H_
#define _FSYSTEM_H_

#include "os_export.h"
#include "IFSystem.h"

#include <iostream>
#include <fstream>

namespace Ppa {
namespace Os {

class FSystem : IFSystem {
public:
   OS_EXPORT FSystem::FSystem(string filenamec) {}
   OS_EXPORT ~FSystem::FSystem() = default;

   OS_EXPORT bool FileIsOpen () const override;
   OS_EXPORT bool FileExist () const override;
   OS_EXPORT void WriteContent ( const char* filename, std::vector<BYTE> data) const override;
   OS_EXPORT std::vector<BYTE> ReadContent (const char* filename) const override;

protected:
   std::string filename;

   void OpenFile (const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out) const override;
   void CloseFile () const override;
};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
