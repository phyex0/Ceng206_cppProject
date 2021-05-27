// Ceng206_cppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <fstream>
#include "Animal.h"
#include "Eagle.h"

//split method is created return type is a vector<string>
vector<string> split( string line){
    //"abc,bcd,def"
    int size = line.length(),begin=0;
  
    vector<string> splitted;
    for (int i = 0; i < size; i++){
        if(line[i]==','){
            splitted.push_back(line.substr(begin, i - begin));
            begin = i + 1;
        }

    }

    splitted.push_back(line.substr(begin, size-begin));

    return splitted;
}

//boolean parser
bool boolParse(string input) {
    if (input._Equal("true"))
        return true;
    else
        return false;
}


void sortVector(vector<Eagle*> &vectorEagle) {
    Eagle* temp;
    for (int i = 0; i < vectorEagle.size(); i++) {
        for (int j = 0; j < vectorEagle.size(); j++) {
            if (*vectorEagle[i] < *vectorEagle[j]) {
                swap(vectorEagle[i], vectorEagle[j]);

            }
        }
    }
}

using namespace std;

int main()
{
    //8. Main function will ask user to enter an integer number. And according to this number your program will create an array with type of subclass dynamically.
    //Note: This is array never used.
     /*
    int sizeArray;
    cout << "Enter the size of the Array" << endl;
    cin >> sizeArray;

    Eagle* eagleArray = new Eagle[sizeArray];
    */

    //Vector created 
    vector<Eagle*> eagleVector;

    //File operations has begun
    string line;
    ifstream file;
    file.open("input.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            vector<string> splittedData = split(line);
            if (splittedData.size() == 5) {
                Eagle* e = new Eagle(splittedData[0], stoi(splittedData[1]), stod(splittedData[2]), boolParse(splittedData[3]), boolParse(splittedData[4]));
                eagleVector.push_back(e);
            }
            splittedData.clear();

            

        }
        file.close();

        sortVector(eagleVector);
       
        for (Eagle* e : eagleVector)
            e->printDeatils();
    }
    else
        cout << "File couldn't open" << endl;
    
    

  




    return 0;
}


