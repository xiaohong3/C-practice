#include "../std_lib_facilities.h"

vector<int> getAllPrimes(int max) {
    vector<bool> sequence (max - 1);
    int start = 2;
    bool stop = false;
    vector<int> result;
    while(!stop) {
        for (int i = 2; i * start <= max; ++i) {
            int composite = i * start;
            sequence.at(composite - 2) = true;
        }

        for (unsigned i = (start - 1); i < sequence.size(); ++i) {
            if (!sequence.at(i)) {
                start = i + 2;
                break;
            }
            stop = true;
        }
    }

    for (unsigned i = 0; i < sequence.size(); ++i) {
        if (!sequence.at(i)) {
            result.push_back(i + 2);
        }
    }

    return result;
}

int main() {
    cout << "This program will find all primes between 1 - MAX";
    cout << "\n";
    cout << "Input a number for the MAX: ";
    cout << "\n";

    int max;
    cin >> max;

    vector<int> primesFound = getAllPrimes(max);

    for (int prime : primesFound) {
        cout << prime;
        cout << "\n";
    }
}