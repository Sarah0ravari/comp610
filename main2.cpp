//This is the body of our program (with user input)
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
    
    
    cout <<"Type a word: "; 
    cin >> name;
    
    while (dataFile >> name)
    {
       // obj.NewHashTable
       //obj.loadhashtable (name); 
       
       //cout << obj.search(name) << endl; 
    }
    
    return 0; 
}
