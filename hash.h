#ifndef HASH_H
#define HASH_H
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
namespace Hash_table{


class hash{
    public:
        hash();
        int Hash(string key); //Index of hash table 
    //Take a string and stores it in that key value, and change it into a integer number that represents where in the hash table we'll store that key
        void AddItem(string name, string college);
    //Stores the name of the people and their college
        int NumberOfItemsInIndex(int index);
    //Counts the number of buckets and counts the number of items that is in that location
        void PrintTable();
    //tell us what is contained in the first items of each bucket and how much does it contain
        void PrintItemsInIndex (int index);
    //the value being passed in will be the index that we want to print the items out of
        void FindCollege(string name); 
    //Determine if that's person's name is in the table and the college they go to
        void RemoveItem(string name);
    //Will remove the item contained in the has table 


    private:
    static const int tableSize = 25; //I just am starting off with a small hash table 
    struct item{ //defined the item and what it contains
        string name; //person's name
        string college; //person's college
        item* next; //pointer to teh next item
    };
    item* HashTable[tableSize]; //Core of our hash table which is just an array with the size.
};

}
#endif /* HASH_H */