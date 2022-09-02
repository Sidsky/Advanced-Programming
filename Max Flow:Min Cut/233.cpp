/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 213130
 * Submitted at:  2022-04-27 00:09:50
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    233
 * Problem Name:  All Pairs Maximum Flow
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>

#define NODES 10000

using namespace std;

struct Edge{
    int v, c, f, r;
    Edge(int _v, int _c, int _f, int _r){
        v = _v; c = _c; f = _f; r = _r;
    }
};

vector<Edge> APMF[NODES];
int level[NODES];
int visited[NODES];
int cost[NODES][NODES];
int parent[NODES];

void addEdge(int u, int v, int c){
    Edge g (v, c, 0,APMF[v].size());
    Edge r (u, 0, 0, APMF[u].size());

    APMF[u].push_back(g);
    APMF[v].push_back(r);
}

bool BFS(int S, int T) {
    memset(level, -1, sizeof (level));

    queue<int> Q;
    Q.push(S);
    level[S] = 0;

    while (!Q.empty()){
        int t = Q.front(); Q.pop();

        for(int i=0; i < APMF[t].size(); i++) {
            int n = APMF[t][i].v;
            int c = APMF[t][i].c;
            int f = APMF[t][i].f;

            if (level[n] < 0 && f < c) {
                level[n] = level[t]+1;
                Q.push(n);
            }
        }
    }
    return level[T] >= 0;
}

int DFS(int S, int T, int F){
    if (S == T) {
        return F;
    }
    for(; visited[S] < APMF[S].size(); visited[S]++){
        int n = APMF[S][visited[S]].v;
        int c = APMF[S][visited[S]].c;
        int f = APMF[S][visited[S]].f;
        int r = APMF[S][visited[S]].r;


        if (level[n] > level[S] && f < c) {
            int flow = DFS(n, T, min(c-f, F));

            if(flow > 0) {
                APMF[S][visited[S]].f += flow;
                APMF[n][r].f -= flow;
                return flow;
            }
        }
    }
    return 0;
}
int maxFlow(int S, int T) {
    int maxflow = 0;

    while(BFS(S, T)) {
        memset(visited, 0, sizeof (visited));
        while (int flow = DFS(S, T, 1e9)){
            maxflow += flow;
        }
    }
    return maxflow;
}
void reset(int n) {
    for(int i=0; i <= n; i++){
        APMF[i].clear();
    }
}

void gomoryTree(int n){

    for(int i=1; i<=n; i++){
        parent[i]=1;
        for(int j=1; j<=n; j++){
            cost[i][j]=1e9;
        }
    }
    parent[1] = -1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<APMF[j].size(); k++){
                APMF[j][k].f = 0;
            }
        }
        int mf = maxFlow(i, parent[i]);

        for(int j = i+1; j<=n; j++){
            if(parent[i]==parent[j] && level[j] > 0){
                parent[j]=i;
            }
        }
        cost[i][parent[i]] = cost[parent[i]][i] = mf;
        for(int j=1; j<i; j++){
            cost[i][j] = cost[j][i] = min(mf, cost[parent[i]][j]);
        }
    }
}
int main() {
    int N, n, C = 1; cin>>N;

    while (N--){
        cin>>n;

        reset(n);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int e; cin>>e;
                addEdge(i, j, e);
            }
        }
        gomoryTree(n);
        printf("Case #%d:\n", C++);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){

                if(cost[i][j]==1e9) cost[i][j]=0;
                if(j!=1) cout<<" ";
                cout<<cost[i][j];
            }
            cout<<endl;
        }
    }
}
//4
//2
//0 2
//2 0
//6
//0 1 1 0 1 0
//1 0 0 1 0 1
//1 0 0 1 0 0
//0 1 1 0 0 0
//1 0 0 0 0 1
//0 1 0 0 1 0
//0
//1
//0

//2
//2
//0 2
//2 0
//2
//0 2
//2 0
