#include "queue.h"
//constructor
///queue
queue::queue()
{
	rear= NULL;
}

queue::~queue()
{
	// if there's data then delete 
	if(rear)
	{
		node * temp =rear->next;
		 queueremove(rear,temp);
	}
}

//recursive function to delete all nodes
///////
int queue::queueremove(node * &rear,node * &temp)
{
	if(temp == rear) 
	{
		delete rear;
		rear=NULL;
		return 1;
	}
	delete temp;
return 	queueremove(rear,temp->next);

}

//to store data into my queue 
////////
int queue::enqueue(char stop[],char area[],char lodg[],char rate[],int & far)
{
//	node * temp1 = new node;
	if(!rear)//if the CLL is empty
	{	rear= new node;
		rear->trip.create(stop,area,lodg,rate,far);
		rear->next=rear;
		return 1;
	}

	if(rear->next ==rear) //if there's only one node
	{	node * first = rear;
		node * temp = new node;
		temp->trip.create(stop,area,lodg,rate,far);	
		first->next = temp;
		rear = temp;
		rear->next = first;
		return 1;
	}

	// when there are multiple nodes
	node * first = rear->next;
	node * last = rear;
	node * temp = new node; 
	temp->trip.create(stop,area,lodg,rate,far); // to call the manging class to create these data
	
	last->next = temp;
	rear=temp;
	rear->next = first;
	return 1;
}

/// display function for my queue even though i dont think ill need it
//////
int queue::display()
{
	// if there's no data retrun 
	if(!rear) return 0;
	node * first = rear->next;

	while(first !=rear)
	{
		first->trip.displayAll();
		first= first->next;
	}

	rear->trip.displayAll();

return 1;
}

// function to copy all data before dequeuing into temp variables
/////
int queue::copy(char stop[],char area[],char lodg[],char rate [],int & far,int & cost,stack & history)// function to copy quesue's data and then push them to the stack
{
	
	node * first = rear->next;
	first->trip.copy(stop,area,lodg,far); // to have access of the queue data and store them
	history.push(stop,area,lodg,rate,far,cost); // so i can push into my stack everytime i get data

return 1;
}

// delete data from my queue but copy data before that 
///////
int queue::dequeue(char stop[],char area[],char lodg[],char rate [],int & far,int & cost,stack & history)
{
	// if there's nothng return 
	////
	if(!rear) return 0;
	if(rear->next ==rear)
	{
		copy(stop,area,lodg,rate,far,cost,history);//to call the function that will copy queue's data
		delete rear; 
		rear=NULL;
	//	rear->next = rear;
		return 1;
	}
	node * first = rear->next; // hold to first node;
	copy(stop,area,lodg,rate,far,cost,history);
	rear->next = first->next; // reconnect
	delete first;// remove first node
	return 1;
}
