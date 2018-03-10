#include "../std_lib_facilities.h"

vector<int> getAllPrimes(int max) {
    vector<bool> isComposite (max - 1);
    int start = 2;
    vector<int> result;
    bool quit = false;
    while(!quit) {
        for (int multiplier = 2; multiplier * start <= max; ++multiplier) {
            int composite = multiplier * start;
            isComposite.at(composite - 2) = true;
        }

        quit = true;
        for (unsigned i = start + 1; i < isComposite.size(); ++i) {
            if (!isComposite.at(i - 2)) {
                start = i;
                quit = false;
                break;
            }
        }
    }

    for (unsigned i = 0; i < isComposite.size(); ++i) {
        if (!isComposite.at(i)) {
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
