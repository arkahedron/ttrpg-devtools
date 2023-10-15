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
int dieTypes= 0;
int dieSides = -1;
int dieAmount = 1;
int modifier = 0;

float totalInput;
int finalDieResult;


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



float rollDiceBatch()
{

	float* dieArray;
	float dieSum = 0;
	int rolledDie;
	int dieIndex;
	int arrayLength = dieAmount;

	//Generate and validate array size
	dieArray = new (nothrow) float[arrayLength];
	if (dieArray == nullptr) { cout << "(error lol)"; }
	else {
		for (dieIndex = 0; dieIndex < arrayLength; dieIndex++) {
			rolledDie = dieRoller(dieSides);
			cout << (dieIndex == 0 ? " " : ", ") << rolledDie;
			dieArray[dieIndex] = rolledDie;
			dieSum += rolledDie;
		}
	}
	
	cout << endl;

	totalInput = dieSum;

	delete[] dieArray; //Delete sum array from memory heap

	return dieSum;
}


float addAllDiceRolls()
{
	float* totalArray;
	float totalSum = 0;
	
	int totalIndex;
	int totalLength = dieTypes;

	totalArray = new (nothrow) float[totalLength];
	if (totalArray == nullptr) { cout << "(error lol)"; }
	else {
		for (totalIndex = 0; totalIndex < totalLength; totalIndex++) {

			totalSum += totalInput;
		}
	}
	finalDieResult = totalSum + modifier;
	cout << endl <<" Final dice roll result: "<< finalDieResult << endl;
	
	delete[] totalArray; //Delete sum array from memory heap

	return finalDieResult;
}


int main()
{
	cout << "Welcome to the Roll Factory" << endl<< endl;
	

	while (continueProgram == 1)
	{
		cout << "How many DIFFERENT TYPES of dice do you want to roll?" << endl << " > ";
		dieTypes = cinputParseFloat();

		cout << "What MODIFIER do you want to add?" << endl << " > ";
		modifier = cinputParseFloat();

		for (int i = dieTypes; i > 0; i--)
		{

			cout << "What SIDED die do you want to roll?" << endl<< " > ";
			dieSides = cinputParseFloat();

			cout << "HOW MANY " << dieSides << " sided dice do you want to roll?" << endl << " > ";
			dieAmount = cinputParseFloat();

			rollDiceBatch();

		}
		
		addAllDiceRolls();

		
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
	rollResult = distribute(generator);

	return rollResult;
}