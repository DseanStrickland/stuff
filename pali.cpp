//Arjun Pai
//Palindrome
//September 27th, 2023 

#include <iostream>
#include <cstring>

using namespace std;

int main () {

   //Initialize 
   char inputArr[81];
   char filteredArr[81];
   char arrBackwards[81];
   int count = 0;
   int newCount = 0;

   //Input
   cout << "Input: " << endl;
   cin.get(inputArr, 80); 


   //Filters everything
   for (int i = 0; i < strlen(inputArr) + 1; i++) { 
      if (ispunct(inputArr[i]) == false && inputArr[i] != ' ') { 
         filteredArr[count] = tolower(inputArr[i]);
         count++;
      }
   }

   //Reverses array
   for (int j = count-2; j > -1; j--) {
      arrBackwards[newCount] = filteredArr[j];
      newCount++;
   }
   arrBackwards[newCount] = '\0'; 

   //Check for palindrome
   if (strcmp(filteredArr, arrBackwards) == 0) {
      cout << "Palindrome." << endl;
   }
   else {
      cout << "Not a palindrome." << endl;
   }

   return 0;
}
