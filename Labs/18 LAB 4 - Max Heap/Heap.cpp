#include "Heap.h"

 /* Initializes an empty heap. */
  Heap::Heap() {
      numItems_ = 0;
  }

  /* Inserts a PrintJob to the heap without violating max-heap properties. */
  void Heap::enqueue(PrintJob* job) {
      // check for max heap size to run
      if (numItems_ == 0) {
          arr_[0] = job;
          ++numItems_;
          return;
      } else {
          /* for (int i = 0; i < MAX_HEAP_SIZE; ++i) {
              if (arr_[i] == nullptr) {
                  arr_[i] = job;

              }
          } */
          arr_[numItems_] = job;
          percolateUp(numItems_);
          ++numItems_;
      }
  }

  /* Removes the node with highest priority from the heap. Follow the algorithm
   * on priority-queue slides. */
  void Heap::dequeue() {
      if (numItems_ == 0) {
          return;
      }
      
      if (numItems_ == 1) {
          delete arr_[0];
          --numItems_;
          return;
      } else {
          arr_[0] = arr_[numItems_ - 1];
          --numItems_;
          trickleDown(0);
      }
  }

  /* Returns the node with highest priority. */
  PrintJob* Heap::highest() const {
      /* if (numItems_ == 0) {
          return 0;
      } */

      return arr_[0];
  }

  /* Prints the PrintJob with highest priority in the following format:
   * Priority: priority, Job Number: jobNum, Number of Pages: numPages (Add a
   * new line at the end.) */
  void Heap::print() {
      // for (int i = 0; i < numItems_; ++i) {
        if (numItems_ > 0) {
          cout << "Priority: " << arr_[0]->getPriority() << ", Job Number: " << arr_[0]->getJobNumber() 
               << ", Number of Pages: " << arr_[0]->getPages() << endl;
      }
  }

  void Heap::trickleDown (int x) {
      // similar to percolateDown
      for (int i = 0; i < numItems_; ++i) {
          if (arr_[x]->getPriority() < arr_[i]->getPriority()) {
              // swap
              PrintJob* tmp = arr_[x];
              arr_[x] = arr_[i];
              arr_[i] = tmp;
          }
      }
  }

// percolate up from zybooks
void Heap::percolateUp(int nodeIndex) {
   while (nodeIndex > 0) {
        int parentIndex =  (nodeIndex - 1) / 2;
        
        if (arr_[nodeIndex]->getPriority() <= arr_[parentIndex]->getPriority()) {
            return;
        } else {
            // swap function
            PrintJob* tmp = arr_[nodeIndex];
            arr_[nodeIndex] = arr_[parentIndex];
            arr_[parentIndex] = tmp;
            nodeIndex = parentIndex;
        }
    }
}