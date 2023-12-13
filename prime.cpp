// https://open.kattis.com/problems/primereduction
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int limit = 31622;  // sqrt(10^9)

/**
 * Generate all prime numbers up to a given number (DP technique memoization)
 * Using this algorithm technique https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * (this is really interestng read)
 */
void generatePrimes(vector<int>& primes) {
    vector<bool> isPrime(limit + 1, true);

    isPrime[0] = isPrime[1] = false;

    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (int p = 2; p <= limit; p++) {
        if (isPrime[p])
            primes.push_back(p);
    }
}

/**
 * Calculate both the sum & determine if original is a prime number
 */
pair<int, bool> smallestPrimeFactor(int n, vector<int>& primes) {
    int sum = 0, count = 1;
    bool check = true;
    // Edge case:2 is the only prime even number
    if (n == 2)
        return {sum, check};

    // Primes are not even
    while (!(n & 0x1)) {
        n = n / 2;
        sum += 2;
        check = false;
    }

    // go through all the primes generated.
    for (int i = primes[count]; i <= sqrt(n); i = primes[++count]) {
        while (!(n % i)) {
            sum += i;
            n = n / i;
            check = false;
        }
    }

    // add remaining prime
    if (n > 2)
        sum += n;
    return {sum, check};
}

int main() {
    int input, count;
    vector<int> primes;
    generatePrimes(primes);
    while (true) {
        count = 1;
        // read input
        cin >> input;
        pair<int, bool> prime = smallestPrimeFactor(input, primes);  // calculate both if it's prime & sum
        if (input == 4) break;
        if (prime.second) {
            cout << input << " " << count << endl;
        } else {
            do {
                prime = smallestPrimeFactor(prime.first, primes);
                count++;
            } while (!prime.second);
            cout << prime.first << " " << count << endl;
        }
    }
}
