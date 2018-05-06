// this file has the funcations for the second linked list the help

#include "1-program.h"

helpList::helpList()
{


	head=NULL;
	tail=NULL;	
}

way2help::way2help()
{
	disc1 = NULL;
	hours1 = NULL;
	rating1 = 0;
	location1 =NULL;
	help1 = NULL;


}

way2help::~way2help()
{
	if(disc1)
	{
		delete [] disc1;
		disc1 = NULL;
	}
	if(hours1)
	{
		delete [] hours1;
		hours1 =NULL;
	}
	if(location1)
	{
		delete [] location1;
		location1 = NULL;
	}
	if(help1)
	{
		delete [] help1;
		help1 = NULL;
	}
	next = NULL;
}

helpList::~helpList()
{


	way2help * prev = NULL;
	while(head)
	{
		if(head->disc1)
		{
			delete [] head->disc1;
			head->disc1=NULL;
		}
		if(head->hours1)
		{
			delete [] head->hours1;
			head->hours1 = NULL;
		}
		if(head->location1)
		{
			delete [] head->location1;
			head->location1 = NULL;
		}
		if(head->help1)
		{
			delete [] head->help1;
			head->help1 = NULL;
		}
		

	prev = head->next;
	delete head;
	head = prev;

	}	
		if(head)
		{	
			delete head;
			head = NULL;
		}
}

int helpList::insert(char disc [], char hours [], int& rating, char location [], char help [])
{
	if(!head)
	{
		head=new way2help;
		//tail = head;
		head->disc1 = new char [strlen(disc)+1];
		strcpy(head->disc1,disc);

		head->hours1 = new char [strlen(hours)+1];
		strcpy(head->hours1,hours);

		head->rating1 = rating;

		head->location1 = new char [strlen(location)+1];
		strcpy(head->location1,location);

		head->help1 = new char [strlen(help)+1];
		strcpy(head->help1,help);

		head->next =NULL;
		tail = head;
				return 1;
	}

	else
	{
		tail->next = new way2help;
		tail = tail->next;

		tail->disc1 = new char [strlen(disc)+1];
		strcpy(tail->disc1,disc);

		tail->hours1 = new char [strlen(hours)+1];
		strcpy(tail->hours1,hours);

		tail->rating1=rating;

		tail->location1 = new char [strlen(location)+1];
		strcpy(tail->location1,location);

		tail->help1 = new char [strlen(help)+1];
		strcpy(tail->help1,help);

		tail->next = NULL;
		return 1;
}

return 1;


}

int helpList::display()
{
		if(!head)return 0;
		display(head);

/*
	way2help * current = head;

	while(current)
	{
		cout << "The description is: " <<  current->disc1
		<< "\nThe hours are: " << current->hours1  	
		<< "\nThe rating is: " << current->rating1
		<< "\nThe location is: " << current->location1
		<< "\nHelp for it is: " << current->help1 << endl;

		current = current->next;
	}
		*/

return 1;
}

int helpList::display(way2help* head)
{
	if(!head)return 0;
		cout << "The description is: " <<  head->disc1
		<< "\nThe hours are: " << head->hours1  	
		<< "\nThe rating is: " << head->rating1
		<< "\nThe location is: " << head->location1
		<< "\nHelp for it is: " << head->help1 << endl;

		display(head->next);

}

int helpList::editrating(int& rating, char name []) 
{
	way2help * current = head;

	if(rating > 0)
	{
		current->rating1 = rating;
		return 1;
	}
	while(current)
	{
			
		if(!current->next)
		{
			return current->rating1;
		}
		current = current->next;

	}





}

int helpList::displayrate() // to display top rated 
{

	way2help * current = head;
	
	while(current)
	{
		
		if(current->rating1 >=8)
		{
		cout << "The description is: " <<  current->disc1
		<< "\nThe hours are: " << current->hours1  	
		<< "\nThe rating is: " << current->rating1
		<< "\nThe location is: " << current->location1
		<< "\nHelp for it is: " << current->help1 << endl;
		return 1;
		}
		
	
		current=current->next;
	}

 return 0;
}

int helpList::remove()// remove the second list if its low rating 
{
/*
	if(tail->rating <=3)
	{
		return 1;
	}

*/
	if(!head)return 0;
	if(head->rating1 <=3)
	{
		delete head;
		head = head->next;
		remove();
	}

		way2help * current = head;
		way2help * prev = NULL;
		
		while(current)
		{
				if(current->rating1 > 3)
				{
					return 0;

				}
			
				if(!current->next && current->rating1 <=3)
				{
					delete current;
					current= NULL;
					return 1;
				}
				if(current->rating1 <=3)
				{
					prev->next = current->next;
					delete current;
					current = prev;
				}

			
			prev = current;
			current = current->next;
	
		}

	return 1;
}

/*
	if(remove(head))
		return 1;
	else
		return 0;
*/

//	if(current->rating <= 3)
//	{	temp = current;
///		current = current->next;
//		delete temp;
//		return 1;
//	}
/*
	current = head;	
	while(current)
	{

		if(!current->next && current->rating <=3)
		{
			delete current;
			current = NULL;
			return 1;
		}	
		if(current->rating <=3)
		{	
			temp = current;
			current = current->next;
			prev->next = current;
			delete temp;
			return 1;

		}

		
		prev =current;
		current = current->next;
	} 
return 1;
}
*/

int helpList::remove(way2help*& head)
{
	way2help * prev=NULL;
		if(!head) return 0;
		if(head->rating1 <=3)
		{	
			if(!head->next)
			{
					delete head;
					head =NULL;
					return 1;
			}
			else
			{
				prev->next = head->next;
				delete head;
				head = prev;
				return 1;
			}
		}
		 prev = head;
	remove(head->next);

}

/*int helpList::connect()
{

	if (!head)
	{
		head=new way2help;
		//tail = head;
		head->disc1 = new char [strlen(disc)+1];
		strcpy(head->disc1,disc);

		head->hours1 = new char [strlen(hours)+1];
		strcpy(head->hours1,hours);

		head->rating1 = rating;

		head->location1 = new char [strlen(location)+1];
		strcpy(head->location1,location);

		head->help1 = new char [strlen(help)+1];
		strcpy(head->help1,help);
		head->next =NULL;
		tail = head;
				return 1;
	}


return 0
}
*/
int helpList::newhelp(char disc [],char hours[], int& rating, char location [], char help [])
{
	if (!head)//to add new help if there was no help 
	{
		head=new way2help;
		//tail = head;
		head->disc1 = new char [strlen(disc)+1];
		strcpy(head->disc1,disc);

		head->hours1 = new char [strlen(hours)+1];
		strcpy(head->hours1,hours);

		head->rating1 = rating;

		head->location1 = new char [strlen(location)+1];
		strcpy(head->location1,location);

		head->help1 = new char [strlen(help)+1];
		strcpy(head->help1,help);
		head->next =NULL;
		tail = head;
				return 1;
	}
	else if(!strcmp(head->disc1,disc)==0)//to appened from tail 
	{
		tail->next = new way2help;
		tail = tail->next;

		tail->disc1 = new char [strlen(disc)+1];
		strcpy(tail->disc1,disc);

		tail->hours1 = new char [strlen(hours)+1];
		strcpy(tail->hours1,hours);

		tail->rating1=rating;

		tail->location1 = new char [strlen(location)+1];
		strcpy(tail->location1,location);

		tail->help1 = new char [strlen(help)+1];
		strcpy(tail->help1,help);

		tail->next = NULL;
		return 1;
	}
}
