// https://open.kattis.com/problems/sangbok
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, songs, sum = 0;
    cin >> t >> n;
    vector<int> list;
    for( int i = 0; i < n; i++) {
        cin >> songs;
        list.push_back(songs);
    }
    sort(list.begin(), list.end());
    int bound = t * 60;
    for (auto &e : list) {
        if(sum + e < bound)
            sum += e;
    }
    cout << sum << endl;
}