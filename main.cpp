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


    Coffee head = person_1;
    auto it = head;
    for(int i = 0; i < 10; i++)
    {
        Coffee* temp = new Coffee(set1[rand() % set1.size()], set2[rand() % set2.size()]);
        it->next = temp;
        temp->next = NULL;
        it++;
    }
    //Milestone 1 ^
    return 0;
}