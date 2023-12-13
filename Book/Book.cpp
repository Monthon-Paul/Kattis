// https://open.kattis.com/problems/bokhyllor
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
using namespace std;

map<tuple<int, int, int, int>, int> memo;

int minsubset(int b1, int b2, int b3, int shelf, int books) {
    // Base case: if there are no books, return whether there are any books on the shelf 
    if (b1 == 0 && b2 == 0 && b3 == 0)
        return books != 0;
    tuple<int, int, int, int> tup = make_tuple(b1, b2, b3, books);
    // Don't do repeated work
    if (memo.count(tup)) 
        return memo[tup];
    int result = INT_MAX;
    // Books of width 3
    if(b3) {
        if (shelf - 3 >= books)
            // place the book on the current shelf  
            result = min(result, minsubset(b1, b2, b3 - 1, shelf, books + 3));
        else
            // place the book on a new shelf 
            result = min(result, 1 + minsubset(b1, b2, b3 - 1, shelf, 3));
    }
    // Books of width 2
    if(b2) {
        if (shelf - 2 >= books)
            // place the book on the current shelf 
            result = min(result, minsubset(b1, b2 - 1, b3, shelf, books + 2));
        else
            // place the book on a new shelf 
            result = min(result, 1 + minsubset(b1, b2 - 1, b3, shelf, 2));
    }
    // Books of width 1
    if(b1) {
        if (shelf - 1 >= books) 
            // place the book on the current shelf
            result = min(result, minsubset(b1 - 1, b2, b3, shelf, books + 1));
        else 
            // place the book on a new shelf
            result = min(result, 1 + minsubset(b1 - 1, b2, b3, shelf, 1));
    }
    return memo[tup] = result;
}

int main() {
    int b1, b2, b3, shelf;
    cin >> b1 >> b2 >> b3 >> shelf;
    vector<int> val;
    int count = minsubset(b1, b2, b3, shelf, 0);
    cout << count << endl;
    return 0;
}