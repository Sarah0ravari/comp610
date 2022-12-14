
#include <iostream>
#include<fstream>
#include <string.h>
#include <sys/time.h>
#include <ctime>
#include <bits/stdc++.h>

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

using namespace std;

struct BSTNode /// BinarySearchTreeNode
{

string value;
BSTNode* left = NULL;
BSTNode* right = NULL;
};

class BST // BinarySearchTree
{
private:
BSTNode* root ;

public:
BST (){ root = NULL;}
struct BSTNode* insert(struct BSTNode* Node , struct BSTNode*newNode)
{
if (Node == NULL) return newNode;

if (newNode->value< Node->value)
Node->left = insert(Node->left, newNode);
else if (newNode->value > Node->value)
Node->right = insert(Node->right, newNode);

return Node;
}
void insert(string value)
{
struct BSTNode* newNode = new BSTNode;
newNode->value = value;
newNode->left = NULL;
newNode->right = NULL;
root = insert(root , newNode);
}
/// ------------------------------------------
struct BSTNode*findmin(struct BSTNode*tree){
while(tree->left){
tree=tree->left;
}
return tree;
}
BSTNode*remove(struct BSTNode*tree, string value){
BSTNode*temp;
if(!tree)return NULL;
else if(tree->value<value)tree->right=remove(tree->right,value);
else if(tree->value>value)tree->left=remove(tree->left,value);
else if(tree->value==value){
if(!tree->left){
temp=tree->right;
delete(tree);
return temp;
}
if(!tree->right){
temp=tree->left;
delete(tree);
return temp;
}
temp=findmin(tree->right);
tree->value=temp->value;
remove(tree->right,temp->value);
}
else
cout<<"key not found\n";


return tree;
}
void remove(string value)
{
root= remove(root,value);
}
/// ------------------------------------------

/// ------------------------------------------
void inOrderTraversal() const
{
//cout << "inOrderTraversal: ";
inOrderTraversal(root);
//cout << endl;
}
void inOrderTraversal(BSTNode* node) const
{
if (node != NULL) {
inOrderTraversal(node->left);
//cout << node->value << " ";
inOrderTraversal(node->right);
}
}
/// ------------------------------------------
bool searchRec(BSTNode* root, string key , int &count)
{ count++;
if (root == NULL)return false;
if(root->value == key) return true;
if (root->value < key) return searchRec(root->right, key,count);
return searchRec(root->left, key,count);
}


bool search(string key){
int count=0;
bool found = searchRec(root , key , count);
cout<<"Number of element inspected : "<<count<<endl;
return found;
}

};

int main()
{
BST bst;
int n;
string search_word;
ifstream in;
double load_time; 
double search_time; 
string filename;
cout<<"Enter file name : ";
cin>>filename;
in.open(filename.c_str());
auto load_starttime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        

if(!in){
cout<<"File not opened\n";
exit(1);
}

auto load_endtime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        cout << "Finish loading the txt File" << endl;
        cout <<"Load start time: "<< load_starttime << endl;
        cout << "Load end time: "<<load_endtime << endl;
        load_time = double(load_endtime - load_starttime);
        cout << "Load time: " << load_time << endl;

while(!in.eof()){
in>>search_word;
bst.insert(search_word);

}

bst.inOrderTraversal();

cout<<"\n\nEnter number of words you want to serach in Binary search tree : ";
cin>>n;
for(int i=0;i<n;i++){
cout<<"enter word to search : ";
cin>>search_word;

auto search_starttime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
if(bst.search(search_word))cout<<search_word <<" Found in Binary search tree\n";

else cout<<search_word <<" Not found in Binary search tree\n";

exit(1); 

}

auto search_endtime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        
        cout << "Search start time: " <<search_starttime << endl;
        cout << "Search end time: " <<search_endtime << endl;
        search_time = double(search_endtime - search_starttime);
        cout << "Search time: " <<search_time << endl;

in.close();
return 0;
}
