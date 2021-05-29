// Halit Burak Yeşildal 18050111043

#include <iostream>
#include <vector>
#include <fstream>
#include "Animal.h"
#include "Eagle.h"

using namespace std;


//split method is created return type is a vector<string>
vector<string> split( string line = NULL){
    int size = line.length(),begin=0;
  
    vector<string> splitted;
    for (int i = 0; i < size; i++)
        if(line[i]==','){
            splitted.push_back(line.substr(begin, i - begin));
            begin = i + 1;
        }

    splitted.push_back(line.substr(begin, size-begin));

    return splitted;
}

//boolean parser
inline bool boolParse(string input = NULL) {
    return input == ("true");
   
}

//sorting vector
void sortVector(vector<Eagle*> &vectorEagle) {
    for (int i = 0; i < vectorEagle.size(); i++) 
        for (int j = 0; j < vectorEagle.size(); j++) 
            if (*vectorEagle[i] < *vectorEagle[j]) 
                swap(vectorEagle[i], vectorEagle[j]);

}



int main()
{
    //8. Main function will ask user to enter an integer number. And according to this number your program will create an array with type of subclass dynamically.
    //Note: This is array never used.
     
    int sizeArray;
    cout << "Enter the size of the Array" << endl;
    cin >> sizeArray;

    Eagle* eagleArray = new Eagle[sizeArray];
    

    //Vector created 
    vector<Eagle*> eagleVector;

    //File operations has begun
    string line;


    try
    {
        ifstream file;
        file.open("input.txt");
        //if there is an error related with the file it'll throw it.
        if (!file.is_open())
            throw exception();

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

       
            
            
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        cout << "It's a file error chech your file!!" << endl;
    }



   
    sortVector(eagleVector);

    //proof of the sorting and details.
    for (Eagle* e : eagleVector)
        e->printDeatils();


    //proof of the operator overloading.      
    for (int i = 0; i < eagleVector.size() - 1; i++) {

        cout << "The sum of weights : " + eagleVector[i]->getName() + " and " + eagleVector[i + 1]->getName() + " is :" << endl;
        cout.precision(10);
        cout << *eagleVector[i] + *eagleVector[i + 1];


        cout << "\nThe sum of ages : " + eagleVector[i]->getName() + " and " + eagleVector[i + 1]->getName() + " is :" << endl;
        cout << to_string(*eagleVector[i] - *eagleVector[i + 1]) << endl;
        cout << "#######" << endl;
    }



    return 0;
}


