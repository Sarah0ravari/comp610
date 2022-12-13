#include <iostream>
#include <string.h>
#include <fstream>
#include <sys/time.h>
#include <ctime>
#include <bits/stdc++.h>


using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

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
        nodeArray = new node[new_bucket_size];
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
    int hashtable_bucket = 10007;//use 3 can test the search on the same hash value

    // the string address below is for user to input the file address
    string address = "C://Users/1000.txt";
    double load_time;
    double search_time;
    string file_line;
    string search_word;
    MethodHT obj;

    obj.NewHashTable(hashtable_bucket);

    ifstream loadFile(address);
    if(loadFile.is_open())
    {
        cout << "Start loading the txt File" << endl;
        auto load_starttime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        
        while(getline(loadFile, file_line))
        {
            obj.loadhashtable (file_line);
        }
        loadFile.close();

        
        auto load_endtime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        cout << "Finish loading the txt File" << endl;
        cout <<"Load start time: "<< load_starttime << endl;
        cout << "Load end time: "<<load_endtime << endl;
        load_time = double(load_endtime - load_starttime);
        cout << "Load time: " << load_time << endl;
        
        while(true)
        {
		    cout<<"Please enter the word to search. TYPE 'QUIT' to quit the program"<<endl;
		    cin>>search_word;
            if(search_word.compare("QUIT")==0)
            {
                exit(1);
            }
        auto search_starttime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            if(obj.search(search_word)==1) 
            {
                cout << "The word exists" <<endl;
            }
            else
            {
                cout << "The word does not exist" <<endl;
            }
        auto search_endtime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        
        cout << "Search start time: " <<search_starttime << endl;
        cout << "Search end time: " <<search_endtime << endl;
        search_time = double(search_endtime - search_starttime);
        cout << "Search time: " <<search_time << endl;
        }
    }
    else
    {
        cout<< "File address is invalid" << endl;
        exit(1);
    }
}