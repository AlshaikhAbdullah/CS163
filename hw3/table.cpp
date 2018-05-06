//this .cpp file is going to have my hash table class functions 
//it will do all the operations and it will call manging class functions to complete 
//these operations, these functions will return success or fillure dierctly back to main 
//i will include only table.h and by that it will have access to games.h which is the main .h file 




#include "table.h"
using namespace std;

//in my constructor i will create my hash of size table whic is 101 a prime number, so i can have a good hash function
//and then i will go to each index and set to null,eventually i will set hash size variable 
//to table
table::table()
{
	hash = new node*[TABLE];
	for(int i =0; i<TABLE; ++i)
	{
		hash[i]=NULL;
	}
	hashSize =TABLE;		
}

//the destructor will be taking care of checking each index and if there was chaining in it 
//and check if there was data to delete then it will call clearAll function which will
//delete all chaining nodes with tail recursion, and then it will check if hash is pointing at somthing 
//delete if it is and set it to null
table::~table()
{
	for(int i =0;i<TABLE;++i) //to go thorugh each index
	{
		node * head = hash[i];//assign head to point at that index
		if(head) clearAll(head);//if there's data it will call the recursive function
	}
	if(hash)//check if there's data 
	{
		delete [] hash; // delete it this way cuz its an array
		hash =NULL; //set it to null
	}

}

//this is a recursive function which will be traversing through each node and check
//if there's data then it will delete data with tail recursion from the last node to the first
//and then it will return to the destructor 
void table::clearAll(node *&head)
{

	if(!head) return;//base case to return head is null
	clearAll(head->next);//the recrsive call to traverse
	if(head)//check if head has data
	{
		delete head; // remove it 
		head=NULL;//set it to null
	}
}


///this function will read from the extrnal txt file, first it will create a varible for reading from the file 

//then it will open the txt file it will check if we opened the file then it will start reading from the file to every coulmn line by line till end of file then it will close the file and then clear it will return 1 if that happened succesfully other than that it will return 0 back to main
int table::load(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[])
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
 

// this function will be taking care of inserting data from the extrnal file
///it will reate a temporary pointer to the node struct it will call the hash function so i get an index to store my data into my hash
////if the hash function returns -1 that will mean there were no game name thus it will not save anything and it will return 0 to main other than that 
/////it will check if there'data stored in that index if there's it will create the node and then will connect the list 
////othere than that it will create the node and then make the hash pointer point to it
////it will always add at head
int table::insert(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[])
{
	node * temp = NULL;
	int index = hash_function(game); //to get the index from the hash function
	if(index == -1) return 0; //if it returns -1 that means game was empty thus will not insert
	
	temp = new node; // create the node
	if(!hash[index]) // if there was no nodes
	{
		temp->games.copy(game,genre,type1,plat,star,disc1);
		temp->next =NULL;
		hash[index]=temp;
		return 1;
	}
	//if there were multiple nodes 
	temp->games.copy(game,genre,type1,plat,star,disc1); //to copy data to managing class
	temp->next=hash[index];
	hash[index]=temp;//to point hash at the first node
	return 1;
}


//this function will be taking care of removing games by calling the find 
//to check if the game is stored if there wasnt it will return filuare back to main
//otherwise it will get the location of the stored game it will delete it 
//if it's the only node ot it will traverse and delete all if there were multiple nodes 
int table::remove(char game [] , char plat [])
{

	if(!find(game)) return 0; //if the game is not found it will return faluire
	else
	{	
		int index = hash_function(game);//it will get the location of that game
		node * current = hash[index]; //temp pointer so i can traverse
		node *prev=current;// previous pointer to connect
		if(!current->next)//to check if there was only one node
		{
			//call manging class remove to check if it deleted the other list
			if(current->games.removein(game))
			{
				delete current; //delete the node
				current = NULL;	
				hash[index] = current; //set hash to null
				return 1;//return success
			}
		}
		else //if there were multiple nodes
		{	
			while(current)//traverse through all of them
			{
				if(current->games.removein(game))
				{
					prev->next=current->next;//connect nodes
					delete current; //delete the nodes
					current =NULL; 
			//		hash[index] = NULL;
					return 1;
				}
				prev=current; //draging the previous pointer
				current = current->next; //traverse
			}
		}
	}	
return 1;	
}

