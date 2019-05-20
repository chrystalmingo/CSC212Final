#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;
namespace Hash_table{
hash::hash(){
    for(int i = 0; i < tableSize; i++){
        //All of these are the defaults
        HashTable[i] = new item; //run i times thru the table making a new item each time
        HashTable[i]->name = "empty"; //name is orginally empty in the hash table
        HashTable[i]->college = "empty"; //college is empty at first
        HashTable[i]->next = NULL;
    };
}
void hash::AddItem(string name, string college){
    int index = Hash(name);//hold the location in the hash table that stores the int of that string
    if(HashTable[index]->name == "empty"){ //over writing
        HashTable[index]->name = name;
        HashTable[index]->college = college;

    }
    else {
        item* Ptr = HashTable[index]; //point to the begginning of that table
        item* n = new item; //Adding new item with name & drink
        n->name = name;
        n->college = college;
        n->next = NULL; //make the next item point to NULL;
        while(Ptr->next != NULL){//will make the pointer transverse till the end of the list/hashTable
            Ptr = Ptr->next;
        }
        Ptr->next = n; //links the last item in that list with the new item in the hash table
    }
}
int hash::NumberOfItemsInIndex(int index){
    int count = 0; //initialize the counter at 0
    if(HashTable[index]->name == "empty"){ //if we haven't put anything in then return the default
         return count;
    }
    else{
        count ++; //incrementing count
        item *Ptr = HashTable[index]; //point to beginning of the list
        while(Ptr->next != NULL){ //As long as the next pointer is not empty
            count ++;//increment as long as something is attached
            Ptr = Ptr->next;//continue to transe to the next
        }
    }

}
void hash::PrintTable(){//Will Print out all the information in the HashTable
    int number; //hold the num of elements in each buckets
    for(int i =0; i < tableSize; i++){
        number = NumberOfItemsInIndex(i);
        cout <<"------------------\n";
        cout<<"index = " << i << endl;
        cout<<HashTable[i]->name<<endl;
        cout<<HashTable[i]->college<<endl;
        cout<<"# of Items = "<<number<<endl;
        cout <<"-----------------\n";
    }
}
void hash::PrintItemsInIndex(int index){
    item* Ptr = HashTable[index]; //points to the first item in the bucket/hash table
    if(Ptr->name == "empty"){
        cout<<"index = "<< index << " is empty"<< endl;
    }
    else{
        cout <<"index = "<<index<< "contains the following items"<<endl;
        while(Ptr != NULL){
             cout <<"------------------\n";
             cout<<Ptr->name<< endl;
             cout<<Ptr->college<<endl;
             cout <<"------------------\n";
             Ptr = Ptr->next;
        }
    }

}
void hash::FindCollege(string name){
    int index = Hash(name);
    bool foundName = false; //Name not found
    string college;
    item* Ptr = HashTable[index]; //pointing to the first item in the bucket
    while (Ptr!= NULL){
        if(Ptr->name == name){
            foundName = true;
            college = Ptr->college;
        }
        Ptr = Ptr->next;
    }
    if(foundName == true){
        cout<<"College = "<<college<<endl;
    }
    else{
        cout<< name <<" not found in the hash table"<<endl;
    }

}
int hash::Hash(string key){
   int hash = 0;
   int index;
   index = key.length(); //index is represented by the lenght of the string
   for (int i = 0; i< key.length(); i++){ //Adds up all the characters in the string 
       hash = hash + (int)key[i];
    }
    //key[0]; would print the first letter of the string
    //now when you do (int)key[0 or any other index] you get the integer that represents that number
    index = hash % tableSize;
    //example if key total = 402 / 100(table size) = 4 r 2 and you store that remainder value as the index in the hash table


   return index;
}
void hash::RemoveItem(string name){
    int index = Hash(name);
    item* delPtr;
    item* P1;
    item* P2;
    //Case 0 (where the bucket is empty)
    if(HashTable[index]->name == "empty" && HashTable[index]->college == "empty" ){
        cout<<name<<" was not found in the hash table"<<endl;
    }
    //Case 1 (Only 1 item contained in bucket and that item has matching name)
    //if name in item is equal to name were looking for then & the next item is NULL (ONLY ONE ITEM IN BUCKET)
    //reseted to default values
    else if (HashTable[index]->name == name && HashTable[index]->next == NULL){
        HashTable[index]->name = "empty";
        HashTable[index]->college = "empty";
        cout<<name<<" was removed from the hash table"<<endl;
    }
    //Case 2 (Match is located in teh first item in the bucket but there are more items in the bucket)
    else if (HashTable[index]->name == name){
        delPtr = HashTable[index]->name == name; 
        HashTable[index] = HashTable[index]->next; //the second becomes the new first item
        delete delPtr; //deletes first item

        cout<<name<<" was removed from the hash table"<<endl;
    }
    //Case 3 (Bucket contains items but first item is not a match)
    else{
        P1 = HashTable[index]->next;
        P2 = HashTable[index]; //first item trailing behind P1/second item
        while(P1 != NULL && P1->name != name){
            P2 = P1;
            P1 = P1->next;
        }
    //Case 3.1 (No Match)
        if(P1 == NULL){
            cout<<name<<" was removed from the hash table"<<endl;
    }
        else{
    //Case 3.2 (Match is found)
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;
            delete delPtr;
            cout<<name<<" was removed from the hash table"<<endl;
        }
    }
}
}
