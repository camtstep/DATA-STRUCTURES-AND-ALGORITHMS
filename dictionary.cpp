
#include <string>
using namespace std;

/****
* PSEUDOCODE:
* Goals:
* - return length of word with the minimum length
* - minimize time spent
* Algorithm:
* - sequentially step through array of words of known length and 
*   compare to current min_length (initilized to 100 since there is *   no word of this length)
* - if the word is shorter, store its lenghth in min_length
* - return min_length after stepping through the entire array
*/

int MinWordLength(string words[], int length) {
  
  int min_length = 100; // minimun word length

  for(int i=0; i<length; i++) {
    int count = words[i].length();
    if(count < min_length)
      min_length = count;
  }
  return min_length;

  throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* Goals:
* - return length of word with the maximum length
* - mimimize time spent
* Algorithm:
* - sequentially step through array of words of known length and 
*   compare to current max_length (initilized to 0)
* - if the word is longer, store its lenghth in max_length
* - return max_length after stepping through the entire array 
*/

int MaxWordLength(string words[], int length) {
    
  int max_length = 0; // maximum word length

  for(int i=0; i<length; i++) {
    int count = words[i].length();
    if(count > max_length)
      max_length = count;
  }
  return max_length;

  throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* Goals:
* - return range of word lengths
* - minimize time spent
* Algorithm:
* -  return MaxWordLength return minus the MinWordLength return
*/

int WordLengthRange(string words[], int length) {
    return MaxWordLength(words, length) - MinWordLength(words, length);

  throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* Goals:
* - return average word length
* - minimize time spent
* Algorithm:
* - add all word lengths together
* - return total_characters divided by length of array
*/

int AverageWordLength(string words[], int length) {
    
  int total_characters = 0; // accumulates length of all words

  for(int i=0; i<length; i++) {
    total_characters += words[i].length();
  }

  return total_characters / length;

  throw "Unsupported Operation";
}

/****
* PSEUDOCODE:
* Goals:
* - return most common word length
* - minimize time spent
* Algorithm:
* - for each word in the array, find the number of words in the 
*   array with the same number of characters by going through the 
*   entire array (subtract 1 from count since the word being
*   compared against will be compared against itself)
* - if the count is greater than most_common_count, set 
*   most_common_count to count minus 1 and most_common_length to the
*   length of the current word
* - return most_common_length after going through the entire array
*/

int MostCommonWordLength(string words[], int length) {

  int most_common_count = 0; // most common word length count
  int most_common_length = -1; // length of most common word length

  for(int i=0; i<length; i++) {
    int count = 0; // count of current word length in array
    for(int j=0; j<length; j++) {
      if(words[i].length() == words[j].length())
        count++;
    }
    if(count - 1 > most_common_count) {
      most_common_count = count - 1;
      most_common_length = words[i].length();
    }
  }

  return most_common_length;

  throw "Unsupported Operation";
}
