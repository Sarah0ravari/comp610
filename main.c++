//This is the body of our program
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class node{
	public:
		string data; 
		node* left;
		node* right;
		node(string d, node* l = NULL, node* r = NULL){
			data = d;
			left = l;
			right = r;
		}
};

class bst{
    public :
    node* head;
    bool search(node* bstNode, string word)
    {
        if (bstNode == null)
            return false;
        if(bstNode->data == word)
            return true;
        if(bstNode->data > word)
            return search(bstNode->left, word);
        else if (bstNode->data < word)
            return search(bstNode->right, word);
    }

    void insert(node* bstNode ,string word){
		if(bstNode == NULL){
			bstNode = new node(word);
		}

		if(word < bstNode->data){
			bstNode->left = insert(bstNode->left, word);
		}
		else{
			bstNode->right = insert(bstNode->right, word);
		}
	}
};

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
