#include <iostream>

#include "SavEdit.h"

void SavEdit::setLang(int i)
{
    /*
     * Set the language.
     */
    lang = i;
}

void SavEdit::greeting()
{
    /*
     * Greet the user in their language of choice.
     */
    switch(lang)
    {
        case en_US:
            std::cout << "Hello." << std::endl;
            break;
        case ie_gle:
            std::cout << "dia duit." << std::endl;
            break;
        case ja_jp:
            std::cout << "こんにちは" << std::endl;
            break;
        default:
            std::cout << "Something went wrong." << std::endl;
            break;
    }
}
void SavEdit::languageForm()
{
    /*
     * Allow the user to switch to their preferred language.
     */
    int selection = 0;

    std::cout << "Language selection:\n";
    std::cout << "\t0. American English.\n";
    std::cout << "\t1. Gaelige\n";
    std::cout << "\t2. 日本語\n";
    std::cout << std::endl;

    std::cout << "Language: ";
    std::cin >> selection;

    setLang(selection);

}

void SavEdit::textOT()
{
    /*
     * Template subroutine to add language support.
     */
    switch(lang)
    {
        case en_US:
        case ie_gle:
        case ja_jp:
        default:
            std::cout << "OT: ";
            break;
    }
}
