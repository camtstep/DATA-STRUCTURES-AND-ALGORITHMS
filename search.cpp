/****
* PSEUDOCODE:
* Goal:
* - use linear search to find index of a specified number and 
*   return -1 if number not found 
* - minimize time spent
* 
* Algorithm:
* - navigate numbers array consecutively until specifed number is
*   found
* - if number is found set found to true so while loop stops and
*   return index poisition
* - if not found add 1 to index and do while loop again
* - if not found after navigating entire array return -1 
*/
int LinearSearch(int numbers[], int length, int n) {
  int index = 0; // index position
  int position = -1; // index of found number, -1 if not found
  bool found = false; // indicates if number has been found

  while(index < length && !found) {
    if(numbers[index] == n) {
      found = true;
      position = index;
    }
  index++;
  }
   return position;
}

/***
* PSEUDOCODE:
* Goal:
* - use binary search to find index of a specified number in a 
*   sorted array and return -1 if number not found
* - minimize time spent
*
* Algorithm:
* - find middle index and test to see if it matches specified number
* - if it doesn't match, determine if specifed number is lower or
*   higher than the middle index
* - if lower, set last index to middle - 1
* - if higher, set first index to middle + 1
* - repeat until specified number is found, -1 if not found
*/

int BinarySearch(int numbers[], int length, int n) {
  int first = 0; // fist index in a search
  int last = length - 1; // last index in a search
  int middle; // middle index in a search
  int position = -1; // index of found number, -1 if not found
  bool found = false; // indicates if number has been found

  while(!found && first <= last) {
    middle = (first + last) / 2;
    if(numbers[middle] == n) {
      found = true;
      position = middle;
    }
    else if (numbers[middle] > n)
      last = middle - 1;
    else
      first = middle + 1;
  }
     return position;
}
