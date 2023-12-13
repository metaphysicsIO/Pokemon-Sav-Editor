#include <iostream>

#include "SavEdit.h"

SavEdit::SavEdit()
{
    /*
     * init
     */

    filename = "Pokemon - Red Version (USA, Europe) (SGB Enhanced).sav";
    
    lang = en_US;

    // Generate the hashmaps
    pkmnMap();
    moveMap();
    //TODO: itemMap();

}

std::string SavEdit::getFilename()
{
    /*
     * Return the file name.
     */

    return filename;
}

void SavEdit::setFilename(std::string fname)
{
    /*
     * Set the file name.
     */

    filename = fname;
}
