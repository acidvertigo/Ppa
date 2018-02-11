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

   OS_EXPORT void Open (const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out) override;
   OS_EXPORT void Close () const override;
   OS_EXPORT bool IsOpen () const override;
   OS_EXPORT bool Exists () const override;

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
