#include <iostream>
#include <cstring>
#include <iomanip>

#include "SavEdit.h"

void SavEdit::printMovelist()
{
    /*
     * Print move options.
     */
    printf("%-18s%-18s%-18s%-18s%-18s\n","01: Pound","22: Body Slam","43: Low Kick","64: Teleport","85: Amnesia");
    printf("%-18s%-18s%-18s%-18s%-18s\n","02: Karate Chop","23: Wrap","44: Counter","65: Night Shade","86: Kinesis");
    printf("%-18s%-18s%-18s%-18s%-18s\n","03: Double Slap","24: Take Down","45: Seismic Toss","66: Mimic","87: Soft-Boiled");
    printf("%-18s%-18s%-18s%-18s%-18s\n","04: Comet Punch","25: Thrash","46: Strength","67: Screech","88: High Jump Kick");
    printf("%-18s%-18s%-18s%-18s%-18s\n","05: Mega Punch","26: Double-Edge","47: Absorb","68: Double Team","89: Glare");
    printf("%-18s%-18s%-18s%-18s%-18s\n","06: Pay Day","27: Tail Whip","48: Mega Drain","69: Recover","8a: Dream Eater");
    printf("%-18s%-18s%-18s%-18s%-18s\n","07: Fire Punch","28: Poison Sting","49: Leech Seed","6a: Harden","8b: Poison Gas");
    printf("%-18s%-18s%-18s%-18s%-18s\n","08: Ice Punch","29: Twineedle","4a: Growth","6b: Minimize","8c: Barrage");
    printf("%-18s%-18s%-18s%-18s%-18s\n","09: Thunder Punch","2a: Pin Missile","4b: Razor Leaf","6c: Smokescreen","8d: Leech Life");
    printf("%-18s%-18s%-18s%-18s%-18s\n","0a: Scratch","2b: Leer","4c: Solar Beam","6d: Confuse Ray","8e: Lovely Kiss");
    printf("%-18s%-18s%-18s%-18s%-18s\n","0b: Vise Grip","2c: Bite","4d: Poison Powder","6e: Withdraw","8f: Sky Attack");
    printf("%-18s%-18s%-18s%-18s%-18s\n","0c: Guillotine","2d: Growl","4e: Stun Spore","6f: Defense Curl","90: Transform");
    printf("%-18s%-18s%-18s%-18s%-18s\n","0d: Razor Wind","2e: Roar","4f: Sleep Powder","70: Barrier","91: Bubble");
    printf("%-18s%-18s%-18s%-18s%-18s\n","0e: Swords Dance","2f: Sing","50: Petal Dance","71: Light Screen","92: Dizzy Punch");
    printf("%-18s%-18s%-18s%-18s%-18s\n","0f: Cut","30: Supersonic","51: String Shot","72: Haze","93: Spore");
    printf("%-18s%-18s%-18s%-18s%-18s\n","10: Gust","31: Sonic Boom","52: Dragon Rage","73: Reflect","94: Flash");
    printf("%-18s%-18s%-18s%-18s%-18s\n","11: Wing Attack","32: Disable","53: Fire Spin","74: Focus Energy","95: Psywave");
    printf("%-18s%-18s%-18s%-18s%-18s\n","12: Whirlwind","33: Acid","54: Thunder Shock","75: Bide","96: Splash");
    printf("%-18s%-18s%-18s%-18s%-18s\n","13: Fly","34: Ember","55: Thunderbolt","76: Metronome","97: Acid Armor");
    printf("%-18s%-18s%-18s%-18s%-18s\n","14: Bind","35: Flamethrower","56: Thunder Wave","77: Mirror Move","98: Crabhammer");
    printf("%-18s%-18s%-18s%-18s%-18s\n","15: Slam","36: Mist","57: Thunder","78: Self-Destruct","99: Explosion");
    printf("%-18s%-18s%-18s%-18s%-18s\n","16: Vine Whip","37: Water Gun","58: Rock Throw","79: Egg Bomb","9a: Fury Swipes");
    printf("%-18s%-18s%-18s%-18s%-18s\n","17: Stomp","38: Hydro Pump","59: Earthquake","7a: Lick","9b: Bonemerang");
    printf("%-18s%-18s%-18s%-18s%-18s\n","18: Double Kick","39: Surf","5a: Fissure","7b: Smog","9c: Rest");
    printf("%-18s%-18s%-18s%-18s%-18s\n","19: Mega Kick","3a: Ice Beam","5b: Dig","7c: Sludge","9d: Rock Slide");
    printf("%-18s%-18s%-18s%-18s%-18s\n","1a: Jump Kick","3b: Blizzard","5c: Toxic","7d: Bone Club","9e: Hyper Fang");
    printf("%-18s%-18s%-18s%-18s%-18s\n","1b: Rolling Kick","3c: Psybeam","5d: Confusion","7e: Fire Blast","9f: Sharpen");
    printf("%-18s%-18s%-18s%-18s%-18s\n","1c: Sand Attack","3d: Bubble Beam","5e: Psychic","7f: Waterfall","a0: Conversion");
    printf("%-18s%-18s%-18s%-18s%-18s\n","1d: Headbutt","3e: Aurora Beam","5f: Hypnosis","80: Clamp","a1: Tri Attack");
    printf("%-18s%-18s%-18s%-18s%-18s\n","1e: Horn Attack","3f: Hyper Beam","60: Meditate","81: Swift","a2: Super Fang");
    printf("%-18s%-18s%-18s%-18s%-18s\n","1f: Fury Attack","40: Peck","61: Agility","82: Skull Bash","a3: Slash");
    printf("%-18s%-18s%-18s%-18s%-18s\n","20: Horn Drill","41: Drill Peck","62: Quick Attack","83: Spike Cannon","a4: Substitute");
    printf("%-18s%-18s%-18s%-18s%-18s\n","21: Tackle","42: Submission","63: Rage","84: Constrict","a5: Struggle");

}

