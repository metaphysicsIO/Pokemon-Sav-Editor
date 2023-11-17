#include <iostream>
#include <cstring>
#include <iomanip>
#include <map>

#include "SavEdit.h"


/*
 *      NOTES FOR MYSELF: DELETE LATER.
 *
 * Noticed a big difference between Party 1 and Party 2 ID when compared
 * to their respective attributes.
 *
 * The range between Party #2's ID and MOVE 1 is 3A.
 * The range between Party #1's ID and MOVE 1 is F.
 * 
 * That is 2B, or 43 spaces between them. 
 * 
 * There is also a possibly 2nd ID for P#2 at 0x2F4C
 * which would come out to 1C. I suspect this isn't correc.t
 * 
 * But I may have solved it
 *
 * Let's see the difference between P1.ATK, P2.ATK and P1.DEF, P2.DEF:
 * P1.ATK - P2.ATK is |0x2f59 - 0x2F85| = 2C (44)
 * P1.DEF - P2.DEF is |0x2F5B - 0x2F87| = 2C (44)
 * 
 * So for stats, we can simply add 44(n) where n is the party #-1.
 * What about for moves?
 * 
 * P1.MOVE1 - P2.MOVE1 is |0x2F3C - 0x2F68| = 2C (44)
 * 
 * This is fine. This means the identification change will be
 * 0x2F2C + n, where n is the party number and the stats will
 * be changed with the memory offset + 44(n-1), where n is the party number.
 *
 *
 */

