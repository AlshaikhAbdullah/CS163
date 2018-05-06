#include "stops.h"

stops::stops()
{
	name = NULL;
	location = NULL;
	lodging = NULL;
	rating = NULL;
	miles = 0;
	expense =0;


}
/// destructor for manging class
stops::~stops()
{
	//if there's info delete it
	if(name)
	{
		delete [] name;
		name =NULL;
	}
	if(location)
	{
		delete [] location;
		location =NULL;
	}
	if(lodging)
	{
		delete [] lodging;
		lodging =NULL;
	}
	if(rating)
	{
		delete [] rating;
		rating =NULL;
	}
}

//to display all data 
///////
int stops:: displayAll() 
{
	cout << "The stop is: " << name << endl;
	cout << "the location is: " << location << endl;
	cout << "The lodging is: " << lodging <<endl;
	cout << "The distanceis: " << miles <<" Miles" << endl;
	if(rating) // to display these info only if i have something "for the stack display"
	{
		cout << "The lodging rating was: " << rating << endl;
		cout << "The gas cost: $" << expense << endl;
	}
return 1;
}

//to create queue data
/////
int stops:: create(char stop[],char area[],char lodg[],char rate [],int & far) 
{
	int len =0;
	len = strlen(stop) +1; name = new char [len]; strcpy(name,stop);
	len = strlen(area) +1; location = new char [len]; strcpy(location,area);
	len = strlen(lodg) +1; lodging = new char [len]; strcpy(lodging,lodg);
	//len = strlen(rate) +1; rating = new char [len]; strcpy(rating,rate);
	miles = far;
return 0;
}
//to create stack data 
/////
int stops:: create1(char stop[],char area[],char lodg[],char rate [],int & far,int & cost)
{
	int len =0;
	len = strlen(stop) +1; name = new char [len]; strcpy(name,stop);
	len = strlen(area) +1; location = new char [len]; strcpy(location,area);
	len = strlen(lodg) +1; lodging = new char [len]; strcpy(lodging,lodg);
	len = strlen(rate) +1; rating = new char [len]; strcpy(rating,rate);
	expense = cost;
	miles = far;

return 0;
}

// to copy information into temp varibales in order to store them in the stack
///////
int stops::copy(char stop[],char area[],char lodg[],int & far){
	strcpy(stop,name);
	strcpy(area,location);
	strcpy(lodg,lodging);
	far = miles;

return 1;
}

//just a function to repeat steps
/////
bool again(){
	char response;
			cout << "Would you like to repeat the step(y/n): ";
			cin >> response; cin.ignore(100,'\n');
		if(response == 'y' || response == 'Y')
			return true;
		else
			return false;
}
