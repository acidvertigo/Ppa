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

namespace Ppa {
namespace Os {

class FSystem : public IFSystem {
public:
   OS_EXPORT FSystem(std::string filenamec);
   OS_EXPORT ~FSystem() override;

   OS_EXPORT bool FileIsOpen () const override;
   OS_EXPORT std::string GetFilename() const override;
   OS_EXPORT void WriteContent (const std::vector<char>& data) override;  
   OS_EXPORT std::vector<char> ReadContent () override;
   OS_EXPORT std::vector<char> ReadContentAt(const long& start) override;

/*
 * Methods: Exists
 * Usage: FSystem::Exists();
 * ----------------------------------
 * Returns true if the file already exists
 */
   OS_EXPORT static bool FileExists (const std::string& filenamec);

protected:
   std::string filename;
   std::fstream fl;
};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
