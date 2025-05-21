#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int num, guess;
	srand(time(0));
	num = rand() % 20 + 1;
	cout << "Guess My Number Game"<<endl<<endl;

	do
	{
		cout << "Enter a guess between 1 and 20 : ";
		cin >> guess;

		if (guess > num)
			cout << "Your guess is higher than the number."<<endl<<"Guess again!"<<endl<<endl;
		else if (guess < num)
			cout << "Your guess is lower than the number."<<endl<<"Guess again!"<<endl<<endl;
		else
			cout << "You guessed the correct number!!!"; 
	} while (guess != num);
	return 0;
}