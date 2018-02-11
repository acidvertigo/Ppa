/*
 * File: FSystem.h
 * -------------
 * This interface exports the FSystem implementation, which is responsable
 * for file I/O operations.
 */
#ifndef _FSYSTEM_H_
#define _FSYSTEM_H_

#include "fsystem_export.h"
#include "IFSystem.h"

#include <iostream>
#include <fstream>

namespace Ppa {
namespace FSystem {

class FSystem : IFSystem {

   FSYSTEM_EXPORT void Open (const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out) const override;
   FSYSTEM_EXPORT void Close () const override;
   FSYSTEM_EXPORT bool IsOpen () const override;
   FSYSTEM_EXPORT bool Exists () const = override;

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
