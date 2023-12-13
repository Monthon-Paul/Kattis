// https://open.kattis.com/problems/vemvinner
#include <iostream>
using namespace std;

int main() {
    char l, m, r;
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        cin >> l >> m >> r;
        board[i][0] = l;
        board[i][1] = m;
        board[i][2] = r;
    }
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {  // top horizontal
        if (board[0][1] == '_') cout << "ingen har vunnit" << endl;
        else if (board[0][1] == 'X') cout << "Johan har vunnit" << endl;
        else cout << "Abdullah har vunnit" << endl;
    } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) {  // bottom
        if (board[2][1] == '_') cout << "ingen har vunnit" << endl;
        else if (board[2][1] == 'X') cout << "Johan har vunnit" << endl;
        else cout << "Abdullah har vunnit" << endl;
    } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {  // left vertical
        if (board[1][0] == '_') cout << "ingen har vunnit" << endl;
        else if (board[1][0] == 'X') cout << "Johan har vunnit" << endl;
        else cout << "Abdullah har vunnit" << endl;
    } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) {  // right
        if (board[1][2] == '_') cout << "ingen har vunnit" << endl;
        else if (board[1][2] == 'X') cout << "Johan har vunnit" << endl;
        else cout << "Abdullah har vunnit" << endl;
    } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
               board[0][2] == board[1][1] && board[1][1] == board[2][0] ||
               board[1][0] == board[1][1] && board[1][1] == board[1][2] ||
               board[0][1] == board[1][1] && board[1][1] == board[2][1]) {  // all mid
        if (board[1][1] == '_')
            cout << "ingen har vunnit" << endl;
        else if (board[1][1] == 'X')
            cout << "Johan har vunnit" << endl;
        else
            cout << "Abdullah har vunnit" << endl;
    } else {
        cout << "ingen har vunnit" << endl;
    }
    return 0;
}