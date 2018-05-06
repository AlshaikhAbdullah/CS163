//this is the .cpp file for the table class functions
//this file will have all table functions only and it will be taking care of all of it
//opreations

#include "graphs.h"

//what the constructor will do is,
//it will allocate memory for the adjacencey list,
//then using a for loop, it will go through each index and set each index to null,
//and head pointer to null
//it will also initilizie list size to the the integer size
table::table(int size)   
{
	adjacencey_list = new vertex[size];
	list_size =size;
	for(int i =0;i<size;++i)
	{
		adjacencey_list[i].head=NULL;
		adjacencey_list[i].goal=NULL;
		adjacencey_list[i].visit=NULL;
	}
}
//the destructor will be taking care of deallocate memory,
//it will check if theres data first,then,
//it will use current pointer to traverse and delete every vertex and edge 
//then it will delete adjacencey and set everything to null 

table::~table()
{
	node * current =NULL;
	if(adjacencey_list)
	{
		for(int i=0;i<list_size;++i)
		{
				while(adjacencey_list[i].head)
				{
					current =adjacencey_list[i].head->next;
					delete adjacencey_list[i].head;
					adjacencey_list[i].head=current;
				}
			delete adjacencey_list[i].goal;
			adjacencey_list[i].goal=NULL;
			adjacencey_list[i].head=NULL;
		}
	}
		delete []adjacencey_list;
		adjacencey_list=NULL;
}

//this functon will be taking care of inserting vertex,
//it will start with a for loop to find the first open space to insert data,
//once it finds it, it will create memory for it,
//then it will call manging class copy to store data into that vertex
//it will return 1 if that happened successfully,
//else it will return 0 back to main 
int table::insertVertex(Goal & to_add)
{
	for(int i=0;i<list_size;++i)
	{
		if(!adjacencey_list[i].goal)
		{
			adjacencey_list[i].goal=new Goal;
			adjacencey_list[i].goal->copy(to_add);
			return 1;
		}
	}
return 0;
}
//this function will be taking care of attaching vertices,
//it will get the location of vertices to attach them, it will connect by dierect edges,
//if therse locations weren't found it will return 0 back to the calling routine
//else,once it finds locations,it will create a new connection and attach these vertices,
//finally, it will connect the adjacencey list and return 1 back to the calling routine 
int table::insertEdge(char * currentVertex, char * attach)
{
	int current = retrieve(currentVertex);
	int connect = retrieve(attach);
		if(current == -1 || connect == -1) return 0;
		else
		{
			node * temp = new node;
			temp->adjacent = &adjacencey_list[connect];
			temp->next = adjacencey_list[current].head;
			adjacencey_list[current].head = temp;
			return 1;
		}

return 0;
}

//this function will start with a for loop to get the right index,
//once it finds a match for the key by calling the managing class compare,
//it will return that index,other than that it will return a -1 which means key was not found
int table::retrieve(char * key)
{
	for(int i=0;i<list_size;++i)
	{
		if(adjacencey_list[i].goal)
		{
			if(adjacencey_list[i].goal->compare(key))
				return i;
		}
	}
return -1;
}

//the wrapper function for displayAll,
//it will have a bool connection that will catch if there was a connectd vertices,
//so that it can return true and false back to main
int table::displayAll()
{
	bool connection = false;
	return displayAll(adjacencey_list->head,connection);
}
//recursive function for display all,
//what this recursive function will do is, it will begin with a for loop,
//to get all the length of the list,
//then it will use recursion to go to adjacent elements in the list,
//it will call the unVisit function to set falgs
int table::displayAll(node * head,bool & connection)
{
	for(int i =0;i<list_size;++i)
	{
		if(!adjacencey_list[i].head)
		{
			unVisit();
			return connection;
		}
		else if(adjacencey_list[i].visit) 
			return displayAll(adjacencey_list[i].head->next,connection);
		else if(!adjacencey_list[i].visit)
		{
			//connection will catch if there was at least one connection
			connection = adjacencey_list[i].visit =true;
			adjacencey_list[i].goal->display();
		}
	}
return 1;
}

//this function will set visited flag to false, after the displayAll function is complete
//that way next time displayAll first travarsal occur,
//it dosen't leave the function immediatley because all the flags are true
bool table::unVisit()
{
	node * current =NULL;
	for(int i=0;i<list_size;++i)
	{
		current = adjacencey_list[i].head;
		while(current)
		{
			if(current) current->adjacent->visit=false;

			current = current->next;
		}
	}
return true; 
}
//wrapper function for the recursive function of find
int table::find(char * to_find)
{
	return find(to_find,adjacencey_list->head);
}

//this function will be taking care of finding the vertex recursively 
//and call the manaing class to display it's tasks 
//if the vertex connected its going to do the recursive call to check them and check then display
////
int table::find(char * to_find, node *head)
{
	for(int i=0;i<list_size;++i)
	{
		if(adjacencey_list[i].goal)
		{
			if(adjacencey_list[i].goal->info(to_find))
				return 1;
		}
		else if(adjacencey_list[i].head->next)
			return find(to_find,adjacencey_list[i].head->next);	
	}
return 1;
}
