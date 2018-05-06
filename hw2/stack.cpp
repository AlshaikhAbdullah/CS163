#include "queue.h"

stack::stack()
{
	head = NULL;
	top =0;
}
//destructor fro my stack 
//////
stack::~stack()
{
	if(head)//if there's data then delete it
	{	
		delete head;
		head=NULL;
	}	
}

//destructor fro my struct Dnode
/////
Dnode::~Dnode()
{
	//if there's data then delete it
	if(extra)
	{
		delete [] extra;
		extra =NULL; // set it to null
	}
	
}

//to store push data into my stack 
//////
int stack::push(char stop[],char area[],char lodg[],char rate [],int & far,int & cost)
{
	//to create new one if there's data
	if(!head)
	{
		head= new Dnode;
		head->extra = new stops[MAX];
		head->extra[top].create1(stop,area,lodg,rate,far,cost);
		head->next =NULL;
	//	head->extra[top].displayAll();
		top++; // increment the top index
		
		return 1;
	}
	//to create new node if it's full
	else if(top == 5)
	{
		Dnode * temp = new Dnode;
		temp->extra =new stops[MAX];
		temp = head->next;
		top =0;
		temp->extra[top].create1(stop,area,lodg,rate,far,cost);
		head = temp;
		temp->next = NULL;
		++top;
		return 1;
	}
	//to store
	head->extra[top].create1(stop,area,lodg,rate,far,cost);
	++top;// increament my top index
return 1;		
}
//to delete data from my stack
///////
int stack::pop()
{
	if(!head) return 0;
//	show();
	--top; //decreament my top index
	show();
	if(top ==0) // if it's 0 means im at the top so delete the node
	{
		Dnode * temp = NULL;
		temp=head->next;
		delete head;
		head =temp;
		return 1;
	}
	
	return 0;	
}
///
//////
int stack::peek()
{
	if(!head) return 0;
//	head->extra[top-1].displayAll();
	//--top;
	return 1;	

}

// to diaplay the top of the stack
//////
int stack::show()
{
	//if there's nothing return
	///
	if(!head) return 0;
//	int i = top;
	head->extra[top].displayAll();
	//show(head,i);
	//int i = top
return 1;
}


/*
int stack::show(Dnode * head, int & i)
{
	if(!head) return 0;
	head->extra[i].displayAll();
	--i;
	show(head,i);
	if(top==0)
	show(head->next,i);
}*/
