#include <iostream>
#include <cstring>

#include "SavEdit.h"

void SavEdit::clear()
{
    /*
     * Operating system agnostic function that clears the screen.
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

        // This should fix the hex->deci issue.
        std::cin >> std::hex >> s;

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
        //std::cout << "\t4. QUIT, DO NOT SAVE" << std::endl;
        std::cout << "\t4. EDIT ITEM #0." << std::endl;
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

void SavEdit::debug()
{
    /*
     * This subroutine is just for
     * getting information. It
     * shouldn't be used otherwise.
     */

    // CURRENT TASK:
    //  [x] Finding out all 255 items
    //  [x] How many item slots are available?
    //          I suspect 25. (0x25CA to 0x25FC ?)
    //  [ ] Create subroutine for: item edit, item value edit

    // ITEM EDIT IDEA:
    //  1. Display item list
    //  2. Select item from list to edit
    //  3. Display list of item options
    //  4. Write item option + amount, if applicable

    // Top of HM/TM list.
    int startingval = 0xC0;
    int inc = 4; 

    int s = startingval + inc;

    std::cout << "Setting items to 25." << std::endl;
    mem.at(0x25C9) = 0x19;

    // Testing item ceiling
    for(int i = 0; i <= 0x19; ++i)
    {
        std::cout << "Item added at addr: " << std::endl;
        mem.at(0x25CA + (i * 2)) = s + i;
        std::cout << std::hex << s + i << std::endl;
        if(i == 0x19)
        {
            // Set cancel properly.
            mem.at(0x25CA + (i * 2)) = 0xFF;
        }
    }
}

void SavEdit::displayItems()
{
    /*
     * Displays items and quantities held within
     * pocket. 
     */

    // TODO: Create vector items list
    // TODO: Find how many slots are in the pocket
    // TODO: Item quantity is displayed as hex, but represents deci.
    //       How do I solve this issue? This would also solve the cash
    //       issue.

    // FORMAT:
    // [ITEM #0] [NAME] x[VAL]  | [ITEM #1] [NAME] x[VAL]
    // 
    // TODO: Maybe a selection menu, list of potential items?


    std::cout << "TODO: Make displayItems();" << std::endl;
}
