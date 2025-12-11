/*COMSC 210 | Final prt 2 | Lawrence Bryant
IDE used: VSC*/
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;


struct Coffee
{
    Coffee(string, string);

    string name;
    string order;

    struct Coffee* next;
};