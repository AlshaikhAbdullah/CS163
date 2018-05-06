#include "1-program.h"
using namespace std;
int main()
{

	helpList list;
	tutor subject;
	char name [SIZE];// temp 
	char disc [SIZE];// temp 
	char hours [SIZE];// temp 
	int rating =0;// temp 
	char location [SIZE];// tmep 
	char help [SIZE];// tmep 
	char response;// temp varibale 
	

	
	cout << "Welcome !!!\n";

	do{
		cout << "What would you like to do:\n"
		<< " 1 - To add a subject.\n"
		<< " 2 - To display all subjects\n"
		<< " 3 - To edit a spesfic rating\n"
		<< " 4 - To display top rated subjects\n"
		<< " 5 - To remove everything with rating with 3 and lower\n" 
		<< " 6 - To Add Help For a Subject" << endl;

		cout << " what will you choose(1-6): "; 
		cin >> response;
		cin.ignore(100,'\n');
 
		if (response == '1')
		{
			cout << "What is the name of the course: ";
			cin.get(name ,SIZE,'\n');
			cin.ignore(100,'\n');
			cout << "What is the description of the assistance: ";
			cin.get(disc, SIZE,'\n');
			cin.ignore(100,'\n');
			cout << "What are the hours of the subject: ";
			cin.get(hours,SIZE,'\n');
			cin.ignore(100,'\n');
			
				cout << "What is the subject rating(1-10): ";
				cin >> rating;
				cin.ignore(100,'\n');
			cout << "Where is the location: ";
			cin.get(location,SIZE,'\n');
			cin.ignore(100,'\n');
			cout << "What is the help you can get for this subject: ";
			cin.get(help,SIZE,'\n');
			cin.ignore(100,'\n');
			subject.add(name,disc,hours,rating,location,help);
		 }



		if (response == '2')
		{
			if(!subject.displayAll())
			{
				cout << "Error There Are No Subjects." <<endl;
			}
		}
		if (response == '3')
		{
			if(!subject.editRating(rating,name))
			{
				cout << "Error There Are No Subjects." <<endl;
			}
			else
			{
				rating =0;
				subject.editRating(rating,name);
				cout << "Which subject: ";
				cin.get(name,SIZE,'\n');
				cin.ignore(100,'\n');
					cout << "What is the new rating: ";
					cin >> rating;
					cin.ignore(100,'\n');
				subject.editRating(rating,name);
			}
		}
		if (response == '4')
		{
			if(!subject.displayRated())
			{
				cout << "Error There Are No Subjects." <<endl;
			}
		}
		if(response == '5')
		{
			if(!subject.removeLow(name,disc,hours,rating,location,help))
			{
				cout << "Error There Are no Subjects." <<endl;
			}
		
			else
			{
				if(subject.removeLow(name,disc,hours,rating,location,help))
				{
					cout << "Assistance with 3 and less ratings are"
					<< "removed" << endl;
				}
			}
		}
		if(response == '6')
		{
				subject.subjects();
				cout << "Which subject would you like to add help for: ";
				cin.get(name,SIZE,'\n');
				cin.ignore(100,'\n');
				cout << "What is the description of the assistance: ";
				cin.get(disc, SIZE,'\n');
				cin.ignore(100,'\n');
				cout << "What are the hours of the subject: ";
				cin.get(hours,SIZE,'\n');
				cin.ignore(100,'\n');
				cout << "What is the subject rating(1-10): ";
				cin >> rating;
				cin.ignore(100,'\n');
				cout << "Where is the location: ";
				cin.get(location,SIZE,'\n');
				cin.ignore(100,'\n');
				cout << "What is the help you can get for this subject: ";
				cin.get(help,SIZE,'\n');
				cin.ignore(100,'\n');
				subject.newHelp(name,disc,hours,rating,location,help);
		}
		cout << "Would you like to start over(y/n): ";
		cin >> response;
		cin.ignore(100,'\n');
	}while(response == 'y');


	cout << "\nBest Of Luck !!" << endl;

		return 0;

}
