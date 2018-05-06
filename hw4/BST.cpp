//this .cpp file is going to have my binary search tree functions  
//it will do all the operations and it will call manging class functions to complete 
//these operations, these functions will return success or fillure dierctly back to main 
//i will include only table.h and by that it will have access to games.h which is the main .h file 




#include "BST.h"
using namespace std;
//the constructor will only initilaize root to null 
BST::BST()
{

	root =NULL;
}

//the destructor will call a recursive function which will traverse thro the tree and delete all nodes.
BST::~BST()
{
	
	if(root) clearAll(root);
}

//this is a recursive function which will be traversing through each node and check
//if there's data then it will delete data with tail recursion from the last node to the first
//and then it will return to the destructor 
void BST::clearAll(node *&root)
{
	if(!root) return;
	clearAll(root->left);
	clearAll(root->right);
	if(!root->left && !root->right)
	{
		if(root)
		{
			delete root;
			root =NULL;
		}
	}
	 //clearAll(root->right);
}


///this function will read from the extrnal txt file, first it will create a varible for reading from the file 
//then it will open the txt file it will check if we opened the file then it will start reading from the file to every coulmn line by line till end of file then it will close the file and then clear it will return 1 if that happened succesfully other than that it will return 0 back to main
int BST::load(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[])
{
	ifstream reading; //variable for reading from the file
	reading.open(file); //open the txt file by const char in header file
		if(reading) //to check if we are in file
		{
			//to traverse till end of file and don't get empty readings at the end
			//because loops for some reason goes beyond eof
			while(reading.get(game,SIZE,':') && !reading.eof()) 
			{

	//			reading.get(game,SIZE,':'); 
				reading.ignore(100,':');
				reading.get(genre,SIZE,':'); reading.ignore(100,':');
				reading.get(type1,SIZE,':'); reading.ignore(100,':');
				reading.get(plat,SIZE,':'); reading.ignore(100,':');	
				reading.get(star,SIZE,':'); reading.ignore(100,':');
				reading.get(disc1,SIZE,'\n'); reading.ignore(100,'\n');
					insert(game,genre,type1,plat,star,disc1);
			}
			reading.close(); // to close the txt file 
			reading.clear();// to clear
			return 1; // return success
		}

	return 0;

}


//this function will be taking care of inserting data by creating nodes it will call the recrsive function  
int BST::insert(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[])
{
	
	return insert(game,genre,type1,plat,star,disc1,root);
}

// this is the recursive function which will call the maning class to check the data entered by the user or from the txt file is big or less , if it's bigger goes to the right or to the left of its less then add the node there 
int BST::insert(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[], node *& root)
{
	if(!root) 
	{
		root=new node;
		root->games.copy(game,genre,type1,plat,star,disc1);
		root->right =NULL;
		root->left =NULL;
		return 1;
	}
	else if(root->games.retrieve(game)) // to check if the data less or bigger
		return insert(game,genre,type1,plat,star,disc1,root->left);
	else  return insert(game,genre,type1,plat,star,disc1,root->right);
}


//this function will be taking care of removing games by calling the find 
//to check if the game is stored if there wasnt it will return filuare back to main
//otherwise it will get the location of the stored game it will delete it 
//if it's the only node ot it will traverse and delete all if there were multiple nodes 
int BST::remove(char game [] ,char genre [],char type1 [], char plat [],char star [],char disc1 [])
{
	if(!root) return 0;
	else return	remove(game,genre,type1,plat,star,disc1,root);
}


//this function will be taking care of removing all instances of a game it will do that with tail recursion, it's going to check the game and then check if it has an in order successor it so going to copy the data to the node that has the game that was found and then delete the ios
int BST::remove(char game [],char genre [], char type1 [], char plat [],char star [],char disc1 [], node *& root)
{
	if(!root)  return 0;
	if(root->games.check(game)) //to check if the game is found
	{
	
		if(!root->left && !root->right)//check if it's a leaf
		{
				delete root;
				root = NULL;
				return 1;
		}
		else if(!root->left) //check if there's one child "parent"
		{
			node * current = root;
			root= root->right;
			delete current;
			return remove(game,genre,type1,plat,star,disc1,root);			
		}
		else if(!root->right) //check if theres one child "parent"
		{
			node * current = root;
			root=root->left;
			delete current;
		//	current =NULL;
			return remove(game,genre,type1,plat,star,disc1,root); 
		}
		else //two children find the in order successor 
		{
				node * current = root->right;
			if(!current->left)  
			{
				current->games.removeCopy(game,genre,type1,plat,star,disc1);
				root->games.copy(game,genre,type1,plat,star,disc1);
		
					return remove(game,genre,type1,plat,star,disc1,root->right);
			}
			else
			{
				while(current->left)
				{
					current = current->left;
				}
					current->games.removeCopy(game,genre,type1,plat,star,disc1);
					root->games.copy(game,genre,type1,plat,star,disc1);
					return remove(game,genre,type1,plat,star,disc1,root->right);
			}
		}
	}
	if(root->games.retrieve(game))
	return remove(game,genre,type1,plat,star,disc1,root->left);
	else return remove(game,genre,type1,plat,star,disc1,root->right);

}

