#include <iostream>

#include "SavEdit.h"

int main(int argc, char *argv[])
{
    // boolean for keeping the main loop going
    bool done = false;

    // Create obj
    SavEdit save;

    if(argc == 2)
    {
        // Set the file name
        save.setFilename(argv[1]);
    }

    // Open the file
    save.open();

    // Create the backup
    save.backup();

    // Start the main loop.
    while(!done)
        done = save.select();

    // Update the checksum
    save.checksum();

    // Save and close the file.
    save.saveNewFile();

    return 0;
}
