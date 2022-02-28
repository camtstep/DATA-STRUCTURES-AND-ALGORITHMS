#include "recursive.h"
#include "hw4.h"

/****
* PSEUDOCODE:
*  Goals:
*  - returns sum of each element in a list, 0 if empty
*  - use tail recursion
*  Algorithm:
*  if list is empty
*    return value of accumulator
*  else
*    add value of first element of list to accumulator
*    return sumHelper passing list with first element removed
*/

static int sumHelper(list_t list, int acc) {
  if(list_isEmpty(list)) {
    return acc;
  } else {
    acc += list_first(list);
    return(sumHelper(list_rest(list), acc));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - returns sum of each element in a list, 0 if empty
*  - use tail recursion
*  Algorithm:
*  return sumHelper function passing list and 0 as the accumulator
*/

int sum(list_t list) {
  return sumHelper(list, 0);
}

/****
* PSEUDOCODE:
*  Goals:
*  - returns product of each element in a list, 1 if empty
*  - use tail recursion
*  Algorithm:
*  if list is empty
*    return value of accumulator
*  else
*    multiply first element by accumulator
*    return productHelper passing list with first element removed
*/

static int productHelper(list_t list, int acc) {
  if(list_isEmpty(list)) {
    return acc;
  } else {
    acc *= list_first(list);
    return(productHelper(list_rest(list), acc));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - returns product of each element in a list, 1 if empty
*  - use tail recursion
*  Algorithm:
*    return productHelper function passing list and 1 as the accumulator
*/

int product(list_t list) {
  return productHelper(list, 1);
}

/****
* PSEUDOCODE:
*  Goals:
*  - return identity if list is empty
*    return fn(list_first(list), 
*    accumulate(list_rest(list),
*    fn, identity) otherwise.
*  - use tail recursion
*  Algorithm:
*  if list is empty
*    return base
*  else
*    return accumulate passing l after removing first element,
*    fn, fn passing base and first element of l
*/

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - returns reverse of a list
*  - use tail recursion
*  Algorithm:
*  if original list (list) is empty
*    return the new list (list2)
*  else
*    add the first element of original list (list) to the beginning 
*    of new list (list2)
*    remove first element from original list (list)
*    return reverseHelper function with updated original list (list) 
*    and new list (list2) 
*/

static list_t reverseHelper(list_t list, list_t list2) {
  if(list_isEmpty(list)) {
    return list2;
  } else {
    list2 = list_make(list_first(list),list2);
    list = list_rest(list);

    return(reverseHelper(list,list2));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - returns reverse of a list
*  - use tail recursion
*  Algorithm:
*    create a new list to store reversed list
*    return reverseHelper function passing orignal and new lists
*/

list_t reverse(list_t list) {
  list_t list2 = list_make(); // new list used to store reversed list
  return(reverseHelper(list,list2));
}

/****
* PSEUDOCODE:
*  Goals:
*  - append 2 lists together
*  - use tail recursion
*  Algorithm:
*  if first and seconds lists are empty
*    return appended list
*  else if second list isn't empty
*    add first element of second list to appended
*    remove first element from second list
*    return appendHelper function passing updated lists
*  else
*    add first element of first list to appended
*    remove first element from first list
*    return appendHelper function passed updated lists
*/

static list_t appendHelper(list_t first, list_t second, list_t appended) {
  if(list_isEmpty(first) && list_isEmpty(second)) {
    return appended;
  } else if(!list_isEmpty(second)) {
    appended = list_make(list_first(second),appended);
    second = list_rest(second);
    return appendHelper(first,second,appended);
  } else {
    appended = list_make(list_first(first),appended);
    first = list_rest(first);
    return appendHelper(first,second,appended);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - append 2 lists together
*  - use tail recursion
*  Algorithm:
*  create new list appended to store first and second list combined
*  reverse first and second lists so they are added together correctly
*  in appendHelper function
*  return appendHelper function passing first, second, and appended
*/

list_t append(list_t first, list_t second) {
  list_t appended = list_make(); // used to store combined lists
  first = reverse(first);
  second = reverse (second);
  return appendHelper(first,second,appended);
}

/****
* PSEUDOCODE:
*  Goals:
*  - return list with only odd values in the order they were in the list
*  - use tail recursion
*  Algorithm:
*  if list is empty
*    return odd list
*  else
*    if first element of list is odd
*      add value to odd list
*    remove first element from list
*    return filter_oddHelper function passing updated list and odd lists
*/

static list_t filter_oddHelper(list_t list, list_t odd) {
  if(list_isEmpty(list)) {
    return odd;
  } else {
    if((list_first(list)) % 2 == 1) {
      odd = list_make(list_first(list),odd);
    }
    list = list_rest(list);
    return(filter_oddHelper(list,odd));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - return list with only odd values in the order they were in the list
*  - use tail recursion
*  Algorithm:
*  create a new list to store odd values
*  reverse list so odd list will be in the correct order when created
*  return filter_oddHelper pasing list and odd lists
*/

list_t filter_odd(list_t list) {
  list_t odd = list_make(); // used to store odd list
  list = reverse(list);
  return filter_oddHelper(list,odd);
}

/****
* PSEUDOCODE:
*  Goals:
*  - return list with only even values in the order they were in the list
*  - use tail recursion
*  Algorithm:
*  if list is empty
*    return even list
*  else
*    if first element of list is even
*      add value to even list
*    remove first element from list
*    return filter_oddHelper function passing updated list and even lists
*/

static list_t filter_evenHelper(list_t list, list_t even) {
  if(list_isEmpty(list)) {
    return even;
  } else {
    if(list_first(list) % 2 == 0) {
      even = list_make(list_first(list),even);
    }
    list = list_rest(list);
    return(filter_evenHelper(list,even));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - return list with only even values in the order they were in the list
*  - use tail recursion
*  Algorithm:
*  create a new list to store even values
*  reverse list so even list will be in the correct order when created
*  return filter_evenHelper pasing list and even lists  
*/

list_t filter_even(list_t list) {
  list_t even = list_make(); // used to store even list
  list = reverse(list);
  return filter_evenHelper(list,even);
}

/****
* PSEUDOCODE:
*  Goals:
*  - return a list containing precisely the elements of list
*    for which the predicate fn() evaluates to true, in the
*    order in which  they appeared in list
*  - use tail recursion
*  Algorithm:
*  if list is empty
*    return filtered list
*  else if first element of list when passed to function is true
*    add first element of list to filtered
*  remove first element of list
*  return filterHelper function passing updated list, updated filtered, and function
*/

static list_t filterHelper(list_t list, list_t filtered, bool (*fn)(int)) {
  if(list_isEmpty(list)) {
    return filtered;
  } else if(fn(list_first(list)) == true) {
    filtered = list_make(list_first(list),filtered);
  }
  list = list_rest(list);
  return(filterHelper(list,filtered,fn));
}

/****
* PSEUDOCODE:
*  Goals:
*  - return a list containing precisely the elements of list
*    for which the predicate fn() evaluates to true, in the
*    order in which  they appeared in list
*  - use tail recursion
*  Algorithm:
*    create a new list list named filtered to hold filtered list
*    reverse list so filtered can be ordered correctly
*    return filterHelper function passing list, filtered, and function
*/

list_t filter(list_t list, bool (*fn)(int)) { 
  list_t filtered = list_make(); // stores filtered list
  list = reverse(list);
  return filterHelper(list,filtered,fn);
}

/****
* PSEUDOCODE:
*  Goals:
*  - return a list equal to the original list with the 
*    first element moved to the end of the list n times
*  - use tail recursion
*  Algorithm:
*  if n (number of times to rotate) equals 0
*    return list
*  else
*    create a list named first that hold the first element 
*    of list remove first element from list
*    create a list named rotated and store appended list
*    and first in it
*    decrement n
*    return rotate passing rotated list and updated n
*/

list_t rotate(list_t list, unsigned int n) {
  if(n == 0) {
    return list;
  } else {
    list_t first = list_make(); // list that holds first element
    first = list_make(list_first(list),first);
    list = list_rest(list);
    list_t rotated = append(list,first); // holds rotated list
    n--;
    return(rotate(rotated,n));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - return a list comprising the first n elements of
*  "first", followed by all elements of "second",
*  followed by any remaining elements of "first"
*  - use tail recursion
*  Algorithm:
*  if n (number of element from first list to insert at 
*  beginning) equals 0 or list is empty
*    reverse third list
*    set third list to appended third and second list
*    set third list to appended third and first list
*    return third list
*  else
*    add first element of first list to third list
*    remove first element from first list
*    decrement n
*    return insert_listHelper function passing updated
*    first, second, updated third, and n
*/

static list_t insert_listHelper(list_t first, list_t second, list_t third, unsigned int n) {
  if(n == 0 || list_isEmpty(first)) {
    third = reverse(third);
    third = append(third,second);
    third = append(third,first);
    return third;
  } else {
    third = list_make(list_first(first),third);
    first = list_rest(first);
    n--;
    return(insert_listHelper(first,second,third,n));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - return a list comprising the first n elements of
*  "first", followed by all elements of "second",
*  followed by any remaining elements of "first"
*  - use tail recursion
*  Algorithm:
*  create third list to store new list that's created
*  return insert_listHelper passing first, second, third, and n
*/

list_t insert_list(list_t first, list_t second, unsigned int n) {
  list_t third = list_make(); // stores new list created
  return(insert_listHelper(first,second,third,n));
}

/****
* PSEUDOCODE:
*  Goals:
*  - return the list equal to l without its last n elements
*  - use tail recursion
*  Algorithm:
*  if n (number of element to remove from end) equals 0 or
*  list is empty
*    return reverse of l
*  else
*    remove first element from l
*    decrement n
*    return chopHelper function passing updated l and n
*/

static list_t chopHelper(list_t l, unsigned int n) {
  if(n == 0 || list_isEmpty(l)) {
    return reverse(l);
  } else {
    l = list_rest(l);
    n--;
    return(chopHelper(l,n));
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - return the list equal to l without its last n elements
*  - use tail recursion
*  Algorithm:
*  reverse l
*  return chopHelper function passing l and n
*/

list_t chop(list_t l, unsigned int n) {
  l = reverse(l);
  return(chopHelper(l,n));
}

/****
* PSEUDOCODE:
*  Goals:
*  - computer the Nth Fibonacci number
*  - don't use tail recursion
*  Algorithm:
*  if n (Nth Fibonacci number) equals 0
*    return 0
*  else if n equals 1
*    return 1
*  else
*    return fib(n-1) + fib(n-2)
*/

int fib(int n) {
  if(n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - computer the Nth Fibonacci number
*  - use tail recursion
*  Algorithm:
*  if n (Nth Fibonacci number) equals 0
*    return a (set to 0)
*  else if n equals 1
*    return (set to 1)
*  else
*    return fib_tailHelper passing a decremented n,
*    b (updating a), and a+b (updating b)
*/

static int fib_tailHelper(int n, int a, int b) {
  if(n == 0) {
    return a;
  } else if(n == 1) {
    return b;
  } else {
    return fib_tailHelper(n-1, b, a+b);
  }
}

/****
* PSEUDOCODE:
*  Goals:
*  - computer the Nth Fibonacci number
*  - use tail recursion
*  Algorithm:
*    return fib_tailHelper function passing n, 0, and 1
*/

int fib_tail(int n) {
  return(fib_tailHelper(n, 0, 1));
}
