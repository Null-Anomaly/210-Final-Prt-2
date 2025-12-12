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
    Coffee(string, string);

    string name;
    string order;

    struct Coffee* next;
};


int main()
{
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

    Coffee* head = NULL;
    Coffee* temp = NULL;
    for(int i = 0; i < set1.size(); i++)
    {
        temp = new Coffee(set2[rand() % set2.size()], set1[rand() % set1.size()]);
        
    }

    return 0;
}