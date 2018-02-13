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

class FSystem : public IFSystem {
public:
   OS_EXPORT FSystem(std::string filenamec);
   OS_EXPORT ~FSystem() override;

   OS_EXPORT bool FileIsOpen () const override;
   OS_EXPORT bool FileExists () const override;
   OS_EXPORT void WriteContent (const std::vector<char>& data) override;
   OS_EXPORT void WriteContentAt(const std::vector<char>& data, int byte) const override;    
   OS_EXPORT std::vector<char> ReadContent () override;
   OS_EXPORT std::vector<char> ReadContentAt(const char* filename, int byte) const override;  

protected:
   std::string filename;
   std::fstream fl;

   void OpenFile (const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out) const override;
   void CloseFile () const override;
};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
