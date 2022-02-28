#include <iostream>
#include <vector>
#include <sstream>
#include "recursive.h"
#include "hw4.h"

/****
* PSEUDOCODE:
*  Goals:
*  - calculate and print difference of 2 lists
*  Algorithm:
*    create diff list to hold differences
*    declare 2 variables to hold values from lists to calculate differences
*    while the lists aren't empty
*      store first value in first list and remove the index from
*      the first list
*      store first value in second list and remove the index from
*      the second list
*      calculate and store difference of the 2 values in diff list
*    reverse diff list to maintain correct order
*    print diff list
*/

void Difference(list_t list1, list_t list2) {
  list_t diff = list_make(); // list to hold differences
  int number_1; // number of first list
  int number_2; // number of second list
  int difference; // difference of 2 numbers

  while(!list_isEmpty(list1) && !list_isEmpty(list2)) {
    // Store number of first lists
    number_1 = list_first(list1);
    list1 = list_rest(list1);

    // Store number of second list
    number_2 = list_first(list2);
    list2 = list_rest(list2);

    difference = number_1 - number_2;

    // If difference is negative make it positive
    if(difference<0) {
      difference *= -1;
    }

    diff = list_make(difference,diff); // difference of 2 values
  }

  diff = reverse(diff);

  //  Print difference of 2 lists
  std::cout << "final_diff_output: ";
  list_print(diff);
}

/****
* PSEUDOCODE:
*  Goals:
*  - calculate and return hash values of list of keys
*  - hash value is the Fibonacci number of the key + the sum of
*    all the items in the list
*  Algorithm:
*    create new_hash_output list to hold hash values
*    while keys list is not empty
*      take the first value of keys lists and find its hash value and store
*      in new_hash_output list
*      remove first element of keys list
*    reverse new_hash_output to maintain correct order
*    return new_hash_output
*/

list_t HashTest1(list_t keys) {

  list_t new_hash_output = list_make();  // list to store new hash output
  int sum_of_keys = sum(keys); // sum of all keys
  int number;  // stores the value of each index in list

  while(!list_isEmpty(keys)) {
    number = list_first(keys);
    new_hash_output = list_make((sum_of_keys + fib(number)),new_hash_output);
    keys = list_rest(keys);
  }

  new_hash_output = reverse(new_hash_output);

  return new_hash_output;
}

/****
* PSEUDOCODE:
*  Goals:
*  - determine if a number is prime
*  Algorithm:
*    if number is less than or equal to 1
*      return false
*    for int i from 2 to number-1
*      if number mod i equals 0
*        return false
*    return true
*/

