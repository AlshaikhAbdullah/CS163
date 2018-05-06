//#include "stops.h"
#include "queue.h"
//#include "stack.h"


int main()
{
	stops stopping;
	stack history;
	queue journy;

	char stop [SIZE];
	char area [SIZE];
	char lodg [SIZE];
	char rate [SIZE];
	int far =0;
	int cost =0;
	char repeat;
	do{
		do{
			cout << "What is the next stop: ";
			cin.get(stop,SIZE,'\n'); cin.ignore(100,'\n');
	
			cout << "Where is is located(state, city): ";
			cin.get(area,SIZE,'\n'); cin.ignore(100,'\n');

			cout << "What is the logding inforamtion: ";
			cin.get(lodg,SIZE,'\n'); cin.ignore(100,'\n');
	
			cout << "\nHow far is it(MILES)\nEnter Digits ONLY: ";
			cin >> far; cin.ignore(100,'\n');

			//enqueue into my queue 
			/////
			journy.enqueue(stop,area,lodg,rate,far);		

		}while(again());
			do{
				cout << "How was the lodging: ";
				cin.get(rate,SIZE,'\n'); cin.ignore(100,'\n');
		
				cout << "\nWhat is the total gas cost\nEnter Digits ONLY: $";
				cin >> cost; cin.ignore(100,'\n');
			
				//to dequeue and push into stack and to catch returned value
				if(!journy.dequeue(stop,area,lodg,rate,far,cost,history)) cout << "\n\nEmpty !!\n\n" << endl;
				cout << "\n\nCurrently you are at this stop:\n\n";
					//to pop and display my top data
					//////
					if(!history.pop())	cout << "\n\nThere's nothing to show.\n\n";
				cout << "\n\nWould you like to see the previous stop(y/n): ";
				cin >> repeat; cin.ignore(100,'\n');
			}while(repeat == 'y' || repeat == 'Y');

	}while(again());
	
return 0;
}
