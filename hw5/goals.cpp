//this file will have functions for the managing class Goal,
//and the bool again function it will include the graphs.h file only 
//all functions comments follows ...

#include "graphs.h"

//the constructor will be taking care of setting al the char pointers to null,
//to begin with.
Goal::Goal()
{
	name = NULL;
	first = NULL;
	second = NULL;
	third = NULL;
	plan =NULL;
}

//the destructor will be taking care of deallcating memory 
//it will check if there's data so that it doesnt delete a null pointer
//if there's data it will delete it and set it to null,
//it will do that for every private memeber of the class, all the char pointers
Goal::~Goal()
{
	if(name)
	{
		delete [] name;
		name =NULL;
	}
	if(first)
	{
		delete [] first;
		first = NULL;
	}
	if(second)
	{
		delete [] second;
		second = NULL;
	}
	if(third)
	{
		delete [] third;
		third = NULL;
	}
	if(plan)
	{
		delete [] plan;
		plan = NULL;
	}
}

//this function will be taking care of,
//taking data passed from main deierctly and stroed into private members
//so that i can use these data stored in the copy function when i create my data structure 
int Goal::create(char toDo[],char do1 [],char do2[],char do3[],char plan1[])
{
	if(name) //to check if theres data 
	{
		delete [] name;
		name =NULL;
	}
	if(first) 
	{
		delete [] first;
		first = NULL;
	}
	if(second)
	{
		delete [] second;
		second = NULL;
	}
	if(third)
	{
		delete [] third;
		third = NULL;
	}
	if(plan)
	{
		delete [] plan;
		plan = NULL;
	}

	int len = 0;

		len = strlen(toDo)+1; name = new char[len]; strcpy(name,toDo);
		len = strlen(do1)+1; first = new char[len]; strcpy(first,do1);
		len = strlen(do2)+1; second = new char[len]; strcpy(second,do2);
		len = strlen(do3)+1; third = new char [len]; strcpy(third,do3);
		len = strlen(plan1)+1; plan = new char[len]; strcpy(plan,plan1);
return 1;
}

//this function will be taking care of, 
//copying data stored by user into the vertex,
//it will get the length of each temporary array and it will allocate memory based on that
//then it will copy the data into the private members 
int Goal::copy(Goal & to_copy)
{

	int len=0;
	if(name) //to chck if there's data delete it first
	{
		delete [] name;
		name =NULL;
	}
	len = strlen(to_copy.name) +1; //get the length 
	name = new char [len];//allocate memory 
	strcpy(name,to_copy.name);//copy from the class object where data is stored
	//and same for the rest
	/////////
	if(first)
	{
		delete [] first;
		first = NULL;
	}
	len = strlen(to_copy.first)+1;
	first = new char [len];
	strcpy(first,to_copy.first);
	if(second)
	{
		delete [] second;
		second = NULL;
	}
	len = strlen(to_copy.second)+1;
	second = new char [len];
	strcpy(second,to_copy.second);
	if(third)
	{
		delete [] third;
		third = NULL;
	}
	len = strlen(to_copy.third)+1;
	third = new char [len];
	strcpy(third,to_copy.third);
	if(plan)
	{
		delete [] plan;
		plan = NULL;
	}
	len = strlen(to_copy.plan)+1;
	plan = new char [len];
	strcpy(plan,to_copy.plan);
		
	return 1;
}

//this function will be taking care of,
//comparing data with one 
bool Goal::compare(char compare[])
{
	if(strcmp(compare,name) == 0) return true;
	else return false;
}
//this function will be taking care of displaying,
//connected vertecies it will display the goal and it's tasks
////
int Goal::display()
{
	cout << "\nPlan is: " << name << endl;
	cout << "Task 1 To Do is: " << first << endl;
	cout << "Task 2 To do is: " << second << endl;
	cout << "Task 3 To do is: " << third << endl;
	cout << "Task 4 To Do is: " << plan << endl << endl;
return 1;
}

//this function was suppose to display tasks for a goal,
//but i believe that was not requiered 
int Goal::info(char toFind [])
{
	if(strcmp(toFind,name) ==0)
	{
		cout << "\n\nThe Tasks For This Goal Are.\n\n"
		<< "First task is: " << first 
		<< "\nSecond Task is: " << second
		<< "\nThird Task is: " << third
		<< "\nLast Task is: " << plan << endl << endl;
		return 1;
	}
return 0;
}

//just a function to repeat process multiple times by calling it in loops 
bool again()
{
	char response;

	cout << "\nWould you like to start from the beginning(y/n): ";
	cin >> response; cin.ignore(100,'\n');
	if(response == 'y' || response == 'Y')
		return true;
	else return false;
}
