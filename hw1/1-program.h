//Abdullah Alshaikh - Homework-1 
//CS 163
/*
	program to help the students get assistance in diffrenet subject on campus


*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int SIZE = 200;

struct way2help
{
		char * location1;
		char * disc1;
		char * hours1;
		int  rating1;
		char * help1;
		way2help * next;
		way2help();
		~way2help();


};

class helpList
{
		public:
			helpList();
			~helpList();
			int insert (char disc [], char hours [], int& rating, char location [], char help []);
			int display();
			int displayrate();	
			int editrating(int& rating, char name []);
			int newhelp(char disc [],char hours [], int& rating, char location [], char help []);
			int remove();
			int connect();
		private:
			int remove(way2help*& head);
			int display(way2help * head);
			way2help * head;
			way2help * tail; 
			

};
struct node
{
	//	subject * head;
		char * subject;
		node * next;
		helpList list;
		node();
		~node();
	
};

class tutor
{
		public:
			tutor();
			~tutor();
			int subjects();
			int displayRated();
			int add(char name [], char disc [],char hours [], int& rating, char location [], char help [] );
			int displayAll();
			int removeLow(char name [], char disc [],char hours [], int& rating, char location [], char help [] );
			int newHelp(char name [], char disc [],char hours [], int& rating, char location [], char help [] );
			int editRating(int & rating, char name []);
		//	int copy ();

		private:
		//	int displayRated();
			int removeLow(node *&head);
			//int add ();
			node * head;
			node * tail;
};
