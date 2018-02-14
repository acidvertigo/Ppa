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

   OS_EXPORT friend bool operator==(const FSystem& fs1, const FSystem& fs2);

protected:
   std::string filename;
   std::fstream fl;
};

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display BitDepth values.
 */
OS_EXPORT std::ostream& operator<<(std::ostream&, const FSystem&);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * -----------------
 * This operator supports equality testing for BitDepths.
 */
OS_EXPORT bool operator==(const FSystem&, const FSystem&);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * -----------------
 * This operator implements the != operator for BitDepth.
 */
OS_EXPORT bool operator!=(const FSystem&, const FSystem&);

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
