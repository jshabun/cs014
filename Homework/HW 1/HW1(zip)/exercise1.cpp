#include <iostream>
#include <vector>
#include <string>

using namespace std;

void count (string in) {

}

int main() {
    // string temp = "";
    string polyIn = "";
    bool polynomial = false;
    string bigO = "";

    cout << "Input a polynomial:" <<  endl;
    getline(cin, polyIn);

    for (int i = 0; i < polyIn.size(); i++) {
        if (polyIn[i] == '(') {
            cout << "The polynomial is invalid." << endl;
            polynomial = false;
        } else if (polyIn[i] == ')') {
            cout << "The polynomial is invalid." << endl;
            polynomial = false;
        }

        if (polyIn[i] == ' ') {
            polyIn.erase(remove(polyIn.begin(), polyIn.end(), ' '), polyIn.end());
            // temp = polyIn;
            // cout << polyIn << endl; // debug for remove spaces. 
            polynomial = true;
        }

        if (polyIn[i] == 'n') {
            if (polyIn[i+1] == '^') {
                bigO = polyIn[i] + polyIn[i+1] + polyIn [i+2];
            } else {
                bigO = polyIn[i];
            }
        }

    }

    if (polynomial == true) {
            cout << "O(" << bigO << ")" << endl;
        }

}