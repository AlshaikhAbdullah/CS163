#include <iostream>
#include <cctype>
#include <cstring>
#include "stops.h"
using namespace std;


//Dnode for the stack
/////
struct Dnode
{
	stops * extra;
	Dnode * next;
	~Dnode();
};

class stack
{
	public:
		stack();
		~stack();
		
		int show();
		int push(char stop[],char area[],char lodg[],char rate [],int & far,int & cost);
		int pop();
		int peek();
	private:
		//int show(Dnode * head, int & i);
		Dnode * head;
		int  top;
};

//node for the queue
////
struct node
{
	stops trip;
	node * next;
};

class queue
{
	public:
		queue();
		~queue();
		int copy(char stop[],char area[],char lodg[],char rate [],int & far,int & cost,stack &history);

		int display();
		int enqueue(char stop[],char area[],char lodg[],char rate [],int & far);
		int dequeue(char stop[],char area[],char lodg[],char rate [],int & far,int & cost,stack & history);
		int peek();
	private:
		int queueremove(node * &rear, node *&temp);

		node * rear;
};
