#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
void findMissingLetters(string word);
void writeMissingLetterInFile(char letter);
main()
{
    string word;
    fstream fileName;
    fileName.open("alphabets.txt", ios::in);
    getline(fileName, word);
    fileName.close();
    fileName.open("alphabets.txt", ios::app);
    fileName << endl;
    fileName.close();
    findMissingLetters(word);
}
void findMissingLetters(string word)
{
    bool letterFound = false;
    for (int i = 97; i < 123; i++)
    {
        for (int j = 0; j < word.length(); j++)
        {
            if (char(i) == word[j])
            {
                letterFound = true;
                break;
            }
        }
        if (letterFound)
        {
            letterFound = false;
            continue;
        }
        else
        {
            writeMissingLetterInFile(char(i));
        }
    }
}

void writeMissingLetterInFile(char letter)
{
    fstream fileName;
    fileName.open("alphabets.txt", ios::app);
    fileName << letter;
    fileName.close();
}