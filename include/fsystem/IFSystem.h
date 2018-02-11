/*
 * File: IFSystem.h
 * -------------
 * Interface for the FSystem class.
 */
#ifndef _IFSYSTEM_H_
#define _IFSYSTEM_H_

#include <iostream>
#include <fstream>

namespace Ppa {
namespace FSystem {

class IFSystem {

/*
 * Methods: Open
 * Usage: ch.Open("drums.wav");
 * ----------------------------------
 * This method opens a new file
 */
   virtual void Open (const char* filename, std:: ios_base::openmode mode = std::ios_base::in | std:: ios_base::out) const = 0;

/*
 * Methods: Close
 * Usage: ch.Close();
 * ----------------------------------
 * Closes the file, flush the buffer and disconnect from stream object
 */  
   virtual void Close () const = 0;
 
/*
 * Methods: IsOpen;
 * Usage: ch.IsOpen();
 * ----------------------------------
 * Returns true if the file is successfully opened
 */
    virtual bool IsOpen () const = 0;

/*
 * Methods: Exists
 * Usage: ch.Exists();
 * ----------------------------------
 * Returns true if the file already exists
 */
    virtual bool Exists () const = 0;
};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
