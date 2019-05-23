//Chrystal Mingo
//Final Project
//Problem from Paul's Programming on Hash Table Projects 
//Implemented a Hash Table, that collected one's name and the key was the person's university.

#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"
using namespace std;
using namespace Hash_table;

int main(){
    hash_C Hashy; 
    Hashy.AddItem("Chrystal", "City College of New York"); //Adding Name and College to Hash Table
    Hashy.AddItem("Sam", "BMCC");
    Hashy.AddItem("Chris", "Queens College");
    Hashy.AddItem("Amanda", "City College");
    Hashy.AddItem("India", "BMCC");
    Hashy.AddItem("June", "Fordham University");
    Hashy.AddItem("Paul", "Columbia University");
    Hashy.AddItem("Pam", "NYU");
    Hashy.AddItem("Lucas", "BMCC");
    Hashy.AddItem("Michelle", "Bing");
    Hashy.AddItem("Ella", "NYU");
    Hashy.AddItem("JJ", "NYU");
    Hashy.AddItem("Maria", "BMCC");
    Hashy.AddItem("Esther", "Bing");
    //Testing for the same
    Hashy.AddItem("Rebecca", "NYU");
    Hashy.AddItem("Rebecca", "NYU");

    //UNCOMMENT THE FUNCTIONS FOR THE SPECIFIC ACTIONS YOU WANT

    //Prints out the entire table
    Hashy.PrintTable();

    //Chain Hash
    cout<<"THIS IS WHERE WE SEE ITEMS WITHIN A INDEX"<<endl;
    Hashy.PrintItemsInIndex(7); //How to see the Hash Table with the same names
    cout<<"THIS IS WHERE WE SEE ITEMS WITHIN A INDEX (ANOTHER INDEX EXAMPLE)"<<endl;
    Hashy.PrintItemsInIndex(2);
    //UNCOMMENT WHEN YOU WANT TO TEST THE BOTTOM FUNCTION
    //THIS FUNCTION BELOW FINDS THE COLLEGE OF EACH PERSON BASED OFF OF THE NAME YOU
    //Put name find the key

    //string input;
    //while(input != "exit"){
    //    cout<<"Search for ";
    //    cin>>input;
    //    if(input != "exit")
    //    {
    //       Hashy.FindCollege(input);
    //   }
    //}
    
    return 0;
}
