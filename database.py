'''
Programmer's Name: Ashton
Contact info: [HIDDEN]
Date Created: Nov 20, 2023
Version: 1.0.0
Purpose: CRUD for editing the database.
ISSUES: None noticed at the moment.
'''
import mysql.connector
import sys

# CHANGE AS NEEDED
HOST="localhost"
USER="root"
PASSWD=""
DATABASE="pokemon"
TABLE = "pkmn"

# This connects to the database
database = mysql.connector.connect(host=HOST,user=USER,password=PASSWD,database=DATABASE)
selection = database.cursor()



# Populate the database
def mk():
    '''
    Creates the database and table.
    '''
    selection.execute("CREATE DATABASE pokemon")
    selection.execute("CREATE TABLE pkmn (hex VARCHAR(2), name VARCHAR(255))")

# CREATE
def CREATE(one, two, val_one, val_two):
    '''
    This creates an entry, inserting it into the given table using the
    column names (one, two) and the values (val_one, val_two).
    '''
    command = "INSERT INTO " + TABLE + " (" + one + "," + two + ") VALUES (%s, %s)"
    values = (val_one, val_two)
    selection.execute(command, values)
    database.commit()
    print(selection.rowcount,"record inserted.")
    exit

# READ
def READ(column, val):
    '''
    Finds all entries of a given value from a given colum.
    '''
    command = "SELECT * FROM " + TABLE + " WHERE " + column + " = '" + val + "'"
    selection.execute(command)
    results = selection.fetchall()
    for x in results:
        print(x)
    exit

# UPDATE
def UPDATE(fix_col, fix_val, location, val):
    '''
    Corrects an entry from at a given value with a given coumn
    '''
    command = "UPDATE " + TABLE + " SET " + fix_col + " = '" + fix_val + "' WHERE " + location + " = '" + val + "'"
    selection.execute(command)
    database.commit()
    print(selection.rowcount, "record(s) modified.")
    exit

# DELETE
def DELETE(column, val):
    '''
    Removes an entry based on the given column and respective value.
    '''
    command = "DELETE FROM " + TABLE + " WHERE " + column + " = '" + val + "'"
    selection.execute(command)
    database.commit()
    print(selection.rowcount, "record(s) deleted.")
    exit

if sys.argv[1] == "CREATE":
    user_hex = sys.argv[2]
    user_name = sys.argv[3]
    CREATE("hex", "name", user_hex, user_name)

if sys.argv[1] == "READ":
    user_col = sys.argv[2]
    user_val = sys.argv[3]
    READ(user_col, user_val)

if sys.argv[1] == "UPDATE":
    user_col = sys.argv[2]
    user_val = sys.argv[3]
    user_loc = sys.argv[4]
    user_loc_val = sys.argv[5]
    UPDATE(user_col, user_val, user_loc, user_loc_val)

if sys.argv[1] == "DELETE":
    user_col = sys.argv[2]
    user_val = sys.argv[3]
    DELETE(user_col, user_val)


