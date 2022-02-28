#ifndef HW3_H
#define HW3_H
#include <string>

using namespace std;

void ReverseArray(int arr[], int length);
/* 
*  I believe that length needs to be added as a parameter because
*  it is needed to split the array in half and swap contents of indices. 
*  Without that information a method would have to be implemented to find 
*  the length and space wouldn't be O(1).
*/
bool HasBalancedParentheses(string input);
bool InDogish(string input);
bool DogishHelper(string word, char letter);
bool InXish(string input, string x);
bool XishHelper(string word, char letter);

#endif
