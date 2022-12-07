#include <iostream>
#include <string.h>
using namespace std;



class MethodHT {    
    
public:   
    struct node
    {
        string value = "";
        node* next = NULL;
    };

    int bucket_size = 10007;
    const int prime_number = 29;
    node* nodeArray;

    //set the bucket size of the hash table
    NewHashTable(int new_bucket_size) {
        bucket_size = new_bucket_size;
        nodeArray = new node[bucket_size];
    }
    
    //calculate hash value using polynomial rolling hash function
    //set the bucket size of the hash table as the divisor
    int hashFunction(string word)
    {
        int hash_value = 0;
        long power = 1;
        const int n = word.length();
        for (int i = 0; i < n; ++i) {
            hash_value = (hash_value + (word[i] - 'a' + 1) * power) % bucket_size;
            power = (power * prime_number) % bucket_size;
        }
        return hash_value;
    }

    //load the words into the hash table. 
    void loadhashtable(string loadWord) 
    {
        int index = hashFunction(loadWord);
        if(nodeArray[index].value=="") 
        {
            nodeArray[index].value = loadWord;
            return;
        }
        
        node* tempNode = new node();
        tempNode->value = nodeArray[index].value;
        tempNode->next = nodeArray[index].next;
        nodeArray[index].value = loadWord;
        nodeArray[index].next = tempNode;
    }

    //search the word in the hash table
    int search(string searchWord) {
        int index = hashFunction(searchWord);
        node* ptr = &nodeArray[index];
        while(ptr!=NULL)
        {
            if(ptr->value.compare(searchWord)==0)
                return 1;
            ptr = ptr->next;
        }
        return 0;
    }

};

int main()
{
    MethodHT obj;
    string input_word1="abcdef";
    string input_word2="abcdeg";
    string input_word3="abcdeh";
    string input_word4="abcdei";
	string search_word1="abcdef";
    string search_word2="abcdei";
    string search_word3="abcdej";
    int bucket_size = 10007;//use 3 can test the search on the same hash value
   
    obj.NewHashTable(bucket_size);
    obj.loadhashtable (input_word1);
    obj.loadhashtable (input_word2);
    obj.loadhashtable (input_word3);
    obj.loadhashtable (input_word4);
     

    cout << obj.search(search_word1) << endl;
    cout << obj.search(search_word2) << endl;
    cout << obj.search(search_word3) << endl;

}