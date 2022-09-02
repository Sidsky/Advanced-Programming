/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 208879
 * Submitted at:  2022-04-06 18:36:09
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    379
 * Problem Name:  Escape
 */

#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>

#define MAX 125005
#define SOLDIERS 505

using namespace std;

struct Edge {
    int v, c, r;
    Edge (int aV, int aC, int aR) {
        v=aV; c=aC; r=aR;
    }
};

vector<Edge> Trial[MAX];
int level [SOLDIERS];
int start [SOLDIERS];

void insertEdge(int u, int v, int c) {
    Edge g (v, c, Trial[v].size());
    Edge r (u, 0, Trial[u].size());

    Trial[u].push_back(g);
    Trial[v].push_back(r);
}

bool BFS(int S, int T) {
    memset(level, -1, sizeof (level));
    queue<int> Q;

    Q.push(S);
    level[S] = 0;

    while (!Q.empty()){
        int t = Q.front(); Q.pop();

        for(int i=0; i<Trial[t].size(); i++){
            int n = Trial[t][i].v;
            int c = Trial[t][i].c;

            if (level[n] < 0 && c > 0) {
                level[n] = level[t] + 1;
                Q.push(n);
            }
        }
    }
    return level[T] >= 0;
}

int Dinics (int S, int T, int F) {

    if (S == T) {
        return F;
    }

    for (; start[S] < Trial[S].size(); start[S]++){
        int n = Trial[S][start[S]].v;
        int c = Trial[S][start[S]].c;
        int r = Trial[S][start[S]].r;

        if (level [n] > level[S] && c > 0) {
            int flow = Dinics(n, T, min(F, c));

            if (flow > 0) {
                Trial[S][start[S]].c -= flow;
                Trial[n][r].c += flow;
                return flow;
            }
        }
    }
    return 0;
}
int maxFlow(int S, int T) {
    int maxFlow = 0;

    while (BFS(S, T)) {
        memset(start, 0, sizeof (start));
        while (int flow = Dinics(S, T, 1e9)){
            maxFlow += flow;
        }
    }
    return maxFlow;
}

void reset(int N) {
    for (int i=0; i<=N; i++){
        Trial[i].clear();
    }
}

int main() {
    int L, W, N, D, X, Y, S, T;

    while(scanf("%d %d %d", &L, &W, &N) != EOF) {
        reset(N*2+2);

        D = 100;
        int x[N+1], y[N+1];
        S = 0; T = 2*N+1;

        for(int i=1; i<=N; i++) {
            scanf("%d %d", &X, &Y);
            x[i]=X; y[i]=Y;

            insertEdge(i*2-1, i*2, 1);

            if(W - Y <= D){
                insertEdge(S, i*2-1, 1);
            }
            if(Y <= D) {
                insertEdge(i*2, T, 1);
            }
            for(int j = i-1; j > 0; j--) {
                if (pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2) <= pow(2*D, 2)){
                    insertEdge(j*2,i*2-1, 1);
                    insertEdge(i*2, j*2-1, 1);
                }
            }
        }
        printf("%d\n", maxFlow(S, T));
    }
}
//130 340 5
//10 50
//130 130
//70 170
//0 180
//60 260
//500 300 4
//250 0
//250 300
//100 150
//400 150
