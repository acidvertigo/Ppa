/*
 * File: IFSystem.h
 * -------------
 * Interface for the FSystem class.
 */
#ifndef _IFSYSTEM_H_
#define _IFSYSTEM_H_

#include <iostream>
#include <fstream>
#include <vector>

namespace Ppa {
namespace Os {

class IFSystem {
public:

    virtual ~IFSystem() = default;
/*
 * Methods: IsOpen;
 * Usage: ch.IsOpen();
 * ----------------------------------
 * Returns true if the file is successfully opened
 */
    virtual bool FileIsOpen () const = 0;

/*
 * Methods: Exists
 * Usage: ch.Exists();
 * ----------------------------------
 * Returns true if the file already exists
 */
    virtual bool FileExists () const = 0;

/*
 * Methods: WriteContent
 * Usage: ch.WriteContent("guitar.wav", data{01110, 10101, 11111, ...});
 * ----------------------------------
 * Writes vector<char> content on file
 */
    virtual void WriteContent(const std::vector<char>& data) const = 0;

/*
 * Methods: WriteContent
 * Usage: ch.WriteContent("guitar.wav", data{01110, 10101, 11111, ...});
 * ----------------------------------
 * Writes vector<char> content on file
 */
    virtual void WriteContentAt(const std::vector<char>& data, int byte) = 0;    
  
/*
 * Methods: ReadContent
 * Usage: ch.ReadContent();
 * ----------------------------------
 * Reads vector<char> content from file
 */
    virtual std::vector<char> ReadContent() = 0;
    
/*
 * Methods: ReadContentAt
 * Usage: ch.ReadContentAt("piano.wav", 15);
 * ----------------------------------
 * Reads vector<char> content from file
 */
    virtual std::vector<char> ReadContentAt(const char* filename, int byte) const = 0;    

protected:
/*
 * Methods: Open
 * Usage: ch.Open("drums.wav");
 * ----------------------------------
 * This method opens a new file
 */
   virtual void OpenFile (const char* filename, std::ios::openmode mode = std::ios::in | std::ios::out) const = 0;

/*
 * Methods: Close
 * Usage: ch.Close();
 * ----------------------------------
 * Closes the file, flush the buffer and disconnect from stream object
 */  
   virtual void CloseFile () const = 0;

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
