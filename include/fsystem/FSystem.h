/*
 * File: FSystem.h
 * -------------
 * This interface exports the FSystem class, which represents audio
 * sample rate frequency.
 */
#ifndef _FSYSTEM_H_
#define _FSYSTEM_H_

#include "fsystem_export.h"
#include "IFSystem.h"

#include <iostream>
#include <fstream>

namespace Ppa {
namespace FSystem {

   FSYSTEM_EXPORT void Open (const char* filename, ios::openmode mode = ios::in | ios::out) const override;
   FSYSTEM_EXPORT void Close () const override;
   FSYSTEM_EXPORT bool IsOpen () const override;
   FSYSTEM_EXPORT bool Exists () const = override;

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
