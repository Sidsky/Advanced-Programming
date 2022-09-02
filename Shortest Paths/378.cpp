/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202113
 * Submitted at:  2022-02-22 22:38:29
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    378
 * Problem Name:  Monster Synthesis
 */

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202055
 * Submitted at:  2022-02-22 16:11:58
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    378
 * Problem Name:  Monster Synthesis
 */

#include <math.h>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int oo=1e9;

struct Monster{
    int M, C, L, H;
    Monster(int aM, int aC, int aL, int aH){
        M=aM; C=aC; L=aL; H=aH;
    }
    bool operator<(const Monster &monster)const{
        return C > monster.C;
    }
};
int main() {
    int M, N;
    int level[101];
    int cost[101];
    int MS[101][101];
    int d[101];

    while(~scanf("%d %d", &M, &N)) {

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                MS[i][j]=oo;
            }
        }

        int P, L, S;
        for(int i=1; i<=N; i++) {
            scanf(" %d %d %d", &P, &L, &S);
            cost[i]=P;
            level[i]=L;

            int e, c;
            while(S--){
                scanf(" %d %d", &e, &c);
                MS[e][i]=c;
            }
        }

        int minSynthesis=cost[1];
        priority_queue<Monster> Q;

        for(int s=1; s<=N; s++) {
            while(!Q.empty()) Q.pop();
            d[s]=0;
            for(int j=1; j<=N; j++) {
                d[j]=oo;
                if(MS[s][j]!=oo && abs(level[s]-level[j])<=M){
                    Q.push(Monster(j, MS[s][j]+ cost[s], min(level[s], level[j]), max(level[s], level[j])));
                    d[j] = MS[s][j] + cost[s];
                }
            }

            while (!Q.empty()) {
                Monster monster = Q.top(); Q.pop();
                int cM=monster.M;
                int cC=monster.C;
                int cL=monster.L;
                int cH=monster.H;
                if (cM==1){
                    minSynthesis=min(minSynthesis, cC); break;
                }

                for(int i=1; i<=N; i++) {
                    if(MS[cM][i]!=oo && abs(cL-level[i]) <= M && abs(cH-level[i]) <= M && (d[i] > d[cM] + MS[cM][i])){
                        Q.push(Monster(i, d[cM] + MS[cM][i], min(cL, level[i]), max(cH, level[i])));
                        d[i]=d[cM] + MS[cM][i];
                    }
                }
            }
        }
        printf("%d\n", minSynthesis);
    }
    return 0;
}
//1 4
//10000 3 2
//2 8000
//3 5000
//1000 2 1
//4 200
//3000 2 1
//4 200
//50 2 0

//1 5
//10000 3 2
//2 5000
//3 5000
//3000 2 1
//4 500
//3000 4 1
//4 400
//1000 3 1
//5 100
//100 2 0

//1 5
//10000 1 2
//2 5000
//3 5000
//3000 2 1
//4 500
//3000 4 1
//4 400
//1000 3 1
//5 100
//100 2 0
