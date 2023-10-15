#include <iostream>
#include <string>
#include <sstream>
#include <random>

using namespace std; //using declaration for cout, cin, endl and string

string globalInput = ""; //User inputed string
bool continueProgram = 1; //If to continue program main loop or not


//Prompt for user to exit program if "x" or "X" is inputted
void exitPrompt() 
{
	cout << endl << "(type X to exit)" << endl;
	getline(cin, globalInput);
	//Exit program if user inputs "x" key
	if (globalInput == "x" or globalInput == "X")
	{
		cout << "exiting program..."; 
		continueProgram = 0;
	}
}



int main()
{



	while (continueProgram == 1)
	{



		exitPrompt();
	}
	return 0;
}

