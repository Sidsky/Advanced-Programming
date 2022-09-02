/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 200418
 * Submitted at:  2022-02-05 16:29:29
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    247
 * Problem Name:  Fire! (UVa 11624)
 */

//
//  main.cpp
//  Fire! (UVa 11624)
//
//  Created by Siddharth Mehrotra on 4/2/2022.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

int maze[1001][1001];
int joey[1001][1001];
int fire[1001][1001];
int d[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

struct Grid{
    int r,c;
    bool isFire;

    Grid(int aR, int aC, bool aIsFire) {
        r=aR; c=aC; isFire=aIsFire;
    }
};

void multiSourceBFS(queue<Grid> &Q, int &R, int &C){
    bool isFire;
    bool escaped = false;
    int alive = 1;

    while(!Q.empty() && !escaped && alive > 0) {
        Grid grid = Q.front(); Q.pop();
        isFire = grid.isFire;

        if(isFire){


            for (int i=0; i<4; i++) {
                int nr = grid.r + d[0][i]; //d[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
                int nc = grid.c + d[1][i];

                if((nr>-1 && nr < R && nc>-1 && nc<C) && (fire[nr][nc]==0 && maze[nr][nc]!=2)) {
                    maze[nr][nc] = 1;
                    fire[nr][nc] = 1;
                    Q.push(Grid(nr, nc, true));
                }
            }
        }
        else {
            alive--;
            for (int i=0; i<4; i++) {
                int nr = grid.r + d[0][i];
                int nc = grid.c + d[1][i];

                if(nr<0 || nr>=R || nc<0 || nc>=C) {
                    printf("%d\n", joey[grid.r][grid.c] + 1);
                    escaped=true;
                    break;
                }
                else if (joey[nr][nc]==0 && maze[nr][nc]==0){
                    joey[nr][nc] = joey[grid.r][grid.c] + 1;
                    Q.push(Grid(nr, nc, false));
                    alive++;
                }
            }
        }
    }
    if (!escaped){
        printf("IMPOSSIBLE\n");
    }
}
int main() {
    int T; scanf("%d", &T);

    while (T--) {

        queue<Grid> Q;
        Grid *source = NULL;

        int R, C; scanf("%d %d\n", &R, &C);

        for(int i=0; i<R; i++){

            for(int j=0; j<C; j++) {

                maze[i][j]=0;
                joey[i][j]=0;
                fire[i][j]=0;

                char c; scanf(" %c", &c);

                if(c=='#'){
                    maze[i][j]=2;
                }
                else if(c=='F'){
                    maze[i][j]=1;
                    Q.push(Grid(i, j, true));
                }
                else if(c=='J') {
                    maze[i][j]=3;
                    source = new Grid(i, j, false);
                }
            }
        }
        Q.push(*source);
        multiSourceBFS(Q, R, C);
    }
}
