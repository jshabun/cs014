// Assignment 2, exercise 3
// To compile, run:
//    g++ -std=c++11 exercise_3.cpp

#include <chrono>
#include <cstdio>

/*
 * Implement the 4 in-place sort functions for exercise 3.a.
 */

void insertion_sort(int array[], size_t size) {
  // Implement here
  int i = 0;
  int j = 0;
  int temp = 0;  

  for (i = 1; i < size; ++i) {
    j = i;
    
    while (j > 0 && array[j] < array[j - 1]) {
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
        --j;
    }
  }
}

void quick_sort(int array[], size_t size) {
  // Implement here
}

void heap_sort(int array[], size_t size) {
  // Implement here
}

void merge_sort(int array[], size_t size) {
  // Implement here
}


/*
 * Generate random integers for exercise 3.b
 */
int *random_ints(size_t size) {
  int *numbers = new int[size];
  // Generate random numbers here
  return numbers;
}

/* Here is an example to measure a function's running time in nanoseconds
long long time_example() {
  auto start_time = std::chrono::high_resolution_clock::now();

  // Run function to measure the time in nanoseconds

  auto end_time = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
      end_time - start_time);
  return elapsed.count();
}
*/