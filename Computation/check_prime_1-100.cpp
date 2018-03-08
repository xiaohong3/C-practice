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

vector<int> getFirstNPrimes(unsigned n) {
    vector<int> primeSequence;
    int i = 2;
    while(primeSequence.size() <= n) {
        if (isPrime(i)) {
            primeSequence.push_back(i);
        }
        ++i;
    }
    return primeSequence;
}

vector<int> getPrimes(unsigned max) {
    vector<int> primesFound;
    for (unsigned i = 2; i <= max; ++i) {
        if (isPrime(i)) {
            primesFound.push_back(i);
        }
    }
    return primesFound;
}

int main() {
    // unsigned max;
    // cout << "Max number you want is: ";
    // cout << "\n";
    // cin >> max;
    // for(unsigned i : getPrimes(max)) {
    //     cout << i;
    //     cout << "\n";
    // }

    unsigned n;
    cout << "The number of primes you want is: ";
    cout << "\n";
    cin >> n;
    for (unsigned i : getFirstNPrimes(n)) {
        cout << i;
        cout << "\n";
    }
}