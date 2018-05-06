/// Abdullah Alshaikh
//// CS163 Homework 2
///// homework to help manging a trip by stops and the location of them
////// the header will have the manging stop for my project
///////
/////////
//////////
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//consts for my arrays
int const SIZE = 200;
int const MAX = 5;

class stops
{
	public:
		stops();
		~stops();
		int create(char stop[],char area[],char lodg[],char rate [],int & far);
		int displayAll();	
		int copy(char stop[],char area[],char lodg[],int & far);
		int create1(char stop[],char area[],char lodg[],char rate [],int & far,int & cost);
	private:
		char * name;
		char * location;
		char * lodging;
		char * rating;
		int miles;
		int expense;
};

//function to repeat steps
//
bool again();	
