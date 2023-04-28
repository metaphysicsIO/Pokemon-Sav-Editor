#include <iostream>

#include "SavEdit.h"

int main(int argc, char *argv[])
{
    // Create obj
    SavEdit save;

    if(argc == 2)
    {
        // Set the file name
        save.setFilename(argv[1]);
    }


    // Select language.
    //save.languageForm();
    
    // Send greeting.
    //save.greeting();

    // store file in vector
    save.open();

    // print vector
    //save.read();

    // create the backup
    save.backup();

    // Test OT
    //save.modify(0x2598, 0x259E);

    // TEST OPTIONS
    bool done = true; //false;
    while(!done)
        done = save.select();

    // To make things faster.
    save.debug();

    // Test the rival.
    //save.modify(0x25F6, 0x25FC);

    // Update the checksum.
    save.checksum();

    // Save the new file
    save.saveNewFile();

    return 0;
}
