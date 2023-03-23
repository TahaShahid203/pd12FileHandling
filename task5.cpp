#include <iostream>
#include <fstream>
using namespace std;
string parseLine(string word, int count, char separator);
string readDataFromFile(int numberOfOrders, int minimumPrice);
main()
{
    int numberOfOrders, minimumPrice;

    cout << "Enter minimum number of orders: ";
    cin >> numberOfOrders;
    cout << "Enter minium price: ";
    cin >> minimumPrice;
    readDataFromFile(numberOfOrders, minimumPrice);
}

string parseLine(string word, int count, char separator)
{
    int spaceCount = 1;
    string answer = "";
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == separator)
        {
            spaceCount++;
            continue;
        }
        if (word[i] == '[' || word[i] == ']')
        {
            continue;
        }
        if (spaceCount == count)
        {
            answer += word[i];
        }
    }
    return answer;
}

string readDataFromFile(int numberOfOrders, int minimumPrice)
{
    int orderCount = 0;
    string data;
    int arraySize;
    string name;
    fstream fileName;
    fileName.open("Customer.txt", ios::in);
    while(!fileName.eof())
    {
        getline(fileName, data);
        arraySize = stoi(parseLine(data, 2, ' '));
        int arrayOfPizzaPrices[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            arrayOfPizzaPrices[i] = stoi(parseLine(parseLine(data, 3, ' '), i+1, ','));
        }
        for (int i = 0; i < arraySize; i++)
        {
            if (arrayOfPizzaPrices[i] >= minimumPrice)
            {
                orderCount++;
            }
        }
        if (orderCount >= numberOfOrders)
        {
            cout << parseLine(data, 1, ' ') << endl;
        }
    }
    fileName.close();
}