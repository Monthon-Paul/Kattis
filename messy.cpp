// https://open.kattis.com/problems/stokigalistor
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ele, count = 0;
    vector<int> messy;
    vector<int> sorted;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ele;
        messy.push_back(ele);
        sorted.push_back(ele);
    }
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < n; i++) {
        if(messy[i] != sorted[i])
            count++;
    }

    cout << count << endl;
    return 0;
}