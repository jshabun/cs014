// Assignment 2, exercise 2

#include <cstdio>
#include <stdexcept>

template <class T>
class TwoStacks {
 public:
  // Constructor, initialize the array to size_hint
  TwoStacks(size_t size_hint = 16) : size_(size_hint), array_(new T(size_hint)) {}
  // Destructor
  ~TwoStacks() { delete array_; }

  // Push a value to the first stack
  void push_first(const T& val) {
    // Implement here
    for (int i = val.size(); i < )
  }

  // Push a value to the second stack
  void push_second(const T& val) {
    // Implement here
  }

  // Pop from the first stack and return the value
  T pop_first() {
    // Implement here, throw std::out_of_range if necessary
    if (empty_first() == true) {
      throw std::out_of_range ("Out of Range: Stack Empty");
    } else {

    }
  }

  // Pop from the second stack and return the value
  T pop_second() {
    // Implement here, throw std::out_of_range if necessary
    if (empty_second() == true) {
      throw std::out_of_range ("Out of Range: Stack Empty");
    } else {

    }
  }

  // Return the size of the first stack
  size_t size_first() const {
    // Implement here
  }

  // Return the size of the second stack
  size_t size_second() const {
    // Implement here
  }

  // Return true if the first stack is empty
  bool empty_first() const { return size_first() == 0; }

  // Return true if the second stack is empty
  bool empty_second() const { return size_second() == 0; }

 private:
  size_t size_;
  T *array_;
};
