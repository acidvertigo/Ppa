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

#include <string>

namespace Ppa {
namespace Os {

class FSystem : IFSystem {
public:
   OS_EXPORT FSystem(std:string filenamec);
   OS_EXPORT ~FSystem() = default;

   OS_EXPORT bool FileIsOpen () const override;
   OS_EXPORT bool FileExists () const override;
   OS_EXPORT void WriteContent (const std::vector<char>& data) const override;
   OS_EXPORT std::vector<char> ReadContent () const override;

protected:
   std::string filename;

   void OpenFile (const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out) const override;
   void CloseFile () const override;
};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
