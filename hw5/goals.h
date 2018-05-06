//Abdullah Alshaikh
//CS163 - Program 5
/*
	***This program will help manage student's goals for the winter break 
	***It will be using graphs data structure and it will store goals and it tasks 
	***from the client and it will give the usre the option to connect the goals 
	***and display connected ones or display tasks for a goal
	***it will be connecting vertices by diercted edges.
										*/




//the managing class .h file and the main header file which will include all the libraries needed
//and the constant integers and the functions prototypes,
//
#include <iostream> 
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 100; //for all temp arrays

class Goal
{
		//function detailed comments in goals.cpp please refere to it for more info
		/////
	public:
		Goal();
		~Goal();
		int info(char toFind []);//to display tasks for a goal
		int create(char toDo[],char do1[],char do2 [],char do3 [], char plan1 []);
		int display();//to display connected
		bool compare(char compare []);//to find matches
		int copy(Goal & to_copy);//to copy into private data members
	private:
		//variables to store data
		char * name;
		char * first;
		char * second;
		char * third;
		char * plan;
};

bool again(); //function for reapeting response
