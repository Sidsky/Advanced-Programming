/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 201635
 * Submitted at:  2022-02-17 22:25:40
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    165
 * Problem Name:  Frogger (UVa 534) (Precision)
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
    int N;
    double frogger[201][201];
    int X[201], Y[201];
    int c=1;
    while(scanf("%d", &N) && N) {

        for (int i = 0; i < N; i++) {
            scanf(" %d %d", &X[i], &Y[i]);
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                frogger[i][j] = frogger[j][i] = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                for(int k=0; k<N; k++) {
                    if(i!=j && j!=k && i!=k){
                        frogger[j][k] = min(frogger[j][k], max(frogger[j][i], frogger[i][k]));
                    }
                }
            }
        }

        printf("Scenario #%d\n", c++);
        printf("Frog Distance = %.3lf\n\n", frogger[1][0]);

    }
}
