//Chrystal Mingo
//Final Project

//Implemented a Hash Table, that collected one's name and the key was the person's university.

#include <cstdlib>
#include <iostream>
#include <string>
#include "hash.h"
using namespace std;
namespace Hash_table{

int main(){
    hash Hashy; 
    Hashy.AddItem("Chrystal", "City College of New York"); //Adding Name and College to Hash Table
    Hashy.AddItem("Sam", "BMCC");
    Hashy.AddItem("Chris", "Queens College");
    Hashy.AddItem("Amanda", "City College");
    Hashy.AddItem("India", "BMCC");
    Hashy.AddItem("June", "Fordham University");
    Hashy.AddItem("Paul", "Columbia University");
    Hashy.AddItem("Pam", "NYU");
    Hashy.PrintTable();//Print's entire Hash Table
    Hashy.PrintItemsInIndex(0);//How to see the Hash Table

    while(name != "exit"){
        cout<<"Search for ";
        cin>>name;
        if(name != "exit")
        {
            Hashy.FindCollege(name);
        }
    }
    return 0;
}
}