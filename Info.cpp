#include<ios>
#include<iostream>

#include <string>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include  <cstdarg>



#define MAX_LENGTH  255

#define  OR  ||
#define AND && 




typedef struct Node Node;

struct Node  {
    int a ;

    Node  *next;
};



using namespace std ;

class Info
{
private:
    /* data */

     string username ;
     string password ;
public:
    Info(/* args */);
    ~Info();
};

Info::Info(/* args */)
{
}

Info::~Info()
{
}



