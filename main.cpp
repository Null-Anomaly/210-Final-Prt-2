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
    //Seed randomization
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
    ifstream fin3("muffins.txt");
    string muffin;
    vector<string> set3;
    while(getline(fin3,muffin))
    {
        set3.push_back(muffin);
    }
    deque<string> muffins;

    //Part of milstone 4. Vector (But I mean everything else uses vectors as a basis)
    ifstream fin4("bracelets.txt");
    string bracelet;
    vector<string> set4;
    while(getline(fin4,bracelet))
    {
        set4.push_back(bracelet);
    }
    vector<string> bracelets;

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

        //Random muffin
        muffins.push_back(set3[rand() % set3.size()]);

        //Random bracelet
        bracelets.push_back(set4[rand() % set4.size()]);
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
        if(rand() % 2 == 0)
        {
            muffins.push_back(set3[rand() % set3.size()]);
        }
        if(rand() % 2 == 0)
        {
            bracelets.push_back(set4[rand() % set4.size()]);
        }
        
        //Prints out the person and what they order when they leave the line.
        if(head != nullptr)
        { 
            cout << head->order << " has ordered a: " << head->name << "\n\n";
            Coffee* deleter = head;
            head = head->next;
            delete deleter;
        }

        //Prints out a muffin and a person that ordered it
        if(!muffins.empty())
        {
            cout << set2[rand() % 100] << " has ordered a: " << muffins.front() << "\n\n";
            muffins.pop_front();
        }
        //Braclets!
        if(!bracelets.empty())
        {
            cout << set2[rand() % 100] << " has ordered a: " << bracelets.back() << " bracelet\n\n";
            bracelets.pop_back();
        }
        
    }
    
    return 0;
}