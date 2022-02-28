#include <iostream>
#include <string>

using namespace std;

/****
* PSEUDOCODE:
*  Goals:
*  - return an array that is the reverse of the array passed to the 
*    function
*  - minimize time spent
*  Algorithm:
*  declare int temp
*  for first half of indices of arr[]
*    temp equals arr[i]
*    arr[i] equals arr[last index minus i]
*    arr[last index minus i] equals temp
*/

void ReverseArray(int arr[], int length) {

  int temp; // used to swap elements in array

  for(int i = 0; i < length/2; i++) {
    temp =arr[i];
    arr[i] = arr[length-1-i];
    arr[length-1-i] = temp;
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - determine if a string of parentheses is balanced or not
*  - minimize time spent
*  Algorithm:
*  declare a length variable initialized to length of input
*  declare bool balanced initialized to true
*  declare int count initialized to 0
*  for each character in input
*    if character is ')'
*      increment count
*    else
*      decrement count
*    if count falls below 0
*      balanced is false (indicates a closed parenthesis came 
*      before an open parenthesis)
*  if count doesn't equal 0 after navigating all characters
*    balanced is false (indicates there aren't an equal amount of
*    open and closed parentheses)
*  return balanced
*/

bool HasBalancedParentheses(string input) {
  int length = input.length(); // length of input
  bool balanced = true; // indicates if balanced
  int count = 0; // used to count parentheses

  for(int i = 0; i < length; i++) {
    if(input[i] == '(') {
      count++;
    } else {
      count--;
    }
    
    if(count<0) {
      balanced = false;
    }
  }

  if(count != 0) {
    balanced = false;
  }

  return balanced;
}

/****
* PSEUDOCODE:
*  Goals:
*  - determine recursively if a char is in a string
*  - minimize time spent
*  Algorithm:
*  if a string is empty
*    return false (no more opportunites to find the character)
*  if first character is the character being searched for
*    return true
*  else
*    return this function with the first letter removed this time
*/

bool DogishHelper(string word, char letter){
  if(word == "") {
    return false;
  }
  if(word[0] == letter) {
    return true;
  } else {
    return DogishHelper(word.substr(1,word.length()), letter);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - determine recursively if a word is in the language dog-ish
*  - minimize time spent
*  Algorithm:
*  declare bools found_d and found_o initialized to false
*  if letter d is found in input
*    set found_d to true
*    while first letter of input isn't d
*      remove first letter of input and store as input
*  if letter o is found in input and found_d is true
*    set found_o to true
*    while first letter of input isn't o
*      remove first letter of input and store as input
*  if letter g is found in input and found_d and found_o are true
*    return true
*  else
*    return false
*  
*/

bool InDogish(string input) {

  bool found_d = false; // indicates if letter d has been found
  bool found_o = false; // indicates if letter o has been found

  if(DogishHelper(input,'d')) {
    found_d = true;
    while(input[0] != 'd') {
      input = input.substr(1,input.length());
    }
  }
  
  if((DogishHelper(input,'o')) && found_d) {
    found_o = true;
    while(input[0] != 'o') {
      input = input.substr(1,input.length());
    }
  }
  
  if((DogishHelper(input,'g')) && found_d && found_o) {
    return true;
  } else {
    return false;
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - determine recursively if a char is in a string
*  - minimize time spent
*  Algorithm:
*  if a string is empty
*    return false (no more opportunites to find the character)
*  if first character is the character being searched for
*    return true
*  else
*    return this function with the first letter removed this time
*/

bool XishHelper(string word, char letter) {
  if(word == "") {
    return false;
  }
  if(word[0] == letter) {
    return true;
  } else {
    return XishHelper(word.substr(1,word.length()), letter);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - determine recursively if a word is in the language x-ish
*  - minimize time spent
*  Algorithm:
*    declare int length_x equal to length of word XishHelper
*    declare bool letter_not_found to indicate if a letter in x isn't found
*  for the length of word x
*    if XishHelper returns true with input and current index of word x
*      while first letter of input doesn't equal current index of word x
*        input equals input with first letter removed
*    else
*      letter_not_found set to true
*  if letter_not_found is false
*    return true
*  else
*    return false
*/

bool InXish(string input, string x) {
  
  int length_x = x.length(); // length of word x
  bool letter_not_found = false; // indicates letter not found

  for(int i = 0; i < length_x; i++) {
    if(XishHelper(input, x[i])) {
      while(input[0] != x[i]) {
        input = input.substr(1,input.length());
      }
    } else {
      letter_not_found = true;
    }
  }

  if(!letter_not_found) {
    return true;
  } else {
    return false;
  }
}