//thie function will be taking care of displaying how many games with a rating of 5 and above
//it will check first if there's data.
//return, it will call the recrsive function 

int BST::displayRate()
{
	int rate =0;
	if(!root) return -1;
	else return displayRate(root,rate);
}

//this is the recursive function for displaying the rate which will be tarversing thro the BST
int BST::displayRate(node *root,int &rate)
{
	if(!root) return rate;	
	displayRate(root->left,rate);
	if(root->games.checkRate()) ++rate;
	return displayRate(root->right,rate);
}
//this function will return 0 if there were no data to display 
////or it will call recrsive function 
int BST::displayAll1()
{
	if(!root) return 0;
	return displayAll1(root);
}

//it going to ttraverse all the way thro the binary search tree and then displays the data by calling the manging class fudtion that will display the data.
int BST::displayAll1(node * root)
{
	if(!root) return 1;
	displayAll1(root->left);
	root->games.displayAll();
	return displayAll1(root->right);	
}
//this is my retrieve function it will check if the input entered by the user is avilable 
//it will traverse and  catch the returned value from manging class and store it 
//if there was a match it will return true otherwise it will return false
int BST::find(char game[])
{
	bool success = false;
	return find(game,root,success);
}
//this is the recrsive function for find which will be taking care of traversing.
int BST::find(char game [], node * root,bool &success)
{
	if(!root) return success;
	if(root->games.check(game)) success = true;
	find(game,root->right,success);
	if(root->games.check(game)) success = true;
	return find(game,root->left,success);
}
//this is wrapper function for the display in range function it will check if there's data first
// then it will call the recursve function 
int BST::displayRange(char first[], char last[])
{
	if(!root) return 0;
	else return displayRange(first,last,root);
}
//the recursive function will traverse and check the range of the two letters from the manging class and then diaply if it's in that range 
int BST::displayRange(char first[], char last[],node *root)
{
	if(!root) return 1;
	displayRange(first,last,root->left);
	root->games.range(first,last);
	return displayRange(first,last,root->right);	
}
//this function will display info for certain game even if it has multiple platforms 
//whenever im gonna get to this i will make sure that i have that game by using the retrieve function before calling this one like what im doing in main and it will get the location of the data
//then traverse to get all games in the location in memory
int BST::displayInfo(char to_find [])
{
	if(find(to_find)) return displayInfo(to_find,root);
	else return 0;
}
// the recursive fuunction which will traverse and display each node 
int BST::displayInfo(char to_find[],node * root)
{
	if(!root) return 0;
	displayInfo(to_find,root->left);
	root->games.gameInfo(to_find);
	return 	displayInfo(to_find,root->right);
}

//this function will be taking care of the deleting a game by name and platform by calling the recursive function
int BST::removePlat(char game [] ,char genre [],char type1 [], char plat [],char star [],char disc1 [])
{
	if(!root) return 0;
	else return removePlat(game,genre,type1,plat,star,disc1,root); 
}
//the resrive function for removing from the BST by checking if it has a ios the n find it and then copy the data and the 
int BST::removePlat(char game[],char genre [], char type1 [],char plat [],char star [], char disc1 [],node*&root)
{
	if(!root)  return 0;
	if(root->games.deletePlat(game,plat))
	{
		if(!root->left && !root->right)//check if it's a leaf
		{
				delete root;
				root = NULL;
				return 1;
		}
		else if(!root->left) //check if there's one child "parent"
		{
			node * current = root;
			root= root->right;
			delete current;
			current =NULL;
			return 1;
		}
		else if(!root->right) //check if theres one child "parent"
		{
			node * current = root;
			root=root->left;
			delete current;
			current = NULL;
			return 1;
		}
		else //two children find the in order successor 
		{
				node * current = root->right;
			if(!current->left)  //if the node on the right is the ios
			{
				current->games.removeCopy(game,genre,type1,plat,star,disc1);
				root->games.copy(game,genre,type1,plat,star,disc1);
					if(current->right) // if theres' right node after the ios 
					{
						root->right = current->right; // conect it 
					
						delete current;
		
						return 1;
					}
					else 
					{ 
						delete current; // 
						return 1;
					}		
			}
			else // if there's a left so we have to traverse all the way to the left
			{
				while(current->left)
				{
					current = current->left;
				}//if we at the final node copy it and then delete 
					current->games.removeCopy(game,genre,type1,plat,star,disc1);
					root->games.copy(game,genre,type1,plat,star,disc1);
					delete current;
					return 1;
			}
		}
	}
	if(root->games.retrieve(game))
		return removePlat(game,genre,type1,plat,star,disc1,root->left);
	else return removePlat(game,genre,type1,plat,star,disc1,root->right);			
}	
