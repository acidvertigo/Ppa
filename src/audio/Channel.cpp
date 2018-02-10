/*
 * File: Channel.cpp
 * ---------------
 * This file implements the Channel.h interface.
 */
#include "audio/Channel.h"
#include "common/String.h"

using namespace std;
using namespace Ppa::Common;

namespace Ppa {
namespace Audio {

/*
 * Constructor: Channel
 * Usage: Channel ch("brass", 3);
 * ------------------------
 * Creates a Channel object.  The parameter sets the name and number;
 */
Channel::Channel(string namec, int numberc) : name(""), number(0) {
    name = namec;
    number = numberc;
}

Channel::~Channel() = default;

string Channel::GetName() const {
  return name;
}

int Channel::GetNumber() const {
  return number;
}

string Channel::toString() const {
  return name + NumberToString(number);
}

//------------------------------------

bool operator==(const Channel& c1, const Channel& c2) {
  return c1.number == c2.number;
}

bool operator!=(const Channel& c1, const Channel& c2) {
  return !(c1 == c2);
}

ostream& operator<<(ostream& os, const Channel& ch) {
  return os << ch.toString();
}

}  // namespace Audio end
}  // namespace Ppa end
