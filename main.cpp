/*COMSC 210 | Final prt 2 | Lawrence Bryant
IDE used: VSC*/
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <list>
using namespace std;


struct Coffee
{

    string name;
    string order;
    Coffee* next;
};


int main()
{
    //Milestone 1 v
    srand(time(NULL));
    

    ifstream fin1 ("Coffee.txt");
    string order;
    vector<string> set1;
    while(getline(fin1,order))
    {
        set1.push_back(order);
    }
    fin1.close();

    ifstream fin2("Name_input.txt");
    string name;
    vector<string> set2;
    while(getline(fin2,name))
    {
        set2.push_back(name);
    }
    fin2.close();


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

    for(int i = 0; i < 10; i++)
    {
        if(rand() % 2 == 1)
        {
            Coffee* temp = new Coffee;
            temp->name = set1[rand() % set1.size()];
            temp->order = set2[rand() % 100];
            temp->next = nullptr;
            Coffee* it = head;
            while(it->next != tail)
            {
                it = it->next;
            }
            it->next = temp;
        }
    }
    auto it = head;
    while(it != nullptr)
    {
        cout << it->order << " has ordered a: " << it->name << "\n";
        it = it->next;
    }
    //Milestone 1 ^
    return 0;
}