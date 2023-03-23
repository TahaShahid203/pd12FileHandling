#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

string readDataFromFile(string word, int field);

bool validateAge(string age);
void showBirthdayCake(string age, string name);

main()
{
    string word;
    fstream fileName;
    fileName.open("names.txt", ios::in);
    getline(fileName, word);
    fileName.close();
    string age = readDataFromFile(word, 2);
    string name = readDataFromFile(word, 1);
    showBirthdayCake(age, name);
}

void showBirthdayCake(string age, string name)
{
    char symbol;
    int ageNumber;
    if (validateAge(age))
    {
        ageNumber = stoi(age);
        
        if (ageNumber % 2 == 0)
        {
            symbol = '#';
        }
        else
        {
            symbol = '*';
        }
        for (int i = 0; i < 15; i++)
        {
            cout << symbol;
        }
        cout << endl;
        cout << symbol << " " << age << " HB " << name << "! " << age << " " << symbol << endl;
        for (int i = 0; i < 15; i++)
        {
            cout << symbol;
        }
    }
}
bool validateAge(string age)
{
    bool flag = true;
    for (int i = 0; i < age.length(); i++)
    {
        if (age[i] < 48 || age[i] > 57)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

string readDataFromFile(string word, int field)
{
    string temporary = "";
    int commaCount = 1;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            temporary += word[i];
        }
    }
    return temporary;
}
