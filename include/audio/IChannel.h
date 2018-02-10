/*
 * File: IChannel.h
 * -------------
 * Interface for the Channel class.
 */
#ifndef _ICHANNEL_H_
#define _ICHANNEL_H_

#include <string>

namespace Ppa {
namespace Audio {

class IChannel {
public:
   virtual ~IChannel() = default;

/*
 * Method: GetNumber
 * Usage: int x = ch.GetNumber();
 * ----------------------------------
 * These methods returns the current channel number
 */
   virtual int GetChannelNumber() const = 0;

/*
 * Method: GetName
 * Usage: int x = ch.GetName();
 * ----------------------------------
 * These methods returns the current channel name
 */
   virtual std::string GetChannelName() const = 0;

/*
 * Method: toString
 * Usage: string str = ch.toString();
 * ----------------------------------
 * Returns a string representation of the bit depth.
 */
   virtual std::string toString() const = 0;

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _ICHANNEL_H_ */