void SavEdit::pkmnMap()
{
    /*
     * Generates the mapping for pkmn values.
     */

    pkmn["94"] = "Abra";
    pkmn["ab"] = "Aerodactyl";
    pkmn["95"] = "Alakazam";
    pkmn["02"] = "Kangaskhan";
    pkmn["2d"] = "Arbok";
    pkmn["14"] = "Arcanine";
    pkmn["4a"] = "Articuno";
    pkmn["72"] = "Beedrill";
    pkmn["bc"] = "Bellsprout";
    pkmn["1c"] = "Blastoise";
    pkmn["99"] = "Bulbasaur";
    pkmn["7d"] = "Butterfree";
    pkmn["7b"] = "Caterpie";
    pkmn["28"] = "Chansey";
    pkmn["b4"] = "Charizard";
    pkmn["b0"] = "Charmander";
    pkmn["b2"] = "Charmeleon";
    pkmn["8e"] = "Clefable";
    pkmn["8b"] = "Cloyster";
    pkmn["11"] = "Cubone";
    pkmn["78"] = "Dewgong";
    pkmn["3b"] = "Diglett";
    pkmn["4c"] = "Ditto";
    pkmn["74"] = "Dodrio";
    pkmn["46"] = "Doduo";
    pkmn["59"] = "Dragonair";
    pkmn["42"] = "Dragonite";
    pkmn["58"] = "Dratini";
    pkmn["30"] = "Drowzee";
    pkmn["76"] = "Dugtrio";
    pkmn["66"] = "Eevee";
    pkmn["6c"] = "Ekans";
    pkmn["35"] = "Electabuzz";
    pkmn["8d"] = "Electrode";
    pkmn["0c"] = "Exeggcute";
    pkmn["0a"] = "Exeggutor";
    pkmn["40"] = "Farfetch'd";
    pkmn["23"] = "Fearow";
    pkmn["67"] = "Flareon";
    pkmn["19"] = "Gastly";
    pkmn["0e"] = "Gengar";
    pkmn["a9"] = "Geodude";
    pkmn["ba"] = "Gloom";
    pkmn["82"] = "Golbat";
    pkmn["9d"] = "Goldeen";
    pkmn["80"] = "Golduck";
    pkmn["31"] = "Golem";
    pkmn["27"] = "Graveler";
    pkmn["0d"] = "Grimer";
    pkmn["21"] = "Growlithe";
    pkmn["16"] = "Gyarados";
    pkmn["93"] = "Haunter";
    pkmn["2c"] = "Hitmonchan";
    pkmn["2b"] = "Hitmonlee";
    pkmn["5c"] = "Horsea";
    pkmn["01"] = "hydon";
    pkmn["81"] = "Hypno";
    pkmn["07"] = "Nidoking";
    pkmn["03"] = "Nidoran♂";
    pkmn["64"] = "Jigglypuff";
    pkmn["68"] = "Jolteon";
    pkmn["48"] = "Jynx";
    pkmn["5a"] = "Kabuto";
    pkmn["5b"] = "Kabutops";
    pkmn["26"] = "Kadabra";
    pkmn["71"] = "Kakuna";
    pkmn["8a"] = "Kingler";
    pkmn["37"] = "Koffing";
    pkmn["4e"] = "Krabby";
    pkmn["13"] = "Lapras";
    pkmn["04"] = "lefairy";
    pkmn["0b"] = "Lickitung";
    pkmn["08"] = "lowbro";
    pkmn["7e"] = "Machamp";
    pkmn["29"] = "Machoke";
    pkmn["6a"] = "Machop";
    pkmn["85"] = "Magikarp";
    pkmn["33"] = "Magmar";
    pkmn["ad"] = "Magnemite";
    pkmn["36"] = "Magneton";
    pkmn["39"] = "Mankey";
    pkmn["91"] = "Marowak";
    pkmn["4d"] = "Meowth";
    pkmn["7c"] = "Metapod";
    pkmn["15"] = "Mew";
    pkmn["83"] = "Mewtwo";
    pkmn["49"] = "Moltres";
    pkmn["2a"] = "Mr. Mime";
    pkmn["88"] = "Muk";
    pkmn["10"] = "Nidoqueen";
    pkmn["0f"] = "Nidoran♀";
    pkmn["a8"] = "Nidorina";
    pkmn["a7"] = "Nidorino";
    pkmn["53"] = "Ninetales";
    pkmn["b9"] = "Oddish";
    pkmn["06"] = "oltorb";
    pkmn["62"] = "Omanyte";
    pkmn["63"] = "Omastar";
    pkmn["22"] = "Onix";
    pkmn["6d"] = "Paras";
    pkmn["2e"] = "Parasect";
    pkmn["05"] = "pearow";
    pkmn["90"] = "Persian";
    pkmn["97"] = "Pidgeot";
    pkmn["96"] = "Pidgeotto";
    pkmn["24"] = "Pidgey";
    pkmn["54"] = "Pikachu";
    pkmn["1d"] = "Pinsir";
    pkmn["47"] = "Poliwag";
    pkmn["6e"] = "Poliwhirl";
    pkmn["6f"] = "Poliwrath";
    pkmn["a3"] = "Ponyta";
    pkmn["aa"] = "Porygon";
    pkmn["75"] = "Primeape";
    pkmn["2f"] = "Psyduck";
    pkmn["55"] = "Raichu";
    pkmn["a4"] = "Rapidash";
    pkmn["a6"] = "Raticate";
    pkmn["a5"] = "Rattata";
    pkmn["12"] = "Rhyhorn";
    pkmn["60"] = "Sandshrew";
    pkmn["61"] = "Sandslash";
    pkmn["1a"] = "Scyther";
    pkmn["5d"] = "Seadra";
    pkmn["9e"] = "Seaking";
    pkmn["3a"] = "Seel";
    pkmn["17"] = "Shellder";
    pkmn["25"] = "Slowpoke";
    pkmn["84"] = "Snorlax";
    pkmn["b1"] = "Squirtle";
    pkmn["98"] = "Starmie";
    pkmn["1b"] = "Staryu";
    pkmn["1e"] = "Tangela";
    pkmn["3c"] = "Tauros";
    pkmn["18"] = "Tentacool";
    pkmn["9b"] = "Tentacruel";
    pkmn["69"] = "Vaporeon";
    pkmn["77"] = "Venomoth";
    pkmn["41"] = "Venonat";
    pkmn["9a"] = "Venusaur";
    pkmn["be"] = "Victreebel";
    pkmn["bb"] = "Vileplume";
    pkmn["52"] = "Vulpix";
    pkmn["09"] = "Ivysaur";
    pkmn["b3"] = "Wartortle";
    pkmn["70"] = "Weedle";
    pkmn["bd"] = "Weepinbell";
    pkmn["8f"] = "Weezing";
    pkmn["65"] = "Wigglytuff";
    pkmn["4b"] = "Zapdos";
    pkmn["6b"] = "Zubat";
}


