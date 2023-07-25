#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string board[3];

        for (int i = 0 ; i<3; i++) {
            cin >> board[i];
        }
        
        char ans = 46;
        for (int i = 0; i<3; i++){
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                if (board[i][0] != 46) {
                    ans = board[i][0];
                    break;
                }
            }
            else if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                if (board[0][i] != 46) {
                ans = board[0][i];
                break;
            }
            }
        }
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            if (board[1][1] != 46)
            ans = board[0][0];
        }
        else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
             if (board[1][1] != 46)
             ans = board[0][2];

    }
    if (ans == 46) {
        cout << "DRAW" << endl;
    }
    else {
        cout << ans << endl;
    }

}
return 0;
}