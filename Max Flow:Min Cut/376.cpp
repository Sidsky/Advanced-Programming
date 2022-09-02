/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 211525
 * Submitted at:  2022-04-20 17:32:39
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    376
 * Problem Name:  PIGS
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#define NODES 105

using namespace std;

struct Edge{
    int v, c, r;
    Edge(int _v, int _c, int _r){
        v = _v; c = _c; r = _r;
    }
};

vector<Edge> Farm[NODES];
int level[NODES];
int visited[NODES];
int combined[NODES];
int pigHouse[1001];
vector<int> pH[1001];

void addEdge(int u, int v, int c){
    Edge g (v, c, Farm[v].size());
    Edge r (u, 0, Farm[u].size());

    Farm[u].push_back(g);
    Farm[v].push_back(r);
}

bool BFS(int S, int T) {
    memset(level, -1, sizeof (level));

    queue<int> Q;
    Q.push(S);
    level[S] = 0;

    while (!Q.empty()){
        int t = Q.front(); Q.pop();

        for(int i=0; i<Farm[t].size(); i++) {
            int n = Farm[t][i].v;
            int c = Farm[t][i].c;

            if (level[n] < 0 && c > 0) {
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
    for(;visited[S]<Farm[S].size(); visited[S]++){
        int n = Farm[S][visited[S]].v;
        int c = Farm[S][visited[S]].c;
        int r = Farm[S][visited[S]].r;

        if (level[n] > level[S] && c > 0) {
            int flow = DFS(n, T, min(c, F));

            if(flow > 0) {
                Farm[S][visited[S]].c -= flow;
                Farm[n][r].c += flow;
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
void reset() {
    memset(combined, 0, sizeof (combined));
    memset(pigHouse, 0, sizeof (pigHouse));

    for(int i=0; i <= NODES; i++){
        Farm[i].clear();
        pH[i].clear();
    }
}
int main() {
    int M, N, S, T, m, A, p, B;

    while (scanf("%d %d", &M, &N)!=EOF) {

        S = 0; T = N+1;
        reset();

        for(int i=1; i<=M; i++) {
            cin>>m;
            pigHouse[i]=m;
        }

        for(int i=1; i<=N; i++) {
            cin>>A;
            while(A--) {
                cin>>p;
                pH[p].push_back(i);
            }
            cin>>B;
            addEdge(i, T, B);
        }

        for(int i=1; i<=M; i++){

            if(pH[i].size()>0) {
                combined[pH[i][0]] += pigHouse[i];

                for(int j=0; j<pH[i].size()-1; j++){
                    addEdge(pH[i][j], pH[i][j+1], 1e9);
                }
            }
        }

        for(int i=1; i<=N; i++) {
            if(combined[i]>0)
                addEdge(S, i, combined[i]);
        }
        cout<<maxFlow(S, T)<<endl;
    }
}
//3 3
//3 1 10
//3 1 2 3 2
//2 1 3 3
//1 2 6
