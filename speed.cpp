// https://open.kattis.com/problems/speed
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
  int n;
  double t, c, result = 0.0, error = 1e-9;

  // Read input
  cin >> n >> t;

  // make both list for d & s
  vector<double> d(n), s(n);

  // set every value down length n for both d & S
  for (int i = 0; i < n; i++) cin >> d[i] >> s[i];

  // Initialize both upper & lower bound
  double upper_b = 1e7;
  double lower_b = -(*min_element(s.begin(), s.end()));

  // approximating Binary Search
  for (int j = 0; j < 1000; j++) {
    c = (lower_b + upper_b) / 2.0;
    result = 0.0;

    // calculations: t = (i = 0 Σ i = n d_i / (s_i + c)
    for (int i = 0; i < n; i++) result += d[i] / (s[i] + c);

    // check that total time difference to result to be close to the error approximation
    if (abs(t - result) <= error) break;

    // when the result is greater than total time,
    // c needs to increase in value. Otherwise, c decrease in value 
    if (result > t) {
      lower_b = c;
    } else {
      upper_b = c;
    }
  }
  // display c
  cout << setprecision(9) << c << endl;
}