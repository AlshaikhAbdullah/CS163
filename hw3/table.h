/*

	this header file will contain the hash table which will have my functions and integer hash size and a hash double pointer to struct node which will have the mangaing class as data type anda next pointer 

*/
#include "games.h"


struct node
{
	videoGames games; //object variable to my manging class
	node * next;
};	


class table
{
	public:
	//all functions more detailed comments in table.cpp file please refere to that
		table();//constructor
		~table();//destructor
		void clearAll(node *&head);//recrisve function to deallcoate memory
		int displayPlat(char plat []);//to display games for a platform
		int find(char game []);//to find a game
		int displayInfo(char game []);//to display game's information
		int displayAll1();//to display all games 
		int remove(char game [],char plat []);//to remove a game that user chose
		int check(char game [], char plat []);//to check if the game and the platform are match to user input
		int addRec(char game [], char rec1 [], char plat []);//to add recommandtions to a game
		int load(char game[],char genre [],char type1 [],char plat [],char star [],char disc1[]);//to load from extrnal text file
		int insert(char game[],char genre [],char type1 [],char plat [],char star [],char disc1[]); //to store data into my hash table
	private:
		int hash_function(char game []); //hash function that will be giving me index values to store in
		node ** hash; //double pointer to struct node
		int hashSize; 
};
