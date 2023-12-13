/* Programmer's name: Ashton
 * Contact info: [HIDDEN]
 * Date Created: Nov 18, 2023
 * Version: 1.0.0
 * Purpose: Edit the user's party and their individual attributes.
 * Issue:  Aesthetically, the specific details could look nice.
 *  For example, subroutines `printMoves` and `printStats` should
 *  probably print to be side-by-side.
 *  
 *  ---------- EXAMPLE -------------------
 *  [Party Member #3]   Nidorano(M)
 *      LVL: 3          
 *      HP : 16         MOVE #1: Leer
 *      ATK: 8          MOVE #2: Tackle
 *      DEF: 7          MOVE #3: Toxic
 *      SPD: 8          MOVE #4: Peck
 *      SPE: 7          
 * ---------- EXAMPLE -------------------
 * or something like this.
 *
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <map>

#include "SavEdit.h"

int SavEdit::selectStat()
{
    /*
     * The main state for the user to make edits to their party.
     */

    bool safe = false;
    int stat_val_offset = 0;

    std::cout << " 1: Level\n";
    std::cout << " 2: Hitpoints\n";
    std::cout << " 3: Attack\n";
    std::cout << " 4: Defense\n";
    std::cout << " 5: Speed\n";
    std::cout << " 6: Special\n";
    std::cout << " 7: MOVE 1\n";
    std::cout << " 8: MOVE 2\n";
    std::cout << " 9: MOVE 3\n";
    std::cout << " 0: MOVE 4\n";
    std::cout << "10: Pokemon\n" << std::endl;

    std::cout << "Select:";

    while(!safe)
    {
        std::cin >> std::dec >> stat_val_offset;

        switch(stat_val_offset)
        {
            case 1:
                stat_val_offset = 0x00;
                safe = true;
                break;
            case 2:
                stat_val_offset = 0x01;
                safe = true;
                break;
            case 3:
                stat_val_offset = 0x02;
                safe = true;
                break;
            case 4:
                stat_val_offset = 0x03;
                safe = true;
                break;
            case 5:
                stat_val_offset = 0x04;
                safe = true;
                break;
            case 6:
                stat_val_offset = 0x05;
                safe = true;
                break;
            case 7:
                stat_val_offset = 0x10;
                safe = true;
                break;
            case 8:
                stat_val_offset = 0x11;
                safe = true;
                break;
            case 9:
                stat_val_offset = 0x12;
                safe = true;
                break;
            case 0:
                stat_val_offset = 0x13;
                safe = true;
                break;
            case 10:
                stat_val_offset = 0x14;
                safe = true;
                break;
            default:
                std::cout << "Try again." << std::endl;
                break;
        }

        // clear buffer
        std::cin.clear();
        std::cin.ignore();
    }

    return stat_val_offset;
}

void SavEdit::printParty()
{
    /*
     * Iterates through current party.
     */

    int start_addr = 0x2f2c;

    for(int i = 1; i <= 6; ++i)
    {
        std::stringstream mem_to_hex;
        mem_to_hex << std::setw(2) << std::setfill('0') << std::hex << mem.at(start_addr + i);
        std::string char_loc(mem_to_hex.str());
        std::cout << i << ": " << pkmn[char_loc] << std::endl;
    }
}

void SavEdit::printMoves(int party_member)
{
    /*
     * Iterate through given move set of selected party member.
     */
    int loc = 0x2f0f + (0x2C * party_member);

    for(int i = 1; i <= 4; ++i)
    {
        std::stringstream mem_to_hex;
        mem_to_hex << std::setw(2) << std::setfill('0') << std::hex << mem.at(loc + i);
        std::string char_loc(mem_to_hex.str());
        std::cout << "MOVE #" << i << ": " << move[char_loc] << std::endl; 
    }
}

void SavEdit::printStats(int party_member)
{
    /*
     * Displays stats of selected party member
     */
    int loc = 0x2f29 + (44 * party_member);
    std::cout << "LVL: " << mem.at(loc + 0x0) << std::endl;
    std::cout << "HP: " << mem.at(loc + 0x2) << std::endl;
    std::cout << "ATK: " << mem.at(loc + 0x4) << std::endl;
    std::cout << "DEF: " << mem.at(loc + 0x6) << std::endl;
    std::cout << "SPD: " << mem.at(loc + 0x8) << std::endl;
    std::cout << "SPE: " << mem.at(loc + 0xA) << std::endl;
}

void SavEdit::modMainMenu()
{
    /*
     * State for editing
     */
    int start_point = 0x2f29;
    int party_member_offset = 0;
    int stat_val_offset = 0;
    int state_value = 0;

    int party_member = 0;

    // Make room
    clear();

    // Print a list of party members for the user to edit
    printParty();

    // TODO: Stay on this party member until the user is done editing,
    //       then just roll back to party selection.
    // TODO: I think we need back buttons and state handling here.
    std::cout << "Select party member: ";

    while((party_member > 6) || (party_member < 1))
    {
        std::cin >> party_member;

        if((party_member > 6) || (party_member < 1))
        {
            std::cout << "wrong input. Try again." << std::endl;
        }
    }

    // Make room again
    clear();

    // First we need to convert deci -> hex before searching.
    std::stringstream mem_to_hex;
    mem_to_hex << std::setw(2) << std::setfill('0') << std::hex << mem.at(start_point + 0x03 + party_member);
    // Convert to a string.
    std::string char_loc(mem_to_hex.str());
    std::cout << "[Party Member #" << party_member << "] ";
    std::cout << pkmn[char_loc] << std::endl;
    
    // Print out stats of party member to edit.
    printStats(party_member);
    // Print moves list
    printMoves(party_member);

    std::cout << std::endl;

    std::cout << "Options:" << std::endl;

    // Get the stat address
    stat_val_offset = selectStat();

    // Get stat value
    std::cout << "What would you like to set this to?" << std::endl;

    switch(stat_val_offset)
    {
        case 0x14:
            // Change species.
            // TODO: update next memory to 0xFF if creating a new party member.
            // TODO: update 0x2F2C to the number of party members.
            party_member_offset = start_point + 0x03 + party_member;
            printPkmnlist();
            std::cin >> std::hex >> state_value;
            break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            // Change move.
            printMovelist();
            std::cin >> std::hex >> state_value; // TODO: Check user input
            party_member_offset = (start_point - 0x1A) + (0x2C * party_member) + (stat_val_offset - 0x0F); 
            break;
        default:
            party_member_offset = start_point + (44 * party_member) + (stat_val_offset * 0x02);
            std::cin >> state_value; // TODO: Check user input.
            break;
    }
    
    modStats(party_member_offset, state_value);
}

void SavEdit::modStats(int party_member_offset, int state_value)
{
    /*
     * Edit given party member's given stat.
     */

    int mem_to_edit;

    // Set memory address
    mem_to_edit = party_member_offset;

    // Edit that memory
    mem.at(mem_to_edit) = state_value;
}
