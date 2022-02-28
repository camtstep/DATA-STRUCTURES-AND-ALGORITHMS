#include <iostream>
#include <vector>
#include "hw5.h"

void printString(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void printInt(std::vector<int> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  // Bubble Sort Tests

  std::vector<std::string> v;
  std::vector<std::string> w;
  std::vector<std::string> x;

  v = {"emma", "ruth", "ziegellabu", "eichler", "dora"};
  w = {"stepanski", "taylor", "cameron"};
  x = {"zoo", "zebra", "zipper", "zed"};

  BubbleSort(v);
  BubbleSort(w);
  BubbleSort(x);

  std::cout << "Case 1: ";
  printString(v);
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
  std::cout << "Case 2: ";
  printString(w);
  std::cout<< "Expected: [cameron, stepanski, taylor]" << std::endl;
  std::cout << "Case 3: ";
  printString(x);
  std::cout << "Expected: [zebra, zed, zipper, zoo]" << std::endl;

  // Insertion Sort Tests

  std::vector<int> a;
  std::vector<int> b;
  std::vector<int> c;

  a = {1,19,4,2,6};
  b = {};
  c = {1,1,5,3,54,32,8};

  InsertionSort(a);
  InsertionSort(b);
  InsertionSort(c);

  std::cout << std::endl;
  std::cout << "Case 1: ";
  printInt(a);
  std::cout << "Expected: [1, 2, 4, 6, 19]" << std::endl;

  std::cout << "Case 2: ";
  printInt(b);
  std::cout << "Expected: []" << std::endl;

  std::cout << "Case 3: ";
  printInt(c);
  std::cout << "Expected: [1, 1, 3, 5, 8, 32, 54]" << std::endl;
  std::cout << std::endl;

  // Merge Sort Tests
  std::vector<std::string> d;
  std::vector<std::string> e;
  std::vector<std::string> f;

  d = {"emma", "ruth", "ziegellabu", "eichler", "dora"};
  e = {"stepanski", "taylor", "cameron"};
  f = {"zoo", "zebra", "zipper", "zed"};

  MergeSort(d);
  MergeSort(e);
  MergeSort(f);

  std::cout << "Case 1: ";
  printString(d);
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
  std::cout << "Case 2: ";
  printString(e);
  std::cout<< "Expected: [cameron, stepanski, taylor]" << std::endl;
  std::cout << "Case 3: ";
  printString(f);
  std::cout << "Expected: [zebra, zed, zipper, zoo]" << std::endl;
}