void SavEdit::printPkmnlist()
{
    /*
     * Print pokemon list
     */
    std::cout << "\n[Pokemon]\n" << std::endl;

    printf("%-18s%-18s%-18s%-18s%-18s%-18s%-18s\n","94: Abra","59: Dragonair","16: Gyarados","AD: Magnemite","97: Pidgeot","08: Slowbro","6B: Zubat");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","AB: Aerodactyl","42: Dragonite","93: Haunter","36: Magneton","96: Pidgeotto","25: Slowpoke");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","95: Alakazam","58: Dratini","2C: Hitmonchan","39: Mankey","24: Pidgey","84: Snorlax");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","2D: Arbok","30: Drowzee","2B: Hitmonlee","91: Marowak","54: Pikachu","05: Spearow");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","14: Arcanine","76: Dugtrio","5C: Horsea","4D: Meowth","1D: Pinsir","B1: Squirtle");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","4A: Articuno","66: Eevee","81: Hypno","7C: Metapod","47: Poliwag","98: Starmie");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","72: Beedrill","6C: Ekans","09: Ivysaur","15: Mew","6E: Poliwhirl","1B: Staryu");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","BC: Bellsprout","35: Electabuzz","64: Jigglypuff","83: Mewtwo","6F: Poliwrath","1E: Tangela");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","1C: Blastoise","8D: Electrode","68: Jolteon","49: Moltres","A3: Ponyta","3C: Tauros");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","99: Bulbasaur","0C: Exeggcute","48: Jynx","2A: Mr. Mime","AA: Porygon","18: Tentacool");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","7D: Butterfree","0A: Exeggutor","5A: Kabuto","88: Muk","75: Primeape","9B: Tentacruel");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","7B: Caterpie","40: Farfetch'd","5B: Kabutops","07: Nidoking","2F: Psyduck","69: Vaporeon");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","28: Chansey","23: Fearow","26: Kadabra","10: Nidoqueen","55: Raichu","77: Venomoth");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","B4: Charizard","67: Flareon","71: Kakuna","03: Nidoran(M)","A4: Rapidash","41: Venonat");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","B0: Charmander","19: Gastly","02: Kangaskhan","0F: Nidoran(F)","A6: Raticate","9A: Venusaur");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","B2: Charmeleon","0E: Gengar","8A: Kingler","A8: Nidorina","A5: Rattata","BE: Victreebel");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","8E: Clefable","A9: Geodude","37: Koffing","A7: Nidorino","01: Rhydon","BB: Vileplume");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","04: Clefairy","BA: Gloom","4E: Krabby","53: Ninetales","12: Rhyhorn","06: Voltorb");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","8B: Cloyster","82: Golbat","13: Lapras","B9: Oddish","60: Sandshrew","52: Vulpix");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","11: Cubone","9D: Goldeen","0B: Lickitung","62: Omanyte","61: Sandslash","B3: Wartortle");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","78: Dewgong","80: Golduck","7E: Machamp","63: Omastar","1A: Scyther","70: Weedle");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","3B: Diglett","31: Golem","29: Machoke","22: Onix","5D: Seadra","BD: Weepinbell");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","4C: Ditto","27: Graveler","6A: Machop","6D: Paras","9E: Seaking","8F: Weezing");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","74: Dodrio","0D: Grimer","85: Magikarp","2E: Parasect","3A: Seel","65: Wigglytuff");
    printf("%-18s%-18s%-18s%-18s%-18s%-18s\n","46: Doduo","21: Growlithe","33: Magmar","90: Persian","17: Shellder","4B: Zapdos");
}

void SavEdit::printMovelist()
{
    /*
     * Print move options.
     */
    std::cout << "\n[Moveset]\n" << std::endl;

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
    /*
     * The main state for the user to make edits to their party.
     */

    bool safe = false;
    int stat_val_offset;

    std::cout << " 1: Hitpoints\n";
    std::cout << " 2: Level\n";
    std::cout << " 3: Attack\n";
    std::cout << " 4: Defense\n";
    std::cout << " 5: Speed\n";
    std::cout << " 6: Special\n";
    std::cout << " 7: MOVE 1\n";
    std::cout << " 8: MOVE 2\n";
    std::cout << " 9: MOVE 3\n";
    std::cout << " 0: MOVE 4\n";
    std::cout << "10: Pokemon\n" << std::endl;

    while(!safe)
    {
        std::cin >> stat_val_offset;

        switch(stat_val_offset)
        {
            case 1:
                stat_val_offset = 0x2B; // NOTE: 0x0A is CURRENTLY HP
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
            case 10:
                stat_val_offset = 0x01;
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

    int party_member = 0;

    // Create the pkmn name map
    pkmnMap(); 

    //TODO: Display party list + stats

    std::cout << "Select party member: " << std::endl;

    while((party_member > 6) || (party_member < 1))
    {
        std::cin >> party_member;

        if((party_member > 6) || (party_member < 1))
        {
            std::cout << "wrong input. Try again." << std::endl;
        }
    }

    // Zero-indexed update
    party_member-=1;

    // Display party member being edited.
    // First we need to convert deci -> hex before searching.
    std::stringstream mem_to_hex;
    // The addr has to be hard coded.
    mem_to_hex << std::hex << mem.at(0x2F2C + (party_member +0x01));
    // Convert to a string.
    std::string char_loc(mem_to_hex.str());
    std::cout << "[EDITING: " << pkmn[char_loc] << "]" << std::endl;

    // Get the stat address
    stat_val_offset = selectStat();

    // The party member attribute block is +44 times its party position
    // with an exception for the pkmn id.
    party_member_offset = 44 * party_member;

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
    }else if (stat_val_offset == 0x01){
        // The only value not in the +44(n-1), where n is party pos, block is
        // the pkmn id.
        party_member_offset = party_member;
        printPkmnlist();
        // Pokemon list requires hex.
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

    // Start of memory block for the party 
    int party_offset = 0x2F2C;

    // Final memory address to edit.
    int mem_to_edit;

    // jump to proper memory
    mem_to_edit = party_offset + party_member_offset + stat_val_offset;

    // Edit that memory.
    mem.at(mem_to_edit) = state_value;

}
