/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 201659
 * Submitted at:  2022-02-18 11:18:51
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    251
 * Problem Name:  How Many Islands? (Japan Local 2009)
 */

#include <cstdio>
#include <stack>
#include <utility>

using namespace std;

void howManyIslands (int map[53][53], int w, int h){
    stack<pair<int, int >> S;
    int islands=0;

    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {

            if (map[i][j] == 1) {
                islands++;
                S.push(make_pair(i, j));

                while (!S.empty()) {
                    pair<int, int> t = S.top();
                    S.pop();

                    if (map[t.first - 1][t.second] == 1) {
                        S.push(make_pair(t.first - 1, t.second));
                        map[t.first - 1][t.second] = 0;
                    }
                    if (map[t.first - 1][t.second + 1] == 1) {
                        S.push(make_pair(t.first - 1, t.second + 1));
                        map[t.first - 1][t.second + 1] = 0;
                    }
                    if (map[t.first][t.second + 1] == 1) {
                        S.push(make_pair(t.first, t.second + 1));
                        map[t.first][t.second + 1] = 0;
                    }
                    if (map[t.first + 1][t.second + 1] == 1) {
                        S.push(make_pair(t.first + 1, t.second + 1));
                        map[t.first + 1][t.second + 1] = 0;
                    }
                    if (map[t.first + 1][t.second] == 1) {
                        S.push(make_pair(t.first + 1, t.second));
                        map[t.first + 1][t.second] = 0;
                    }
                    if (map[t.first + 1][t.second - 1] == 1) {
                        S.push(make_pair(t.first + 1, t.second - 1));
                        map[t.first + 1][t.second - 1] = 0;
                    }
                    if (map[t.first][t.second-1] == 1) {
                        S.push(make_pair(t.first, t.second-1));
                        map[t.first][t.second-1] = 0;
                    }
                    if (map[t.first - 1][t.second - 1] == 1) {
                        S.push(make_pair(t.first - 1, t.second - 1));
                        map[t.first - 1][t.second - 1] = 0;
                    }
                }
            }
        }
    }
    printf("%d\n", islands);
}

int main() {
    int map[53][53];
    int w, h;

    while(scanf("%d %d", &w, &h) && w && h) {

        for(int i=0; i<53; i++){
            for(int j=0; j<53; j++){
                map[i][j]=0;
            }
        }

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                scanf(" %d", &map[i][j]);
            }
        }
        howManyIslands(map, w, h);
    }
    return 0;
}
