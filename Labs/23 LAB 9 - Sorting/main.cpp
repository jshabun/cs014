#include <cassert>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;

const size_t NUMBERS_SIZE = 50000;

void Quicksort_midpoint(int numbers[], size_t i, size_t k);
void Quicksort_medianOfThree(int numbers[], size_t i, size_t k);
void InsertionSort(int numbers[], size_t numbersSize);

void fillArrays(int[], int[], int[]);
bool isArraySorted(int[], size_t);

int partition(int numbers[], size_t i, size_t k);
int medianPartition(int numbers[], size_t i, size_t);

int main() {
  // Test sorting empty array
  int *nullArray = nullptr;
  Quicksort_midpoint(nullArray, 0, 0);
  Quicksort_medianOfThree(nullArray, 0, 0);
  InsertionSort(nullArray, 0);

  // Test sorting array of single element
  int singleArray[1];
  Quicksort_midpoint(singleArray, 0, 0);
  Quicksort_medianOfThree(singleArray, 0, 0);
  InsertionSort(singleArray, 1);

  int arr1[NUMBERS_SIZE];
  int arr2[NUMBERS_SIZE];
  int arr3[NUMBERS_SIZE];
  fillArrays(arr1, arr2, arr3);

  auto start_time = high_resolution_clock::now();
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
  auto end_time = high_resolution_clock::now();
  unsigned long elapsed =
      duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 1: " << elapsed << " us" << endl;
  assert(isArraySorted(arr1, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 2: " << elapsed << " us" << endl;
  assert(isArraySorted(arr2, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  InsertionSort(arr3, NUMBERS_SIZE);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 3: " << elapsed << " us" << endl;
  assert(isArraySorted(arr3, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 1: " << elapsed << " us" << endl;
  assert(isArraySorted(arr1, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 2: " << elapsed << " us" << endl;
  assert(isArraySorted(arr2, NUMBERS_SIZE));

  start_time = high_resolution_clock::now();
  InsertionSort(arr3, NUMBERS_SIZE);
  end_time = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(end_time - start_time).count();
  cout << "Time elapsed 3: " << elapsed << " us" << endl;
  assert(isArraySorted(arr3, NUMBERS_SIZE));

  return 0;
}

void fillArrays(int arr1[], int arr2[], int arr3[]) {
  // Generate random integers using uniform distribution
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist;
  for (size_t i = 0; i < NUMBERS_SIZE; i++) arr1[i] = dist(gen);
  // Array copy (memcpy) is generally faster
  memcpy(arr2, arr1, sizeof(int) * NUMBERS_SIZE);
  memcpy(arr3, arr1, sizeof(int) * NUMBERS_SIZE);
}

bool isArraySorted(int arr[], size_t len) {
  if (arr == nullptr || len < 2) return true;
  for (size_t i = 0; i < len - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }
  return true;
}

// this function sorts the given array in the range from i to k using quicksort method. 
// In this function, pivot is the midpoint element (numbers[(i+k)/2]). (implementation 
// of this function is given in section 21.5)
void Quicksort_midpoint(int numbers[], size_t i, size_t k) {
  int temp = 0;

  // added if checks for empty or single element arrays  
  if (i == k) {
    return;
  }

  if (k == (size_t) - 1) {
    return;
  }
  
  if( i >= k ) {
    return;
  }

  temp = partition(numbers, i , k );
  Quicksort_midpoint(numbers, i, temp );
  Quicksort_midpoint(numbers, temp+1, k );
}

// this function utilizes different pivot selection technique in quicksort algorithm. 
// The pivot is the median of the following three values: leftmost (numbers[i]), midpoint 
// (numbers[(i+k)/2]) and rightmost (numbers[k]). You should modify the partition function 
// given in section 21.5 to select the pivot using median-of-three technique.
void Quicksort_medianOfThree(int numbers[], size_t i, size_t k) {
  int temp = 0;

  // added if checks for empty or single element arrays  
  if (i == k) {
    return;
  }

  if (k == (size_t) - 1) {
    return;
  }

  if( i >= k ) {
        return;
  }
  
  temp = medianPartition(numbers, i , k );
  Quicksort_medianOfThree(numbers, i, temp );
  Quicksort_medianOfThree(numbers, temp+1, k );
}

// this function sorts the given array using InsertionSort method. (implementation of this 
// method is provided in section 21.3).
void InsertionSort(int numbers[], size_t numbersSize) {
  int numSize = numbersSize;
  for (int i = 1; i < numSize; i++) {
	  int j = i;
		while (j > 0 && numbers[j - 1] > numbers[j]) {
			int temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			j = j - 1;
		}
	}
}


int partition (int numbers[], size_t i, size_t k) {
  int midpoint = i+(k-i)/2;
  int val = numbers[midpoint];
  bool done = false;
  
  while(!done){
    while(numbers[i] < val){
      i++;
    }
    
    while(numbers[k] > val){
      k--;
    }

    if(i >= k){
      done = true;
    } else{
      int temp = numbers[i];
      numbers[i] = numbers[k];
      numbers[k] = temp;
      
      i++;
      k--;
    }
  }

  return k;
}

int medianPartition(int numbers[], size_t i, size_t k) {
  int l = 0;
  int r = 0;
  int midpoint = i + (k - i) / 2;
  int pivot = numbers[midpoint];
  
  l = i;
  r = k;
  
  bool done = false;

  while (!done) {
      while (numbers[l] < pivot) {
          l++;
      }

      while (pivot < numbers[r]) {
        r--;
      }

      if(l >= r) {
          done = true;
      } else {
        int temp = numbers[l];
        numbers[l] = numbers[r];
        numbers[r] = temp;
        
        l++;
        r--;
      }
  }

  return r;
}