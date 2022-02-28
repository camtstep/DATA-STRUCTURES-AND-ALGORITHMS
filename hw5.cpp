#include <iostream>
#include <vector>
#include "hw5.h"

/****
* PSEUDOCODE:
*  Goals:
*  - implement bubble sort
*  - best case is O(n) iteratively
*  Algorithm:
*  for every element in a vector starting at maxElement until 0
*    for each index until maxElement
*      if 2 consecutive indices are alphabetically out of order
*        swap the contents of the indices
*/

void BubbleSort(std::vector<std::string> &vec) {
  for(int maxElement = vec.size()-1; maxElement > 0; maxElement--){
    for(int index = 0; index < maxElement; index++) {
      if(vec[index].compare(vec[index+1]) > 0) {
        std::string temp = vec[index];  // temporarily holds element of index
        vec[index] = vec[index+1];
        vec[index+1] = temp;
      }
    }
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  -implement insertion sort recursively
*  Algorithm:
*  if size is less than or equal to 1 return - vector is sorted
*  call InsertionSortHelper passing v vector and size-1
*  last is element of v vector
*  j is second to last element of v vector
*  while j is greater than or equal to 0 and element at j index is greater
*  than last
*    element at j+1 index is set to element at element at j index
*    decrement j
*  element at j+1 index is set to last
*/

static void InsertionSortHelper(std::vector<int>& v, int n) {
  if(n <= 1) {
    return;
  }

  InsertionSortHelper(v, n-1);

  int last = v[n-1]; // element of last index
  int j = n-2; // index second to last
  
  while(j >= 0 && v[j] > last) {
    v[j+1] = v[j];
    j--;
  }
  v[j+1] = last;
}

/****
* PSEUDOCODE:
*  Goals:
*  -inplement insertion sort recursively
*  Algorithm:
*  call InsertionSortHelper passing v vector and its size
*/

void InsertionSort(std::vector<int>& v) {
  InsertionSortHelper(v,v.size());
}

/****
* PSEUDOCODE:
*  Goals:
*  -implement merge sort to alphabetize a sting vector
*  Algorithm:
*  create a vector holding the left side of vec
*  create a vector holding the right side of vec
*  create counters to track position of left vector, right vector, 
*  and vec
*  while position in left vector is less than left vector size and 
*  position of right index is less than right vector size
*    if left index comes before right index alphabetically
*      copy contents of left index into vec
*      increment left index counter and vec counter
*    else
*      copy contents of right index into vec
*      increment right index counter and vec counter
*    any remaining elements in either vector(left or right) are copied 
*    into the end of vec once the other vector(right or left) has been 
*    fully navigated
*/

static void Merge(std::vector<std::string> &vec, int l, int m, int r) {
  int lsize = m-l+1; // size of left side
  int rsize = r-m; // size of right side

  std::vector<std::string> left_vec(lsize);
  for(int p =0 ; p<lsize; p++) {
    left_vec[p]=vec[l+p];
  }

  std::vector<std::string> right_vec(rsize);
  for(int r =0 ; r<rsize; r++) {
    right_vec[r]=vec[m+1+r];
  }

  int li =0; // counter to track index of left side
  int ri =0; // counter to track index of right side
  int k = l; //  counter to track index of original vector
  while( li < lsize && ri < rsize) {
    if( left_vec[li].compare(right_vec[ri]) <= 0) {
      vec[k] =left_vec[li] ;
      li++;
      k++;
    } else {
      vec[k] =right_vec[ri] ;
      ri++;
      k++;
    }
  }
  while(li < lsize) {
    vec[k] = left_vec[li];
    li++;
    k++;
  }
  while(ri < rsize) {
    vec[k] =right_vec[ri] ;
    ri++;
    k++;
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  -implement merge sort to alphabetize a sting vector
*  Algorithm:
*  determine the middle index of the vector
*  call MergeSortHelper for left half of vector
*  call MergeSortHelper for right half of vector
*  merge the two sorted halves
*/

static void MergeSortHelper(std::vector<std::string> &vec, int l, int r) {
  if(l<r) {
    int mid = l +(r-l)/2; // middle index
    MergeSortHelper(vec,l,mid);
    MergeSortHelper(vec,mid+1,r);
    Merge(vec,l,mid,r);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  -implement merge sort to alphabetize a sting vector
*  Algorithm:
*    call MergeSortHelper passing the vector, 0 for left index, and vector
*    size - 1 for right index
*/

void MergeSort(std::vector<std::string> &vec) {
  MergeSortHelper(vec,0,vec.size()-1);
}
