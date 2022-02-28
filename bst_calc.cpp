#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

/****
* PSEUDOCODE:
*  Goals:
*  - Takes a string and inserts it into a vector
*  Algorithm:
*    Declare stringstream
*    while(stringstream reads in values)
*      Insert the value into a vector
*/

void StringToVector(std::string str, std::vector <int> &vec) {
  std::stringstream iss(str); // stringstream to traverse string
  int number; // value extracted from string (values separated by spaces)
  while(iss >> number) {
    vec.push_back(number);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - Print minimum value of a tree
*  Algorithm:
*    for each index
*      if value in index is less than current minimum
*        min equals that index's value
*    cout minimum value
*/

void PrintMin(std::vector<int> vec) {
  int size = vec.size(); // number of digits
  int min = vec[0]; // minimum value in tree initialized to first index value

  for(int i=1; i<size; i++){
    if(min > vec[i]) {
      min = vec[i];
    }
  }

  std::cout << "min = " << min;
}

/****
* PSEUDOCODE:
*  Goals:
*  - Print maximum value of a tree
*  Algorithm:
*  for each index
*      if value in index is greater than current maximum
*        max equals that index's value
*    cout maximum value
*/

void PrintMax(std::vector<int> vec) {
  int size = vec.size(); // number of digits
  int max = vec[0]; // maximum value in tree initiailzied to first index value

  for(int i=1; i<size; i++) {
    if(max < vec[i]) {
      max = vec[i];
    }
  }

  std::cout << "max = " << max; 
}

/****
* PSEUDOCODE:
*  Goals:
*  - Print average of a tree to 2 decimal places
*  Algorithm:
*    add all digits together
*    divide sum by number of digits
*    print average to decimal places
*/

void PrintAvg(std::vector<int> vec) {
  int size = vec.size(); // number of digits
  int total = 0; // total of all values initiailzied to 0
  
  int i = 0; // used to traverse digits

  while(i<size) {
    total += vec[i];
    i++;
  }

  float avg = static_cast<float>(total)/size; // average of all digits

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "avg = " << avg;
}

int main() {
  std::string numbersString; // string to hold numbers entered by std input
  std::vector<int> myNumbers; // vector of ints that holds the input

  // Get numbers from std input
  getline(std::cin,numbersString);
  StringToVector(numbersString, myNumbers);

  // Print min, max, and average
  PrintMin(myNumbers);
  std::cout << std::endl;
  PrintMax(myNumbers);
  std::cout << std::endl;
  PrintAvg(myNumbers);

  return 0;
}
