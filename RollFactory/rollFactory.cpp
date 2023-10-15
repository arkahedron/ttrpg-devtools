#include <iostream>
#include <string>
#include <sstream>
#include <random>

using namespace std; //using declaration for cout, cin, endl and string
using u32 = uint_least32_t;
using engine = std::mt19937;

string globalInput = ""; //User inputed string
bool continueProgram = 1; //If to continue program main loop or not
int rollResult;


int dieType = -1;
int dieAmount = 1;
int modifier = 0;

int dieRoller(int dieSides);


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

//Function for checking if user input is a valid float and only continuing if it exists
float cinputParseFloat() {

	string inputToParse = "";
	float parsedFloatOutput = 0;

	//Test first user input line stringstream data if float
	getline(cin, inputToParse);
	stringstream ss(inputToParse);
	if (ss >> parsedFloatOutput) { return parsedFloatOutput; }

	//Refuse non-float user input and propmt number input
	while (true) {
		cout << " (please enter a valid number): ";
		getline(cin, inputToParse);
		stringstream ss(inputToParse);
		if (ss >> parsedFloatOutput) { break; }
	}
	return parsedFloatOutput;
}


int main()
{
	
	

	while (continueProgram == 1)
	{
		cout << "How many dice do you want to roll?" << endl;
		dieAmount = cinputParseFloat();

		cout << "What die do you want to roll?" << endl;
		cout << "4, 6, 8, 10, 12, 20" << endl;
		dieType = cinputParseFloat();

		cout << "What mod do you want to add?" << endl;
		modifier = cinputParseFloat();

		for (int i = dieAmount; i > 0; i--)
		{
			cout << (i == dieAmount ? " " : ", ") << dieRoller(dieType);
		}


		exitPrompt();
	}
	return 0;
}


int dieRoller(int dieSides)
{
	random_device os_seed;
	const u32 seed = os_seed();
	engine generator(seed);
	uniform_int_distribution< u32 > distribute(1, dieSides);
	rollResult = modifier+distribute(generator);

	return rollResult;
}