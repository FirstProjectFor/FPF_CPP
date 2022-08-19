#include <fstream>
#include <iostream>

using namespace std;

int main() {
  try {
    string tempFile = "temp_data.txt";
    int dataSize = sizeof(char) * 10;
    char* tempData = (char*)malloc(dataSize);
    char* tempReadData = (char*)malloc(dataSize);

    //读文件
    ofstream outputFile;
    outputFile.open(tempFile, ios::trunc);

    cout << "Please Input data:" << endl << endl;
    cin.getline(tempData, dataSize);
    cout << "You Input Data is:" << endl << tempData << endl;

    outputFile << tempData;

    outputFile.close();
    //写文件

    ifstream inputFile;
    inputFile.open(tempFile);
    inputFile.read(tempReadData, dataSize);

    cout << "Read  data from file:" << endl
         << "Data:" << endl
         << tempReadData << endl;

    inputFile.close();
  } catch (exception* e) {
    cout << e->what() << endl;
  }

  return 0;
}