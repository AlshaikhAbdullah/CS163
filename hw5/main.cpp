//main function file which will have main which is the client interface and all error messages
//and the temp arrays, i will begin by declaring variables and then prompt the user for menu and call functions for eah choice....

#include "graphs.h"




int main()
{
	Goal main,temp;
	table graph;
	char toDo [SIZE];
	char do1 [SIZE];
	char do2 [SIZE];
	char do3 [SIZE];
	char plan1 [SIZE], connect[SIZE];
	char choice;
	
	cout << "\nWelcome !!\n\nI Will Help Manage Your Goals For Winter Break\n\n"
	<< "Press Any Key To Continue ..."; 
	cin >> choice; cin.ignore(100,'\n');

	do{
		cout << "\n1-Add a Plan.\n" << "2-Display All Plans Connected.\n" << "3-Connect Goals.\n" << "4-Find Tasks For a Goal.\n" << endl;
		cout << "Choose(1-4): "; cin >> choice; cin.ignore(100,'\n');

		if(choice == '1')
		{
			cout << "Enter Your Plan: "; cin.get(toDo,SIZE,'\n'); cin.ignore(100,'\n');
			cout << "\nEnter First Thing To Do: "; cin.get(do1,SIZE,'\n'); cin.ignore(100,'\n');
			cout << "\nEnter Second Thing To Do: "; cin.get(do2,SIZE,'\n'); cin.ignore(100,'\n');
			cout << "\nEnter Third Thing To Do: "; cin.get(do3,SIZE,'\n'); cin.ignore(100,'\n');
			cout << "\nEnter Extra Thing to have: "; cin.get(plan1,SIZE,'\n'); cin.ignore(100,'\n');
		
			main.create(toDo,do1,do2,do3,plan1);
			if(graph.insertVertex(main)) cout << "\n\nGoal Stored Successfully.\n";
			else cout << "\n\nERORR !! Couldn't Store Goal.\n";
		}
		if(choice == '2')
			if(graph.displayAll()) cout << "\n\nThese Are Connected Goals\n\n";
			else cout << "\n\nThere Are No Connected Goals!!\n\n";
		if(choice == '3')
		{
			cout << "Enter Goal to connect: "; cin.get(toDo,SIZE,'\n'); cin.ignore(100,'\n');
			cout << "Enter Other Goal to connect to: "; cin.get(connect,SIZE,'\n');
			if(graph.insertEdge(toDo,connect) && graph.insertEdge(connect,toDo)) cout << "\n\nGoals Connected.\n";
			else cout << "\n\nERROR !!! Couldnt Connect Goals !!\n";
		}
		if(choice == '4')
		{
			cout << "Enter The Goal: "; cin.get(toDo,SIZE,'\n'); cin.ignore(100,'\n');
			if(graph.retrieve(toDo)==-1) cout << "\n\nERROR !! Goal Was Not Found !!\n\n";
			else graph.find(toDo);
		}
	}while(again());
	cout << "\nBest Of Luck !! :) " << endl;

return 0;
}
