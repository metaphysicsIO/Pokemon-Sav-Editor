#include <iostream>
#include <cstring>

#include "SavEdit.h"

void SavEdit::clear()
{
    /*
     * Weird screen clear trick I do not remember where I learned it.
     */
    std::cout << "\033[2J\033[1;1H";
}

void SavEdit::modify(const int BEGIN, const int END)
{
    /*
     * Reusable code for editing sections goes here.
     */

    // Make sure the input stays within its expected limits.
    bool correct = false;

    // +1 to include self.
    const int SIZE_LIMIT = (END - BEGIN) + 1;
    
    // This is the user input string.
    std::string s;

    // Prevent the user from breaking limits.
    while(!correct)
    {
        // TODO: Clear / Redraw screen
        std::cout << "input: ";

        std::cin >> s;

        if((const int)s.length() <= SIZE_LIMIT)
            correct = true;

        // Clear the buffer.
        std::cin.clear();
    }

    for(unsigned long int i = 0; i <= (unsigned long int)(END - BEGIN); ++i)
    {
        if(i < s.length())
        {
            // Apply one char at a time.
            const char *c = s.substr(i, 1).c_str();
            modMem( (BEGIN + i), c[0]);
        }

        // Some require 0x50 at the end (TRAINER + RIVAL NAME).
        if(i == s.length())
            if(BEGIN == 0x2598 || BEGIN == 0x25F6)
                mem.at(BEGIN + i) = 0x50;
    }

}

void SavEdit::cashModify()
{
    /*
     * Money is handled differently.
     */

    // Check for correctness
    bool correct = false;

    // User input
    std::string s;

    while(!correct)
    {
        std::cout << "input (numbers only): " << std::endl;

        std::cin >> s;

        if(atoi(s.c_str()) <= 999999)
        {
            correct = true;
        }

        // clear the buffer.
        std::cin.clear();
    }

    // Pad with zeros
    s = std::string(6 - s.length(), '0') + s;

    // Apply the values
    for(int i = 0; i <= 2; ++i)
    {
        // Convert to char
        const char *c = s.substr((i*2), 2).c_str();
        // Convert to int (the char values are in the way.)
        int x_val = ((c[0] * 10) + c[1]);
        // Remove 528 because, for some reason, that's how much higher it is.
        int x_tot = x_val - 528; 

        // BUGFIX: For some reason, we need to remove 1 extra for 1 and 2?
        if(c[0] == 0)
            if((c[1] == '1') || (c[1] == '2'))
                x_tot--;

        // apply
        mem.at(0x25f3 + i) = x_tot;
    }
}

bool SavEdit::select()
{
    /*
     * A giant switch for determining which offsets to edit.
     *
     * TODO: May want to break this down into something else.
     */

    // For the loop. I might not keep it like this.
    bool finished = false;

    // Check for correct input.
    bool correct = false;
    int OPTIONS_LIMIT = 4;

    // user input.
    int selection;

    // Check if supported.
    while(!correct)
    {
        // TODO: translate + create subroutine
        // TODO: Clear / Redraw Screen
        // TODO: Create a better menu
        std::cout << "EDIT: " << std::endl;
        std::cout << "\t1. Player Name" << std::endl;
        std::cout << "\t2. RIVAL Name" << std::endl;
        std::cout << "\t3. MONEY" << std::endl;
        std::cout << "\t4. QUIT, DO NOT SAVE" << std::endl;
        std::cout << "\t0. SAVE AND QUIT" << std::endl;
        std::cout << "YOUR INPUT: ";

        std::cin >> selection;

        if(selection >= 0)
            if(selection <= OPTIONS_LIMIT)
                correct = true;


        // clear the buffer.
        std::cin.clear();
    }


    // TODO: Allow for custom edits?

    switch(selection)
    {
        case 0:
            std::cout << "SAVING FILE..." << std::endl;
            checksum();
            saveNewFile();
            finished = true;
            break;
        case 1:
            std::cout << "EDITING TRAINER NAME:" << std::endl;
            modify(0x2598, 0x259E);
            break;
        case 2:
            std::cout << "EDITING RIVAL NAME:" << std::endl;
            modify(0x25F6, 0x25FD);
            break;
        case 3:
            std::cout << "EDITING MONEY:" << std::endl;
            //std::cout << "SETTING TO 999,999 POKEDOLLARS." << std::endl;
            //mem.at(0x25F3) = 99;
            //mem.at(0x25F4) = 99;
            //mem.at(0x25F5) = 99;
            cashModify();
            //modify(0x25F3, 0x25F5); 
            break;
        case 4:
            std::cout << "Quitting without saving." << std::endl;
            finished = true;
            break;
        default:
            std::cout << "NOT AN OPTION" << std::endl;
            break;
    }

    // TODO: Display what is currently there

    return finished;
}
