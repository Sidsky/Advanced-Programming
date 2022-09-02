/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 200438
 * Submitted at:  2022-02-05 18:25:28
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    267
 * Problem Name:  Avoid The Lakes
 */

//
//  main.cpp
//  Avoid the lakes
//
//  Created by Siddharth Mehrotra on 5/2/2022.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int farm[101][101];

struct Lake{
    int n, m;
    Lake(int aN, int aM){
        n=aN;
        m=aM;
    }
};

void DFS(int &N, int &M){

    stack<Lake> S;
    int d[2][4] = {{1,-1, 0, 0}, {0, 0, 1, -1}};
    int biggestLake = -1;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {

            if(farm[i][j]==1){
                S.push(Lake(i, j));
                farm[i][j]=0;
                int size=1;

                while (!S.empty()) {
                    Lake lake = S.top(); S.pop();

                    for (int k=0; k<4; k++){
                        int nn = lake.n + d[0][k];
                        int nm = lake.m + d[1][k];

                        if(nn != 0 && nn <= N && nm !=0 && nm <= M && farm[nn][nm] == 1){
                            S.push(Lake(nn, nm));
                            size++;
                            farm[nn][nm]=0;
                        }
                    }
                }
                if(size > biggestLake){
                    biggestLake = size;
                }
            }
        }
    }
    printf("%d\n", biggestLake);
}

int main() {
    int N, M, K;

    while (scanf("%d %d %d", &N, &M, &K) != EOF) {

        memset(farm, 0, sizeof(int) * 101 * 101);
        int ln, lm;

        while (K--) {
            scanf("%d %d", &ln, &lm);
            farm[ln][lm] = 1;
        }
        DFS(N, M);
    }
    return 0;
}
//3 4 5
//3 2
//2 2
//3 1
//2 3
//1 1

//7 7 24
//1 1
//1 2
//2 1
//2 2
//2 3
//2 5
//3 3
//3 4
//4 2
//4 3
//4 5
//4 6
//4 7
//5 2
//5 4
//5 5
//5 6
//6 3
//6 4
//6 7
//7 3
//7 4
//7 6
//7 7
