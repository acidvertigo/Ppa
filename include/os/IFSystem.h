/*
 * File: IFSystem.h
 * -------------
 * Interface for the FSystem class.
 */
#ifndef _IFSYSTEM_H_
#define _IFSYSTEM_H_

#include <iostream>
#include <fstream>
#include <string>
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
 * Methods: getFilaname()
 * Usage: ch.getFikename();
 * ----------------------------------
 * Returns the current filename
 */
    virtual std::string getFilename() const = 0;  

/*
 * Methods: WriteContent
 * Usage: ch.WriteContent("guitar.wav", data{01110, 10101, 11111, ...});
 * ----------------------------------
 * Writes vector<char> content on file
 */
    virtual void WriteContent(const std::vector<char>& data) = 0;

/*
 * Methods: ReadContent
 * Usage: ch.ReadContent();
 * ----------------------------------
 * Reads vector<char> content from file
 */
    virtual std::vector<char> ReadContent() = 0;
    
/*
 * Methods: ReadContentAt
 * Usage: ch.ReadContentAt(const long& start);
 * ----------------------------------
 * Reads vector<char> content from file
 */
    virtual std::vector<char> ReadContentAt(const long& start) = 0;    

};

} // namespace Audio end
} // namespace Ppa end

#endif /* _IFSYSTEM_H_ */
