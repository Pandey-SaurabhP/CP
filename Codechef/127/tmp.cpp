#include <bits/stdc++.h>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

int minProduct(int a, int x) {
    vector<int> primeFactorsList = primeFactors(a);
    int min_y = INT_MAX;
    int n = primeFactorsList.size();
    for (int r = 1; r <= n; r++) {
        vector<bool> bitmask(n);
        fill(bitmask.begin(), bitmask.begin() + r, true);
        do {
            int product = 1;
            for (int i = 0; i < n; i++) {
                if (bitmask[i]) {
                    product *= primeFactorsList[i];
                }
            }
            if (product >= x) {
                min_y = min(min_y, product);
            }
        } while (prev_permutation(bitmask.begin(), bitmask.end()));
    }
    return min_y;
}

int main() {
    int a = 1024; // 2^32
    int x = 10;
    cout << "Minimum value of y such that y >= x: " << minProduct(a, x) << endl;
    return 0;
}
