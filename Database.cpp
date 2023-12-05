/* Programmer's name: Ashton
 * Contact info: [HIDDEN]
 * Date Created: Nov 20, 2023
 * Version: 1.0.0
 * Purpose: Handles the python-C++ connection
 * Issues: None noticed at the moment
 *
 */
#include <iostream>
#include <cstdlib>
#include <cstring>

void Create(std::string hex, std::string val)
{
    /*
     * Calls the python file to insert the given values into the MySQL
     * database.
     */
    std::string cmd = "python database.py CREATE ";
    cmd += hex;
    cmd += " ";
    cmd += val;

    system(cmd.c_str());
}

void Read(std::string col, std::string val)
{
    /*
     * Find and print out searched val in a given col.
     */
    std::string cmd = "python database.py READ ";
    cmd += col;
    cmd += " ";
    cmd += val;

    system(cmd.c_str());
}

void Update(std::string u_col, std::string u_val, std::string u_loc, std::string u_loc_val)
{
    /*
     * Update column (u_col) with new value (u_val) at a given location (u_loc)
     * that contains the value u_loc_val.
     */
    std::string cmd = "python database.py UPDATE ";
    cmd += u_col;
    cmd += " ";
    cmd += u_val;
    cmd += " ";
    cmd += u_loc;
    cmd += " ";
    cmd += u_loc_val;

    system(cmd.c_str());
}

void Delete(std::string col, std::string val)
{
    /*
     * Deletes an entry with a given value at a given column.
     */
    std::string cmd = "python database.py DELETE ";
    cmd += col;
    cmd += " ";
    cmd += val;

    system(cmd.c_str());
}


int main()
{
    /*
     * This is a test file, I will connect it to the program later,
     * but for now it's just going to be it's own separate file.
     */

    // Tested each of the below. It works fine.
    //Create("95", "Alakazam");
    //Read("hex", "95");
    //Update("name", "alakazam", "hex", "95");
    //Delete("hex", "95"); 

    // TODO: I should probably put Read into a variable.

    return 0;
}
