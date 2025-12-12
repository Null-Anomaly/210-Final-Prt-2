/*COMSC 210 | Final prt 2 | Lawrence Bryant
IDE used: VSC*/

//Includes
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <deque>
using namespace std;

//Coffee structure
struct Coffee
{

    string name;
    string order;
    Coffee* next;
};


int main()
{
    //Seed
    srand(time(NULL));
    
    //File input 1 mislabled as set 1
    ifstream fin1 ("Coffee.txt");
    string order;
    vector<string> set1;
    while(getline(fin1,order))
    {
        set1.push_back(order);
    }
    fin1.close();

    //File 2 input mislabled as set 2 (At least in terms of having name first then order)
    ifstream fin2("Name_input.txt");
    string name;
    vector<string> set2;
    while(getline(fin2,name))
    {
        set2.push_back(name);
    }
    fin2.close();

    //Part of milestone 3. Deque.
    deque<Coffee> muffins;


    //This mess.
    //Makes a linked list of 3 people to initialize
    Coffee *head = nullptr;
    Coffee *tail = nullptr;
    for(int i = 0; i < 3; i++)
    {
        Coffee *inserter = new Coffee;
        inserter->name = set1[rand() % set1.size()];
        inserter->order = set2[rand() % 100];
        inserter->next = nullptr;
        if(head == nullptr)
        {
            head = inserter;
        }
        else
        {
            Coffee* temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = inserter;
        }
    }  

    //Loop for handling 10 potential people joining the line and ordering coffee
    for(int i = 0; i < 10; i++)
    {
        if(rand() % 2 == 0)
        {
            Coffee* temp = new Coffee;
            temp->name = set1[rand() % set1.size()];
            temp->order = set2[rand() % 100];
            temp->next = tail;
            if(head == nullptr)
            {
                head = temp;
            }
            else
            {
                Coffee* it = head;
                while(it->next != tail)
                {
                    it = it->next;
                }
                it->next = temp;
            }
        }
        
        //Prints out the person and what they order when they leave the line.
        if(head != nullptr)
        { 
            cout << head->order << " has ordered a: " << head->name << "\n";
            Coffee* deleter = head;
            head = head->next;
            delete deleter;
        }
       
        
    }
    
    return 0;
}