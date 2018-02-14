/*
 * File: IChannel.h
 * -------------
 * Interface for the Channel class.
 */
#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "audio_export.h"
#include "IChannel.h"

#include <iostream>

namespace Ppa {
namespace Audio {

class Channel : public IChannel {
public:
  AUDIO_EXPORT Channel(std::string namec, int numberc);
  AUDIO_EXPORT ~Channel() override;

  AUDIO_EXPORT int GetNumber() const override;
  AUDIO_EXPORT std::string GetName() const override;
  AUDIO_EXPORT std::string toString() const override;

  /*
   * friend method needed from comparison operator
   */
  AUDIO_EXPORT friend bool operator==(const Channel&, const Channel&);

protected:
   std::string name;
   int  number; 
};

/*
 * Operator: <<
 * Usage: cout << sr;
 * ------------------
 * Overloads the << operator so that it is able to display channel values.
 */
AUDIO_EXPORT std::ostream& operator<<(std::ostream&, const Channel&);

/*
 * Operator: ==
 * Usage: sr1 == sr2
 * -----------------
 * This operator supports equality testing for channels.
 */
AUDIO_EXPORT bool operator==(const Channel&, const Channel&);

/*
 * Operator: !=
 * Usage: sr1 != sr2
 * -----------------
 * This operator implements the != operator for channels.
 */
AUDIO_EXPORT bool operator!=(const Channel&, const Channel&);

} // namespace Audio end
} // namespace Ppa end

#endif /* _CHANNEL_H_ */
