#include "../std_lib_facilities.h"

vector<int> primes;

bool isPrime(int number) {
    if (number == 2) {
        primes.push_back(number);
        return true;
    } else if (number > 2) {
        bool isPrime = true;
        for (int prime : primes) {
            if (number % prime == 0) {
                isPrime = false;
            }
        }

        if (isPrime) {
            primes.push_back(number);
        }

        return isPrime;
    } else {
        return false;
    }
}

int main() {
    vector<int> primesFound;
    int max;

    cout << "Max number you want is: ";
    cout << "\n";

    cin >> max;

    for (int i = 2; i <= max; ++i) {
        if (isPrime(i)) {
            primesFound.push_back(i);
        }
    }

    cout << "Primes between 1 - " << max << " are: ";
    cout << "\n";

    int count = 0;
    for (int prime : primesFound) {
        cout << prime;
        cout << "\n";

        ++count;
    }

    cout << "Total primes found: " << count;
    cout << "\n";
}