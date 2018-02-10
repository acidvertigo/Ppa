/*
 * File: BitDepth.cpp
 * ---------------
 * This file implements the BitDepth.h interface.
 */
#include "audio/BitDepth.h"
#include "common/String.h"

#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace Ppa::Common;

namespace Ppa {
namespace Audio {

/*
 * Constructor: BitDepth
 * Usage: BitDepth bd(24, false);
 * ------------------------
 * Creates a BitDepth object.  The parameter sets the samplerate;
 */
BitDepth::BitDepth(int bitdepthc) : bitdepth(0), allowed{8,16,24,32,64} {
  if (!IsValid(bitdepthc)) {
    throw invalid_argument( "bit depth value not allowed" );
  } else {
    bitdepth = bitdepthc;
  }
}

BitDepth::~BitDepth() = default;

int BitDepth::GetBitDepth() const {
  return bitdepth;
}

string BitDepth::toString() const {
  return NumberToString(bitdepth);
}

bool BitDepth::IsValid(const int& value) const {
  return std::find(allowed.begin(), allowed.end(), value) != allowed.end();
}

//------------------------------------

bool operator==(const BitDepth& bd1, const BitDepth& bd2) {
  return bd1.bitdepth == bd2.bitdepth;
}

bool operator!=(const BitDepth& bd1, const BitDepth& bd2) {
  return !(bd1 == bd2);
}

ostream& operator<<(ostream& os, const BitDepth& bd) {
  return os << bd.toString();
}

}  // namespace Audio end
}  // namespace Ppa end
