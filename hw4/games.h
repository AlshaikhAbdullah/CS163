//Abdullah Alshaikh 
//CS163 
//Program 3
/*

	this program will help the user stroe tons of games data
	it will be using a binary search tree  to add the game and it's information and it will keep the data away from main and it will only prompt the user for input in main and it will never display error messages from class functions
 



*/ 

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 200; //const int for all temp arrays im going to be using
const char file [] = "CS163_games.txt";//const char for the txt file so it can be changed from here 


//this is the mangaing class it will have all of me char pointers for the data and a head and atail pointers to dnode struct to create node for each game stored that it might be addeed recommandations to afterwards 
//it will have multiple functions to do different operetions
class videoGames
{

	public:
	//all functon descriptions in games.cpp file
		videoGames();
		~videoGames();
		int range(char first[], char last[]);
		int display(char plat []); //to display games for a platform
		int gameInfo(char game []);//to display game's inforamtion
		int copy(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[]); //copy data entered by user or from txt file
		int retrieve(char game []);//to comapre for matched game
		int displayAll();//to display all games
		int removein(char game []);//remove a game
		int removeCopy(char game [],char genre [],char type1 [],char plat [],char star [],char disc1[]);
		int deletePlat(char game [],char plat[]);//to check the game to add recommandations to 
		int checkRate();
		int check(char game []);
	private:
		char * name;//to store game's name
		char * kind;//to store game genre
		char * type;//to store game type
		char * platform;//to store game platform
		char * stars;//to store game's rating
		char * disc;//to store game description
};

bool again();//a function to repeat a process 
