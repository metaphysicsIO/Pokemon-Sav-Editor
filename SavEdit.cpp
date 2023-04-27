#include <iostream>
#include <fstream>
#include <vector>

#include "SavEdit.h"

#define SAV_LEN 32767


void SavEdit::open()
{
    /*
     * Store save file in a vector.
     */

    std::ifstream fs(filename, std::ios::in | std::ios::binary);

    // Verify file is opened
    if(!fs)
    {
        // TODO: translation + subroutine needed.
        std::cout << "Cannot open file." << std::endl;
        exit(1);
    }

    // Iterate through file, adding to vector.
    for(int i = 0; i <= SAV_LEN; ++i)
        mem.push_back(fs.get());
}

void SavEdit::read()
{
    /*
     * Iterates through the opened file.
     * This is mostly just to make sure it
     * properly loaded everything up. I will
     * probably be modifying this for editing
     * later.
     */

    for(int i = 0; i <= SAV_LEN; ++i)
    {
        // offset address
        std::cout.fill('0');
        std::cout << "0x";
        std::cout.width(4);
        std::cout << std::hex << i;
        std::cout << ":\t";

        // print hex value
        std::cout.width(2);
        std::cout << std::hex << mem.at(i) << std::endl;
    }

}

void SavEdit::save(std::string fname)
{
    /*
     * This subroutine writes the binary
     * file using the offset vector.
     */

    std::ofstream bfs(fname, std::ios::out | std::ios::binary);

    if(!bfs)
    {
        // TODO: Translate + subroutine needed.
        std::cout << "Cannot create file." << std::endl;
        exit(2);
    }

    for(int i = 0; i <= SAV_LEN; ++i)
        bfs.write( (char*)&mem.at(i), 1);

}

void SavEdit::backup()
{
    /*
     * Create the backup of the sav file
     * before editing.
     */

    save(getFilename() + ".BAK");
}

int SavEdit::checksum()
{
    /*
     * Set the checksum for the new SAV
     */

    // Autodetect if JP later.
    bool JP = false;

    // The Japanese gen 1 has a different offset
    int checksum_offset = JP ? 0x3594 : 0x3523;
    
    // Starting point for Bank One
    int bankStart = 0x2598;

    // Our new checksum
    unsigned int check_sum = 0;

    // Take all the data from bank 1, but skip the checksum.
    // (Non-JP: 0x2000 to 0x3522)
    for(int i = bankStart; i < checksum_offset; ++i)
        check_sum += mem.at(i);

    // bitwise NOT
    check_sum = ~check_sum;

    // bitwise AND_EQUAL
    check_sum &= 0xff;

    // Update the checksum.
    mem.at(checksum_offset) = check_sum;

    return check_sum;
}

int SavEdit::convert(char given)
{
    /*
     * Converts the given character to the proper value
     * in the text table.
     */

    // The characters are 63 over their ASCII value.
    int mod = 63;

    mod += (int)given;

    return mod;
}

void SavEdit::modMem(int offset, char val)
{
    /*
     * Edits the specified offset to the given value,
     * after converting the given value to it's proper
     * format.
     */

    // note: should this subroutine contain checks?
    mem.at(offset) = convert(val);
}

void SavEdit::saveNewFile()
{
    /*
     * This updates the new file and saves it.
     */

    save(getFilename());
}
