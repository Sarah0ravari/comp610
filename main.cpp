//This is the body of our program
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    // Declare file obj
    ifstream dataFile;
    string name, filename;

    cout << "Opening file ....\n";
    cout << "Please enter the name of your input file: ";
    cin >> filename;

    dataFile.open(filename);
    if(!dataFile)
    {
        cout << "I can't find the input file" << endl;
        exit(-1);
    }

    cout << "The names in the file are: "<<endl;

    cout<< "Done. \n";
    return 0;
}
