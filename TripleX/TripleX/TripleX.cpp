#include<iostream>
#include<math.h>
#include<ctime>
using namespace std;

void PlayGameAtDifficulty(int difficulty)
{
	int codes = 3;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int product = 0;
	int tries = 3;
	int sum = 0;
	
	cout << "=======================================================================" << endl;
	cout << "Beginning software..." << endl;
	cout << "Establishing connection..." << endl;
	cout << "Identified " << codes << " unique characters..." << endl;
	cout << "This is a level " << difficulty << " code." << endl;

	cout << endl;
	cout << endl;
	cout << "=======================================================================" << endl;

	cout << "There are " << codes << " unique numbers in the code" << endl;
	cout << "The code mulitplies to " << product << endl;
	cout << "The code adds to " << sum << endl;

	system("Pause");
}



/*int main()
{
	int difficulty = 1;
	
	return 0;
}*/
