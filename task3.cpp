#include <iostream>
#include <fstream>
using namespace std;

string encryptToMorseCode(string line);
void storeAnswerInFile(string line);
main()
{
    string line, answer;
    cout << "Enter string that you want to encrypt: ";
    getline(cin, line);

    answer = encryptToMorseCode(line);
    storeAnswerInFile(answer);
}
string encryptToMorseCode(string line)
{
    string answer = "";
    string morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == 32)
        {
            answer += "-.-.-.- ";
            continue;
        }
        answer += morseCode[line[i] - 97] + " ";
    }
    return answer;
}
void storeAnswerInFile(string line)
{
    fstream file;
    file.open("encrypt.txt", ios::out);
    file << line;
    file.close();
}