//this is the main fuunction file it will only have main and all the user interaction will be delt with here in this file
//it will include only one header file and that header file will include the other one, in here the error messages will be displayed by using returned values from functions
#include "table.h"


int main()
{
	table mygames; //object for my table class
	//temp arrays to store users input and reading from text file
	char game [SIZE];//for the game name
	char genre [SIZE];// for the genre
	char disc1 [SIZE];//for the description 
	char type1 [SIZE]; // diabates " for the game type
	char plat [SIZE];//for the game platform
	char star [SIZE]; //fro the game rating 
	char rec1 [SIZE];//for the game recommandtions
	char response;//to store user response for the menu
		do{
			cout << "Welcome !!!\n" << endl;
			cout << "Here is the Menu:\n"
				<< "1- Add a new game.\n"	
				<< "2- Load games from the extrnal file.\n"
				<< "3- Remove a game.\n"
				<< "4- Add recommendations for a game.\n"
				<< "5- Retrive information about a game.\n"
				<< "6- Display all games for a platform.\n"
				<< "7- Display all games for all platforms.\n" << endl;
				cout << "What would you choose(1-7): ";
				cin >> response; cin.ignore(100,'\n');
				if(response == '1')
				{
					cout << "What's the game name: ";
					cin.get(game,SIZE,'\n'); cin.ignore(100,'\n');
					game[0] =toupper(game[0]);//capitalzie the first letter for all of them

					cout << "What's the game genre: "; 
					cin.get(genre,SIZE,'\n'); cin.ignore(100,'\n');
					genre[0] =toupper(genre[0]);

					cout << "What's the game type: ";
					cin.get(type1,SIZE,'\n'); cin.ignore(100,'\n');
					type1[0] =toupper(type1[0]);
	
					cout << "What's the platform: ";
					cin.get(plat,SIZE,'\n'); cin.ignore(100,'\n');
					plat[0] =toupper(plat[0]);
	
					cout << "What's the game rating: ";
					cin.get(star,SIZE,'\n'); cin.ignore(100,'\n');

					cout << "What the game description: ";
					cin.get(disc1,SIZE,'\n'); cin.ignore(100,'\n');
					disc1[0] =toupper(disc1[0]);

					mygames.insert(game,genre,type1,plat,star,disc1); //call insert function in table to add data
				}

				if(response == '2')
				{
					//call the load function to read from file and get the returned value 
					if(mygames.load(game,genre,type1,plat,star,disc1)) cout << "\nFile has been loaded!!\n\n";
					else cout << "ERROR!! File was not found !!\n\n";
				}

				if(response == '3')
				{
					cout << "\nwhat's the name of the game you want to remove: ";
					cin.get(game,SIZE,'\n'); cin.ignore(100,'\n');
					game[0] =toupper(game[0]);
					
					//to call the remove function in table class to remove what the user input if it was found and it will catsh the returned value
					if(mygames.remove(game,plat)) cout << "This Game: " << game << " Has Been Removed.\n\n";
					else cout << "ERROR !!! Game Not Found !!\n\n";
				}

				if(response == '4')
				{
					cout << "\nWhich game would you like to add recommendations for: ";
					cin.get(game,SIZE,'\n'); cin.ignore(100,'\n');
					game [0] =toupper(game[0]);
					
					cout << "\nOn which platform: ";
					cin.get(plat,SIZE,'\n'); cin.ignore(100,'\n');
					plat[0] =toupper(plat[0]);

					if(mygames.check(game,plat)) //it will check if there was a match first, otherwise it will display error message
					{
						cout << "\nWhat's the recommendations: ";
						cin.get(rec1,SIZE,'\n'); cin.ignore(100,'\n');
						rec1[0] =toupper(rec1[0]);
						
						//if there was a match it will call this function to add recommandations to a game
						if(mygames.addRec(game,rec1,plat)) 
						cout << "Recommendations have been added to this game: " << game << "\n\n";
					}
					else cout << "\nERROR !! Game not found !!\n\n";
				}

				if(response == '5')
				{
					cout << "\nwhats the game you would like to retrieve it info: ";
					cin.get(game,SIZE,'\n'); cin.ignore(100,'\n');
					game[0] =toupper(game[0]);

					if(!mygames.find(game))	cout << "\nERROR !! Game Not Found !!!\n";
					else
					{
						cout << "\nHere's the information for: " << game << endl;
						mygames.displayInfo(game);
					}	
				}
				
				if(response == '6')
				{
					cout << "\nWhich Platform you want to display it's games: ";
					cin.get(plat,SIZE,'\n'); cin.ignore(100,'\n');
					plat[0] =toupper(plat[0]);
	
					//it will call the display function if this function doesnt find the platform it will display error message
					if(!mygames.displayPlat(plat)) 	cout << "\nThere Are No Games For this Platform!!!\n";
					else cout << endl;
				}			
				
				if(response == '7')
					//it will call the display function if there was no data it will display an error message
					if(!mygames.displayAll1()) cout << "ERROR !! There Are No GAMES !!\n\n";
		}while(again());//call again function to ask the user if wants to repeat and if it returned true it will exacuate otherwise it will end the program


		cout << "\nHave a Great Day :)\n" << endl;



return 0;
}

