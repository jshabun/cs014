#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

template<typename T>
void selection_sort(vector<T> &vals);

template<typename T> 
T getElement(vector<T> vals, int index);

vector<char> createVector();

int main () {
    
    // Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while (--numOfRuns >= 0) {
        cout << "Enter a number: " << endl;
        cin >> index;

        // try-catch block to try calling getElement function and if 
        // out-of-range, then display a message
        try {
            curChar = getElement(vals, index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        } 
        
        catch (const std::out_of_range& excpt) {
            cout << "out of range exception occured" << endl;
        }
        
    }

    return 0;
}

// FUNCTIONS
// min_index function
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned min = index;

    for (unsigned i = index; i < vals.size(); i++) {
        if (vals.at(min) > vals.at(i)) {
            min = i;
        }
    }

    return min;
}

// selection_sort function
template<typename T>
void selection_sort(vector<T> &vals) {
    // implements selection sort method to move min values to front of list
    for (unsigned i = 0; i < vals.size(); i++) {
        T tmp;
        unsigned min; 
        
        min = min_index(vals, i);
        tmp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = tmp;
    }
}

// getElement function
template<typename T> 
T getElement(vector<T> vals, int index) {
    return vals.at(index);
}

// createVector function
vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    
    for (int i = 0; i < vecSize; i++) {
        vals.push_back(c);
        c++;
    }

    return vals;
}