#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(time(NULL));
  

  int number = 0;  // sets number

int guess = 0;
 char again = 'Y'; //for luser prompted play again loop
 while(again == 'y' || again == 'Y')
 {
   int number = (rand() % 100) + 1; //picks random number between 1 and 100
       do
	 {
	   
        cout << "Guess (1 - 100)" << endl; //user guess number
	cin >> guess;

	//scenarios on user guesses
	if (guess > number)
	  cout << "Guess is too high" << endl;
	else if (guess < number)
	  cout << "Guess is too low" << endl;
 	else if(guess == number)
	  cout << "Congrats you got it!!!" << endl;


	 }while (guess != number); //to loop until guess is same as answer


     cout << "do you want to play again? (y/n)";
     cin >> again; // change control
     srand(time(NULL));

     
 }
 cout << "Thanks for playing";
   return 0;
}