//thie function will be taking care of displaying all games for a platform 
//it will check first if there's data and then i will have a bool variable that will catah
//return, it will traverse thro each indexi and node and check if the platform has been found
//if at least won was found it i will return success back to main
int table::displayPlat(char plat [])
{
	if(hash)//to check if i ahve data to begin with
	{
		bool success = false;//to get returned value from manging class function
		bool found = false;//to store true if at least one was found
		cout << "\n\n"; //just new lines
		for(int i =0; i < TABLE; ++i) //traverse thro each index
		{
				node * current = hash[i];//so i traverse thro nodes
				while(current)
				{
					success = current->games.display(plat);//call manging function and store the return value
					if(success)  found = success;//store stroe if one was found
					current=current->next;//traverse
				}
		}
		return found;//return if a platform was found
	}
	else return 0;
}
//this function will return 0 if there were no data to display 
////otherwise it will look through each index and it will display its data and it if there were more than one node it will go through each one and display them all
/// eventually it will retrun 1 which is success after diplaying all data that i have stored
int table::displayAll1()
{
	if(hash)//to check if theres data to begin with
	{
		for(int i =0; i < TABLE; ++i)//to go thro each index
		{
				node * current = hash[i];
				while(current) 
				{
					current->games.displayAll();//to call managing 
					current=current->next;
				}
		}
		return 1;
	}
	else return 0;
}

//this is my retrieve function it will check if the input entered by the user is avilable 
//it will traverse and  catch the returned value from manging class and store it 
//if there was a match it will return true otherwise it will return false
int table::find(char game[])
{
	bool success = false;
	bool found = false;
	int index = hash_function(game);
	node * current = hash[index];	
	while(current && !success) //to exacute if there's data and success is not false
	{
		success = current->games.retrieve(game);//to catch the returned value
		if(success) found=success;//to store if there was a match
		current = current->next;//traverse
	}
	return found;//return catsh value
}
//this function will display info for certain game even if it has multiple platforms 
//whenever im gonna get to this i will make sure that i have that game by using the retrieve function before calling this one like what im doing in main and it will get the location of the data
//then traverse to get all games in the location in memory
int table::displayInfo(char to_find [])
{

	int index = hash_function(to_find); //get the game index
	node *current = hash[index];
		while(current)
		{
			current->games.gameInfo(to_find);//to display games info from manging class
			current = current->next;//traverse
		}	
return 1;
}

//this function will be taking care of adding recommadatios for a game it will check if the game was found and then it will go to that index traverse and then call managing function to add
int table::addRec(char game [], char rec1 [],char plat [])
{
	if(!find(game)) return 0; //to check if the game is there
	else
	{
		bool success = false;
		int index = hash_function(game);
		node *current = hash[index];
			while(current && !success)
			{
				success = current->games.addrecom(game,rec1,plat);
				current= current->next;
			}
		return success;
	}
}

//this function wil be responsible of check for the display games by platform function 
//it will look for the game and thplat form and it will return true back to main if there
//was a match false otherwise
int table::check(char game [],char plat [])
{

	bool success = false; //boolen to store faluire or sucess
	int index = hash_function(game); //to get the location of the data
	node * current = hash[index];	// so ican traverse if there were multiple nodes
	while(current && !success) // traverse and check the return value if its true means we found it 
	{
		success = current->games.checkRec(game,plat); //calling manging function to check for match
		current = current->next;
	}
	return success; /// return my result back to main

}

//this the hash function it will be taking care of creating the number that will become the index where my data will be stored it will return -1 if there was no game other than that it will capitalize the first letter than it will make the integer sum take the value of the length of the game and it will return the number mod the hash table size 
int table::hash_function(char game [])
{
	int sum =0;
	if(!game) return -1; 
	int len = strlen(game);
	for(int i =0; i < len; ++i)
		sum+=game[i];//to get a number so it can be modded to my hash size
	return sum % hashSize;//return the index number
}
