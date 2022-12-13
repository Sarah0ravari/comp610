//This is the body of our program
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node {
   int word;
   struct node *leftChild;
   struct node *rightChild;   
};

struct node* search(node* root, int word){
   struct node *current = root;
   printf("Visiting elements: ");
	
   while(current->word != word){
	
      if(current != NULL) {
         printf("%d ",current->word);
			
         //go to left tree
         if(current->word > word){
            current = current->leftChild;
         }//else go to right tree
         else {                
            current = current->rightChild;
         }
			
         //not found
         if(current == NULL){
            return NULL;
         }
      }			
   }
   return current;
}

void insert(node* root,int word) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->word = word;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) {                
         parent = current;
			
         //go to left of the tree
         if(word < parent->word) {
            current = current->leftChild;                
            //insert to the left
				
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;
            
            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
} 

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

    cout << "The name in the file is: "<<endl;

    cout<< "Done. \n";
    return 0;
}