int SavEdit::selectStat()
{
    bool safe = false;
    int stat_val_offset;

    std::cout << "1: Hitpoints\n";
    std::cout << "2: Level\n";
    std::cout << "3: Attack\n";
    std::cout << "4: Defense\n";
    std::cout << "5: Speed\n";
    std::cout << "6: Special\n";
    std::cout << "7: MOVE 1\n";
    std::cout << "8: MOVE 2\n";
    std::cout << "9: MOVE 3\n";
    std::cout << "0: MOVE 4\n" << std::endl;

    while(!safe)
    {
        std::cin >> stat_val_offset;

        switch(stat_val_offset)
        {
            case 1:
                stat_val_offset = 0x2B; // 0x0A is CURRENTLY HP
                safe = true;
                break;
            case 2:
                stat_val_offset = 0x29;
                safe = true;
                break;
            case 3:
                stat_val_offset = 0x2D;
                safe = true;
                break;
            case 4:
                stat_val_offset = 0x2F;
                safe = true;
                break;
            case 5:
                stat_val_offset = 0x31;
                safe = true;
                break;
            case 6:
                stat_val_offset = 0x33;
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
            default:
                std::cout << "Try again." << std::endl;
                break;
        }

    }

    return stat_val_offset;
}

void SavEdit::modMainMenu()
{
    /*
     * State for editing
     */
    int party_member_offset;
    int stat_val_offset;
    int state_value;

    //TODO: Display party list
    
    //TODO: Allow user to select party member
    party_member_offset = 0;

    // Get the stat address
    stat_val_offset = selectStat();

    // Get stat value
    std::cout << "What would you like to set this to?" << std::endl;

    if( (stat_val_offset == 0x10) ||
        (stat_val_offset == 0x11) ||
        (stat_val_offset == 0x12) ||
        (stat_val_offset == 0x13))
    {
        printMovelist();
        // Move sets require hex.
        std::cin >> std::hex >> state_value;
    }else{
        // All other stats require deci.
        std::cin >> state_value;
    }

    modStats(party_member_offset, stat_val_offset, state_value);

}

void SavEdit::modStats(int party_member_offset, int stat_val_offset, int state_value)
{
    /*
     * Edit given party member's given stat.
     */

    /* offset list
     * ID : 0x01
     * HP : 0x0A
     * LVL: 0x29 
     * ATK: 0x2D
     * DEF: 0x2F
     * SPD: 0x31
     * SPE: 0x33
     * --
     * MOVES
     * MOVE 1: 0x2F3C ?
     * MOVE 2: 0x2F3D ?
     * MOVE 3: 0x2F3E ?
     * MOVE 4: 0x2F3F ?
     */


    // Start of memory block for the party 
    int party_offset = 0x2F2C;

    //int party_member_offset;
    //int stat_val_offset;
    //int state_value;
    int mem_to_edit;

    // jump to proper memory
    mem_to_edit = party_offset + party_member_offset + stat_val_offset;

    // Edit that memory.
    mem.at(mem_to_edit) = state_value;

}
