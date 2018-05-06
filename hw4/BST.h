/*
	this header will contain the node struct which will have pointers to right and left and and object instance for the manging class. also, theres gonna be the binary search tree class which will have the functions that will do multiple opearatios and it will have a root pointer to the struct node in it's private section along with the recrsive functions. 
*/
#include "games.h"


struct node
{
	videoGames games; //object variable to my manging class
	node * right;
	node * left;
};	


class BST
{
	public:
	//all functions more detailed comments in table.cpp file please refere to that
		BST();//constructor
		~BST();//destructor
		int displayRate();//to display games for a platform
		int find(char game []);//to find a game
		int displayInfo(char game []);//to display game's information
		int displayAll1();//to display all games 
		int remove(char game [],char genre [],char type1 [],char plat [],char star [], char disc1 []);//to remove a game that user chose
		int load(char game[],char genre [],char type1 [],char plat [],char star [],char disc1[]);//to load from extrnal text file
		int insert(char game[],char genre [],char type1 [],char plat [],char star [],char disc1[]); //to store data into my hash table
		int removePlat(char game [],char genre [],char type1[],char plat[],char star[],char disc1[]);
		int displayRange(char first [],char last[]);
	private:
		node * root;
		void clearAll(node * &root);
		int displayRange(char first[],char last[],node *root);
		int removePlat(char game [],char genre [], char tpe1 [],char plat [],char star [], char disc1 [], node *&root);
		int displayRate(node * root,int & rate);//to display games for a platform
		int find(char game [], node * root, bool &success);//to find a game
		int displayInfo(char game [], node * root);//to display game's information
		int displayAll1(node * root);//to display all games 
		int remove(char game [],char genre [], char type1 [], char plat [],char star [], char disc1 [], node *& root);//to remove a game that user chose
	//	int check(char game [], char plat []);//to check if the game and the platform are match to user input
		int addRec(char game [], char rec1 [], char plat [], node * root);//to add recommandtions to a game
	//	int load(char game[],char genre [],char type1 [],char plat [],char star [],char disc1[], node * &root);//to load from extrnal text file
		int insert(char game[],char genre [],char type1 [],char plat [],char star [],char disc1[], node *& root); //to store data into my hash table
};
