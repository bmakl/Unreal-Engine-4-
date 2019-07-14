#include<iostream>
#include<ctime>

const int MaxLevel = 10;

void PrintIntroduction(int difficulty)
{
	std::cout << "=======================================================================" << std::endl;
	std::cout << "Beginning software..." << std::endl;
	std::cout << "Establishing connection..." << std::endl;
	std::cout << "Identified unique characters..." << std::endl;
	std::cout << "This is a level " << difficulty << " code." << std::endl;

	std::cout << std::endl;			//creating empty spaces for clarity
}
bool PlayGame(int Difficulty, int Guesses)
{
	PrintIntroduction(Difficulty);

	int numbers = 3;
	int guesses = Guesses;

	if (Difficulty >= 6)
	{
		numbers = 4;
	}

	int CodeA = rand() % Difficulty + 1;						//creating the variables we will use later on
	int CodeB = rand() % Difficulty + 1;
	int CodeC = rand() % Difficulty + 1;
	int CodeD = rand() % Difficulty + 1;

	int CodeSum;		//calculating the sum of a, b, and c
	int CodeProduct;		//calculating the product of a,b,c

	if (numbers == 3)
	{
		CodeSum = CodeA + CodeB + CodeC;
		CodeProduct = CodeA * CodeB * CodeC;
	}
	else if (numbers == 4)
	{
		CodeSum = CodeA + CodeB + CodeC + CodeD;
		CodeProduct = CodeA * CodeB * CodeC * CodeD;
	}


	std::cout << "=======================================================================" << std::endl;

	std::cout << "There are " << numbers << " numbers in the code" << std::endl;
	std::cout << "The code adds to " << CodeSum << std::endl;
	std::cout << "The code multiplies to " << CodeProduct << std::endl;
	std::cout << std::endl;


	std::cout << "=======================================================================" << std::endl;
	std::cout << std::endl;

	//Get the player's guess
	int GuessA, GuessB, GuessC, GuessD;
	int GuessSum;
	int GuessProduct;
	std::cout << "Guess the code by entering the numbers separated by spaces, then 'enter' when the code is complete: " << std::endl;

	if (numbers == 3)
	{
		std::cin >> GuessA >> GuessB >> GuessC;
		GuessSum = GuessA + GuessB + GuessC;
		GuessProduct = GuessA * GuessB * GuessC;
	}
	else if (numbers == 4)
	{
		std::cin >> GuessA >> GuessB >> GuessC >> GuessD;
		GuessSum = GuessA + GuessB + GuessC + GuessD;
		GuessProduct = GuessA * GuessB * GuessC * GuessD;
	}

	//Compares player guesses
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "Password accepted." << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		return true;
	}
	else
	{
		--guesses;
		if (guesses > 0)
		{
			std::cout << "Incorrect code" << std::endl;
			std::cout << "You have " << guesses << " attempts before the server locks out." << std::endl;
			return false;
		}
		if (guesses <= 0)
		{
			std::cout << "You have been locked out of the server..." << std::endl;
			std::cout << "Program Terminating..." << std::endl;
			return false;
		}
		

	}
}

int main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	int Guesses = 3;
	while ((LevelDifficulty <= MaxLevel) && (Guesses > 0))									//until all levels are completed or until they run out of guesses
	{
		bool b_LevelComplete = PlayGame(LevelDifficulty, Guesses);
		std::cin.clear();											//Clears any errors
		std::cin.ignore();											//discards the buffer

		if (b_LevelComplete)
		{
			++LevelDifficulty;
		}
		else if (!b_LevelComplete)
		{
			--Guesses;
		}
	}

	if (LevelDifficulty >= 10)
	{
		std::cout << "Full network break-in achieved." << std::endl;
		std::cout << "Accessing encrypted files... " << std::endl;
		std::cout << "Done." << std::endl;
		std::cout << "Mission Complete. Program Terminating..." << std::endl;
	}
	return 0;
}