bool IsPrime(int n)
{
  if (n <= 1) {
    return false;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

/****
* PSEUDOCODE:
*  Goals:
*  - calculate and return hash value for odd keys
*  Algorithm:
*    return value + product of odds
*/

int OddFn(int value, int product_of_odds) {
  return value + product_of_odds;
}

/****
* PSEUDOCODE:
*  Goals:
*  - calculate and return hash value for even keys
*  Algorithm:
*    return value + sum of odds with the prime numbers removed
*/

int EvenFn(int value, int sum_of_odds_primes_removed) {
  return value + sum_of_odds_primes_removed;
}

/****
* PSEUDOCODE:
*  Goals:
*  - calculate and return hash values of list of keys
*  - hash value of odds is product of odds plus key
*  - hash value of evens is sum of odds w/o primes plus key
*  Algorithm:
*    create list of only odds and find product of odds (used to find
*    odd hash values)
*    create list of odds w/o primes and sum them (used to find even
*    hash values)
*    create new_hash_output to store new hash values
*    while keys list is not empty
*      get first value and remove it from keys list
*      if value is odd
*        call odd_fn and store returned int
*      else
*        call even_fn and store return int
*    reverse new_hash_output to maintain correct order
*    return new_hash_output
*/

list_t HashTest2(list_t keys) {

  list_t odd_list = filter_odd(keys); // list with only odds
  int product_of_odds = product(odd_list); // product of odd numbers
  list_t odd_list_hashed_no_primes = list_make(); // odd list hashed

  int value_1; // used to build odd hashed list w/o primes

  while(!list_isEmpty(odd_list)) {
    value_1 = list_first(odd_list);
    odd_list = list_rest(odd_list);

    if(!IsPrime(OddFn(value_1,product_of_odds))) {
      odd_list_hashed_no_primes = list_make(OddFn(value_1,product_of_odds),
      odd_list_hashed_no_primes);
    }
  }

  int sum_of_odd_no_primes = sum(odd_list_hashed_no_primes); // sum of odds w/o primes
                                                             
  // Hash keys
  list_t new_hash_output = list_make(); // new list of hashed values

  int value_2; // used to build new hash list

  while(!list_isEmpty(keys)) {
    value_2 = list_first(keys);
    keys = list_rest(keys);

    if(value_2 % 2 == 1) {
      new_hash_output = list_make(OddFn(value_2,product_of_odds),
      new_hash_output);
    } else {
      new_hash_output = list_make(EvenFn(value_2,sum_of_odd_no_primes),
      new_hash_output);
    }
  }

  new_hash_output = reverse(new_hash_output);

  return new_hash_output;

}

/****
* PSEUDOCODE:
*  Goals:
*  - return number of collisions when hash values are put into a hash table
*  Algorithm:
*    declare int collisions to store number of collisions
*    create an array of 16 lists
*    while hash_values list is not empty
*      store first index in value and remove from hash_values list
*      if array index [hash value % 16] is not empty
*        increment collisions
*      add hash value to the list at that index
*    return collisions
*/

int CollisionCount(list_t hash_values,int number_of_buckets) {
  int collisions = 0; // number of collisions

  list_t buckets[number_of_buckets]; // array of lists to store hash values

  for(int i=0; i<number_of_buckets; i++) {
    buckets[i] = list_make();
  }

  int value; // used to store value into array of lists

  while(!list_isEmpty(hash_values)) {
    value = list_first(hash_values);
    hash_values = list_rest(hash_values);

    if(!list_isEmpty(buckets[value % number_of_buckets])) {
      ++collisions;
    }

    buckets[value % number_of_buckets] = list_make(value,buckets
    [value % number_of_buckets]);
  }

  return collisions;
}

/****
* PSEUDOCODE:
*  Goals:
*  - convert a string of ints into a list
*  Algorithm:
*    declare stringstream
*    while a number is read it
*      add number to the list
*    reverse the list to maintain correct order
*    return list
*/

list_t StringToList(std::string str, list_t list) {
  std::stringstream iss(str); // stringstream to traverse string
  int number; // value extracted from string (values separated by spaces)
  while(iss >> number) {
    list = list_make(number,list);
  }

  list = reverse(list);

  return list;
}

int main() {

  const int kBuckets = 16; // number of buckets to calculate collisions

  // Test HashTest1
  std::cout << "hash_test1" << std::endl;

  std::string list_1; // list of ints to be hashed as a string

  std::cout << "input (separated by spaces): ";
  getline(std::cin,list_1);

  list_t original_1 = list_make(); // list of ints to be hashed
  original_1 = StringToList(list_1,original_1);

  list_t hash_test_1 = list_make(); // list of hashed values
  hash_test_1 = HashTest1(original_1);

  std::cout << "hash_output: ";
  list_print(hash_test_1);
  std::cout << std::endl;

  std::string old_hash_1; // list of old hash values held in a string

  std::cout << "old_hash_output (separated by spaces): ";
  getline(std::cin,old_hash_1);

  list_t output_from_old_code1 = list_make(); // list of old hash values
  output_from_old_code1 = StringToList(old_hash_1,output_from_old_code1);

  Difference(hash_test_1,output_from_old_code1);
  std::cout << std::endl;

  std::cout << std::endl << "collision cnt" << std::endl;
  std::cout << "{hash_test1}" << std::endl;
  std::cout << "new_code : " << CollisionCount(hash_test_1,kBuckets);
  std::cout << std::endl;
  std::cout << "old_code : " << CollisionCount(output_from_old_code1,kBuckets);
  std::cout << std::endl << std::endl;

  // Test HashTest2
  std::cout << "hash_test2" << std::endl;

  std::string list_2; // list of ints to be hashed as a string

  std::cout << "input (separated by spaces): ";
  getline(std::cin,list_2);

  list_t original_2 = list_make(); // list of ints to be hashed
  original_2 = StringToList(list_2,original_2);

  list_t hash_test_2 = list_make(); // list of hashed values
  hash_test_2 = HashTest2(original_2);

  std::cout << "hash_output: ";
  list_print(hash_test_2);
  std::cout << std::endl;

  std::string old_hash_2; // list of old hash values held in a string

  std::cout << "old_hash_output (separated by spaces): ";
  getline(std::cin,old_hash_2);

  list_t output_from_old_code2 = list_make(); // list of old hash values
  output_from_old_code2 = StringToList(old_hash_2,output_from_old_code2);

  Difference(hash_test_2,output_from_old_code2);
  std::cout << std::endl;

  std::cout << std::endl << "collision cnt" << std::endl;
  std::cout << "{hash_test2}" << std::endl;
  std::cout << "new_code : " << CollisionCount(hash_test_2,kBuckets);
  std::cout << std::endl;
  std::cout << "old_code : " << CollisionCount(output_from_old_code2,kBuckets);
  std::cout << std::endl;

  return 0;
}
