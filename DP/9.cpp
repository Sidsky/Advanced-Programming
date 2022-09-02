#include <iostream>
#include <cstring>
using namespace std;

int DP[21][21];
int BT[21][21];
string m, n;

void backTrack(int i, int j){
    if(i==0 && j==0) {
        return;
    }
    if (BT[i][j]==1){
        backTrack(i-1, j-1);
    }
    else if (BT[i][j] == 2){
        backTrack(i-1, j);
        printf("D%c%02d", m[i-1], j+1);
    }
    else if(BT[i][j] == 3){
        backTrack(i, j-1);
        printf("I%c%02d", n[j-1], j);
    } else {
        backTrack(i-1, j-1);
        printf("C%c%02d", n[j-1], j);
    }
}
int main() {

    while (cin>>m) {
        if(m[0]=='#')break;
        cin>>n;

        memset(DP, 63, sizeof (DP));
        DP[0][0] = 0;

        for(int i = 0; i <= m.size(); i++) {
            for(int j = 0; j <= n.size(); j++) {
                if(m[i] == n[j] && DP[i + 1][j + 1] > DP[i][j]) {
                    DP[i + 1][j + 1] = DP[i][j];
                    BT[i + 1][j + 1] = 1;
                }
                if(DP[i + 1][j] > DP[i][j] + 1) {
                    DP[i + 1][j] = DP[i][j] + 1;
                    BT[i + 1][j] = 2;
                }
                if(DP[i][j + 1] > DP[i][j] + 1) {
                    DP[i][j + 1] = DP[i][j] + 1;
                    BT[i][j + 1] = 3;
                }
                if(DP[i + 1][j + 1] > DP[i][j] + 1) {
                    DP[i + 1][j + 1] = DP[i][j] + 1;
                    BT[i + 1][j + 1] = 4;
                }
            }
        }
        backTrack(m.size(), n.size());
        cout<<"E"<<endl;
    }
    return 0;
}
