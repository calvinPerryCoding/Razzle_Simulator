//If you are not sure what the game is watch the facebook video in the references

//Required for program to run
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Class that contains input validation methods
class InputValidation
{
public:
	double numberValidation(double number)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> number;

			return number;
		}
	}
	void errorMessage()
	{
		cout << "\nERROR: You Must Enter A Number\n";

	}
};

int main()
{
	cout << "This program was written by Calvin Perry\n\n";

	//creates object of classes so main function can access methods in class (W3schools, n.d.)
	InputValidation inputValidationObject;

	//"You need to give the randum number generator a seed. This can be done by taking the current time, as this is hopefully some kind of random." (Tune2fs, 2011)
	srand(time(0));

	//Declare Variables
	int marbleSum, dollarsSpent = 0, dollarRate = 1;
	double score = 0, totalPrizeWorth, housePrize = 0, additionalPrize = 0, hoursOfLife, secondsOfLife = 0;

	
	cout << "How much is your prize worth?\n";
	cin >> totalPrizeWorth;
	//Validates Input (Lang, 2017)	
	while (cin.fail())
	{
		inputValidationObject.errorMessage();
		totalPrizeWorth = inputValidationObject.numberValidation(totalPrizeWorth);
	}

	do
	{
		//Random function (Cplusplus, n.d.)
		//8 Marbles
		//Each marble can land on a number 1-6
		int marble1 = rand() % 6 + 1;
		int marble2 = rand() % 6 + 1;
		int marble3 = rand() % 6 + 1;
		int marble4 = rand() % 6 + 1;
		int marble5 = rand() % 6 + 1;
		int marble6 = rand() % 6 + 1;
		int marble7 = rand() % 6 + 1;
		int marble8 = rand() % 6 + 1;

		//Sum of all marbles 
		marbleSum = marble1 + marble2 + marble3 + marble4 + marble5 + marble6 + marble7 + marble8;

		//Score Chart (Goodmagic, n.d.)
		//H.P. can mean different things depending on who is playing
		//For this simulator H.P means House Prize, but cost an aditional dollar to play
		if (marbleSum == 18 || marbleSum == 38 || marbleSum == 19 || marbleSum == 37)
		{
			cout << "How much is the house prize worth?\n";
			cin >> housePrize;
			//Validates Input (Lang, 2017)	
			while (cin.fail())
			{
				inputValidationObject.errorMessage();
				housePrize = inputValidationObject.numberValidation(housePrize);
			}

			dollarRate = dollarRate + 1;
			totalPrizeWorth = totalPrizeWorth + housePrize;
		}

		//1.5 Points
		else if (marbleSum == 42 || marbleSum == 15 || marbleSum == 41 || marbleSum == 14)
		{
			score = score + 1.5;
		}

		//10 Points (automatic win)
		else if (marbleSum == 8 || marbleSum == 48)
		{
			score = score + 10;
		}

		//5 Points
		else if (marbleSum == 45 || marbleSum == 13 || marbleSum == 10 || marbleSum == 11 || marbleSum == 44 || marbleSum == 12 || marbleSum == 43)
		{
			score = score + 1.5;
		}

		//8 Points 
		else if (marbleSum == 46 || marbleSum == 9)
		{
			score = score + 8;
		}

		//.5 Points
		else if (marbleSum == 40 || marbleSum == 17 || marbleSum == 39 || marbleSum == 16)
		{
			score = score + .5;
		}

		//ADD (Another prize is added, but it cost an additional dollar to play)
		else if (marbleSum == 29)
		{
			cout << "How much is the additional prize worth?\n";
			cin >> additionalPrize;
			//Validates Input (Lang, 2017)	
			while (cin.fail())
			{
				inputValidationObject.errorMessage();
				additionalPrize = inputValidationObject.numberValidation(additionalPrize);
			}

			dollarRate = dollarRate + 1;
			totalPrizeWorth = totalPrizeWorth + additionalPrize;
		}

		//Keeps track of dollars
		dollarsSpent = dollarsSpent + dollarRate;

		//Asuming it takes 10 seconds per turn
		secondsOfLife = secondsOfLife + 10;

		cout << "Current Score: " << score << " out of 10\n";
	} 
	while (score != 10 && score < 10);

	//converts seconds to hours
	hoursOfLife = secondsOfLife / 3600;

	if (dollarsSpent < totalPrizeWorth)
	{
		cout << "\nYou spent $" << dollarsSpent << " and earned $" << totalPrizeWorth << " worth of prizes, congratulations you beat the system, I hope it was worth " << hoursOfLife << " hours of your life\n\n";
	}

	else if (dollarsSpent > totalPrizeWorth)
	{
		cout << "\nYou spent $" << dollarsSpent << " and earned $" << totalPrizeWorth << " worth of prizes, you got screwed, I hope it was worth " << hoursOfLife << " hours of your life\n\n";
	}

	else if (dollarsSpent = totalPrizeWorth)
	{
		cout << "\nYou spent $" << dollarsSpent << " and earned $" << totalPrizeWorth << " worth of prizes, you broke even, I hope it was worth " << hoursOfLife << " hours of your life\n\n";
	}

	system("pause");
}

// References APA 7th Edition


// Cplusplus. (n.d.). Rand. cplusplus.com - The C++ Resources Network. https://www.cplusplus.com/reference/cstdlib/rand/

// Goodmagic. (n.d.). razzlechart [Photograph]. https://www.goodmagic.com/websales/midway/razzle.htm. https://www.goodmagic.com/websales/midway/photos/razzlechart.jpg

// Lang, J. (2017, April 29). C++ input validation. Stack Overflow. https://stackoverflow.com/questions/43699399/c-input-validation

// Lax, R. (2020, February 26). Facebook. Facebook. https://www.facebook.com/realRickLax/videos/this-illegal-game-is-a-total-scam-razzle-dazzle-revealed-the-math-and-psychology/224799581899310/

// Tune2fs. (2011, October 13). Same random numbers every time I run the program. Stack Overflow. https://stackoverflow.com/questions/7748071/same-random-numbers-every-time-i-run-the-program

// W3schools. (n.d.). C++ class methods.W3Schools Online Web Tutorials. https://www.w3schools.com/cpp/cpp_class_methods.asp

// Wikipedia. (2005, November 25). Razzle (game). Wikipedia, the free encyclopedia. Retrieved August 8, 2021, from https://en.wikipedia.org/wiki/Razzle_(game)