#ifndef SAVEDIT_H
#define SAVEDIT_H

#include <iostream>
#include <vector>
#include <map>

class SavEdit
{
    public:
        SavEdit();
        void open();
        void read();
        void save(std::string fname);
        std::string getFilename();
        void setFilename(std::string fname);
        void backup();
        int checksum();        
        int convert(char given);
        void modMem(int offset, char val);
        void saveNewFile();
        void setLang(int i);
        void greeting();
        void languageForm();
        void textOT();
        void modify(const int BEGIN, const int END);
        void cashModify();
        bool select();
        void clear();
        void debug();
        void displayItems();
        void pkmnMap();
        void moveMap();
        void printPkmnlist();
        void printMovelist();
        int selectStat();
        void modMainMenu();
        void modStats(int, int);
        void printParty();
        void printStats(int);
        void printMoves(int);
    private:
        std::string filename;
        std::vector<int> mem;
        enum language{en_US=0, ie_gle=1, ja_jp=2};
        int lang;
        int m_changes = 0;
        std::map<std::string, std::string> pkmn;
        std::map<std::string, std::string> move;
};

#endif
