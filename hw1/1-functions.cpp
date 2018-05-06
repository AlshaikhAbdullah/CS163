#include "1-program.h"

tutor::tutor()
{
	head= NULL;
	tail = NULL;
//	head->subject = NULL;

}
node::node()// initialzie the data memebers in the struct
{

	subject = NULL;
}

node::~node()
{
	if(subject)
	{
		delete [] subject;
		subject = NULL;
	}
	next = NULL;
}

tutor::~tutor()
{
	node * prev = NULL;
	while(head)
	{
		if(head->subject)
		{
			delete [] head->subject;
			head->subject=NULL;
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

/*
int tutor::displayRated()
{

		if (!head)return 0;



return 1;
}
*/


int tutor::add(char name [],char disc [], char hours [], int& rating, char location [], char help [])
{
	int len = strlen(name)+1;

	if(!head)
	{
		head = new node;
		head->subject = new char [len];
		strcpy(head->subject,name);
		head->list.insert(disc,hours,rating,location,help);
		head->next= NULL;	
		tail = head;	
		return 1;
	 }
	else 
	{
		tail->next = new node; 
		tail = tail->next;
		tail->subject = new char [strlen(name)+1];
		strcpy(tail->subject,name);
		tail->list.insert(disc,hours,rating,location,help);
		tail->next=NULL;
	}
return 1;
}

int tutor::displayAll()
{
	if(!head)
	{
		return 0;
	}
	node * current = head;
	while (current) // to display each subject with its help infos
	{
		cout <<"\nSubject Is: " << current->subject <<endl;
		current->list.display();
		current = current->next;
	}
return 1;
}

int tutor::editRating(int& rating, char name[])
{
	if(!head)
		return 0;
	if(rating > 0)
	{
		node * current = head;
		while(current)
		{
			if(strcmp(current->subject,name)==0)
			{
					if(!current->list.editrating(rating,name))
					{	
						

					}
			}
			current = current->next;
		}
	}
	else // just to display subjects with their ratings first 
	{
		node * current = head;
		while(current)
		{
			cout << current->subject << ": "
			 << current->list.editrating(rating,name) <<endl;
			current = current->next;	
		}
		return 1;
	}
return 1;
}

int tutor::displayRated()
{
	if(!head)
		return 0;
	else
	{
		node * current = head;
		while(current)
		{
			cout <<"The subject is: " <<  current->subject << endl;

			if(!current->list.displayrate())
			{	
				cout << "The subject has no top rating."<<endl;				
			}	
		current = current->next;
		}
	return 1;
	}
}

int tutor::removeLow(char name [], char disc [],char hours [], int& rating, char location [], char help [] )
{
	if(!head)
	{
		return 0;
	}
		node * current = head;
		while(current) // to delete the middle nodes
		{		
		//	if(current->list.remove())
		//	{
		//		prev->next = current->next;
		//		delete current;
		//	}
		//	prev = current;
			while(!current->list.remove())// to reconnect the second list in the most ghetto way possible 
			{
				newHelp(name,disc,hours,rating,location,help); 
				current->list.remove();
			}
			current = current->next;
		}
		

return 1;
}

int tutor::removeLow(node*& head)//wrapper to delete last node
{
		if(!head) return 0;
		if(head->list.remove())
		{
			if(!head->next)
			{
				delete head;
				head=NULL;
				return 1;
			}
		}
		removeLow(head->next);
}

int tutor::newHelp(char name [], char disc [],char hours [], int& rating, char location [], char help [] )
{
	if(!head) // to check if there's data
	{
		return 0;
	}
	else
	{
		node * current = head;
		while(current)// to look for a matched subject
		{
			if(strcmp(current->subject,name)==0)
			{
				current->list.newhelp(disc,hours,rating,location,help);
				//to add the help for the match supject
				return 1;
			}

			current = current->next;
		}
	}
		
return 1;

}

int tutor::subjects()//just to display subjects
{

	node * current = head;
	while(current)
	{
		cout << "\n" << current->subject << endl;

		current = current->next;
	}
return 1;
}
