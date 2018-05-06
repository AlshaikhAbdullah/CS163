#include "BST.h"

//constructor which will set all private members variables to null to begin with 
videoGames::videoGames()
{
	name =NULL;
	kind =NULL;
	type =NULL;
	platform =NULL;
	stars =NULL;
	disc =NULL;
}
/*
i dont need this anymore
dnode::~dnode()
{
	if(rec_to_add)
	{
		delete [] rec_to_add;
		rec_to_add =NULL;
	}

}
*/
//destructor that will check for each memeber if it's pointing ar something then it will delete it and it will check 

videoGames::~videoGames()
{
		if(name)
		{
			delete [] name;
			name =NULL;
		}
		if(kind)
		{
			delete [] kind;
			kind =NULL;
		}
		if(type)
		{
			delete [] type;
			type =NULL;
		}
		if(platform)
		{
			delete [] platform;
			platform =NULL;
		}
		if(stars)
		{
			delete [] stars;
			stars =NULL;
		}
		if(disc)
		{
			delete [] disc;
			disc =NULL;
		}
}

//this function will check if the game and the platform entered by the user  are matched to the same one stored already
//it will return 1 if its or 0 if there was no match
int videoGames::deletePlat(char game [], char plat [])
{
	if(strcmp(game,name) ==0 && strcmp(platform,plat) ==0) 
	{
		if(name) //check if there was data
		{
			delete [] name; //delete the array
			name =NULL;
		}
		if(kind)//check if there is data and same for the rest
		{
			delete [] kind;//delete the array and same for the rest
			kind =NULL;
		}
		if(type)
		{
			delete [] type;
			type =NULL;
		}
		if(platform)
		{
			delete [] platform;
			platform =NULL;
		}
		if(stars)
		{
			delete [] stars;
			stars =NULL;
		}
		if(disc)
		{
			delete [] disc;
			disc =NULL;
		}
		return 1;//comparing to stored data
	}
	else return 0;
}

int videoGames::range(char first [], char last[])
{
	if((name[0] >= first[0] && name[0]<= last[0]) || (name[0] >=last[0] && name[0] <= first[0]) )//to compare the first letter of every girl if its in the range of the two letters entered by the user
	{
		cout << "\n\nGAME Name: " << name << endl;
		cout << "GAME Genre: " << kind << endl;
		cout << "GAME Type: " << type << endl;
		cout << "GAME Platform: " << platform << endl;
		cout << "GAME Rating: " << stars << endl;
		cout << "GAME Description: " << disc << endl << endl;

		 return 1;
	}
return 0;
}

int videoGames::checkRate()
{
	if(strcmp(stars,"5") >= 0 || strcmp(stars,"10") <=0) return 1;
	else return 0;
}
//this function will be taking care of copying the data entered by the user or from reading the file
//into my hash variables, it will get the length create a new char with the size of the variable that's been read and then it will copy it into the variables and then it will return success
int videoGames::copy(char game[],char genre [],char type1 [],char plat [],char star [], char disc1[])
{
	
	if(name) delete [] name;
	if(kind) delete [] kind;
	if(type) delete [] type;
	if(platform) delete [] platform;
	if(stars) delete [] stars;
	if(disc) delete [] disc;
	int len =0; //variable to stroe length of temp arrays
		
		//get the length of the temp arrays, then create a char with the size of the 
		//temp array plus 1 for the \0 and then copy the temp into hash variables
		len=strlen(game); name = new char [len +1]; strcpy(name,game);
		len=strlen(genre); kind = new char [len+1]; strcpy(kind,genre);
		len=strlen(type1); type = new char [len+1]; strcpy(type,type1);
		len=strlen(plat); platform = new char [len+1]; strcpy(platform,plat);
		len=strlen(star); stars = new char [len+1]; strcpy(stars,star);
		len=strlen(disc1); disc = new char [len+1]; strcpy(disc,disc1);
 return 1;
}


//this function will be checking if the data entered by user matches the platform for a game
//if it does, it will display that game and then return 1
//otherwise it will return 0 if it wasnt a match
int videoGames::display(char plat [])
{
	if(strcmp(plat,platform) == 0) //to compare if there was a match of the data entered and the data stored
	{
		cout << name << endl; //display the game
		return 1; //return 1 id there was match
	}
	else return 0; //return 0 if there was no match
}

//this function it will be taking care of displaying the data i have for each game 
//it will display the name,the genre,type,platform,rating,descripition 
//and then it will check if that game has another list which is the recommandations
//then it will display that info and traverse if there were more 
int videoGames::displayAll()
{
	if(!name) return 0;
	cout << "\n\nGAME Name: " << name << endl;
	cout << "GAME Genre: " << kind << endl;
	cout << "GAME Type: " << type << endl;
	cout << "GAME Platform: " << platform << endl;
	cout << "GAME Rating: " << stars << endl;
	cout << "GAME Description: " << disc << endl << endl;

return 1;
}

int videoGames::check(char game[])
{

	if(strcmp(game,name) ==0) return 1;
	else return 0;
}

//this function will be taking care of deleting the info so i dont just end up with memory leaks 
//even though destructor was suppose to do that, so it will if the data entered matchs 
//of what i have it will start check if there's data it will delete it
//eventually it will return 1,otherwise it will return 0 
int videoGames::removein(char game [])
{
	if(strcmp(game,name) == 0) 
	{

		if(name) //check if there was data
		{
			delete [] name; //delete the array
			name =NULL;
		}
		if(kind)//check if there is data and same for the rest
		{
			delete [] kind;//delete the array and same for the rest
			kind =NULL;
		}
		if(type)
		{
			delete [] type;
			type =NULL;
		}
		if(platform)
		{
			delete [] platform;
			platform =NULL;
		}
		if(stars)
		{
			delete [] stars;
			stars =NULL;
		}
		if(disc)
		{
			delete [] disc;
			disc =NULL;
		}

		return 1; //check if theres a match of user input and stored data 
	}
 	else return 0;
}


int videoGames::removeCopy(char game[],char genre [], char type1[],char plat [],char star[], char disc1[])
{

	strcpy(game,name); 
	strcpy(genre,kind);
	strcpy(type1,type);
	strcpy(plat,platform);
	strcpy(star,stars);
	strcpy(disc1,disc);

return 1;
}
//this function will be taking care of displaying the information for a game if waht the user 
//entered matced to stored data and it will check if that game has recommandations 
//it will display all of recommandtions if there were, otherwise it will return
int videoGames::gameInfo(char game[])
{

	if(strcmp(name,game) ==0)
	{
		cout << "\n\nGAME Genre: " << kind << endl;
		cout << "GAME Type: " << type << endl;
		cout << "GAME Platform: " << platform << endl;
		cout << "GAME Rating: " << stars << endl;
		cout << "GAME Description: " << disc <<  endl << endl;
	}		
return 1;
}

//this function will be taking care of just find if a game was matched to user input or not
//it will return 1 if its and 0 if it's not
int videoGames::retrieve(char game [])
{
	if(strcmp(game,name) < 0)  return 1;
	else return 0;
}

//this function will only ask user to repeat the process it will return true if y
//and false otherwise
bool again()
{
	char response;
		cout << "Would you like to start from the beginning?(y/n) ";
		cin >> response; cin.ignore(100,'\n');
		if(response == 'y' || response == 'Y') return true;
		if(response == 'n' || response == 'N') return false;
return false;
}
