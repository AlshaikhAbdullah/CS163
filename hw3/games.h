//Abdullah Alshaikh 
//CS163 
//Program 3
/*

	this program will help the user stroe tons of games data
	it will be using hash table of linked list to add the game and it's information and   of linked lists to store multiple recommandations, it will keep the data away from main and it will only prompt the user for input in main and it will never display error messages from class functions
 



*/ 

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 200; //const int for all temp arrays im going to be using
const int TABLE = 101;//const size for my hash table
const char file [] = "CS163_games.txt";//const char for the txt file so it can be changed from here 

//struct which will be the second list that will be the recommandations list
//it will have a char pointer and a next pointer
struct dnode 
{
	char * rec_to_add; //to store recommandations
	dnode * next;
//	~dnode();
};


//this is the mangaing class it will have all of me char pointers for the data and a head and atail pointers to dnode struct to create node for each game stored that it might be addeed recommandations to afterwards 
//it will have multiple functions to do different operetions
class videoGames
{

	public:
	//all functon descriptions in games.cpp file
		videoGames();
		~videoGames();
		int display(char plat []); //to display games for a platform
		int gameInfo(char game []);//to display game's inforamtion
		int copy(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[]); //copy data entered by user or from txt file
		int retrieve(char game []);//to comapre for matched game
		int addrecom(char game [],char rec1 [], char plat []);//to add recommandions for agame
		int displayAll();//to display all games
		int removein(char game []);//remove a game
		int checkRec(char game [],char plat[]);//to check the game to add recommandations to 
		void clear(dnode *&head); //recursive funtion to use in destructor
	private:
		char * name;//to store game's name
		char * kind;//to store game genre
		char * type;//to store game type
		char * platform;//to store game platform
		char * stars;//to store game's rating
		char * disc;//to store game description
		dnode * head;
		dnode * tail;
};

bool again();//a function to repeat a process 
