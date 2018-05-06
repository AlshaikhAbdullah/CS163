//this .h file will have struct vertex which will have object pointer to Goal "managing" class
//and a visit bool to store false and true and a head pointer to the node struct,
//which will have an adjecent pointer to struct vertex and next pointer,
//also the table class which will be my ADT and it will have all the important functions,
//that will be running this program using the graph data structure concept.

#include "goals.h"

struct vertex
{
	Goal * goal; //object pointer for manging class
	struct node * head;
	bool visit;
};



struct node
{
	vertex * adjacent;
	node *next;
}; 







class table
{
	public:
		//functions comments avilable in .cpp file 
		table(int size = 5);
		~table();
		int insertEdge(char * currentVertex,char * attach);
		int insertVertex(Goal & to_add);
		int displayAll();
		int retrieve(char * key);
		int find(char * to_find);
	private:
		vertex * adjacencey_list;
		int list_size;
		int displayAll(node * head,bool &connection); // recureive function for display 
		bool unVisit();
		bool visit();
		int find(char * to_find,node *head);
};
