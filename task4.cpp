#include <iostream>
#include <fstream>
using namespace std;
string readDataFromFile();
string readInformationFromData(string dataLine);
main()
{
    string uselessData;
    uselessData = readDataFromFile();
    string usefulInformation;
    usefulInformation = readInformationFromData(uselessData);
    cout << usefulInformation << endl;
}

string readDataFromFile()
{
    string uselessData;
    fstream fileName;
    fileName.open("uselessData.txt", ios::in);
    getline(fileName, uselessData);
    fileName.close();
    return uselessData;

}
string readInformationFromData(string dataLine)
{
    bool readStatus = false;
    string answer = "";
    for (int i = 0; i < dataLine.length(); i++)
    {
        if (dataLine[i] == '"')
        {
            readStatus = !readStatus;
            continue;        // to avoid the first quotation mark
        }
        if (readStatus)
        {
            answer += dataLine[i];
        }
    }
    if (answer == "")
    {
        answer = "What...why did you make this?";
    }
    return answer;
}