/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 211984
 * Submitted at:  2022-04-22 14:47:09
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    489
 * Problem Name:  Romantically Involved
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_R 1003

int level[MAX_R];
int visited[MAX_R];

struct Edge{
    int v, c, r;
    Edge(int _v, int _c, int _r){
        v=_v; c=_c; r=_r;
    }
};

vector<Edge> Rabbits[MAX_R];

bool BFS(int S, int T){
    memset(level, -1, sizeof (level));

    queue<int> Q;
    Q.push(S);
    level[S]=0;

    while(!Q.empty()){
        int t = Q.front(); Q.pop();

        for(int i=0; i<Rabbits[t].size(); i++){
            int n = Rabbits[t][i].v;
            int c = Rabbits[t][i].c;

            if(level[n]==-1 && c>0){
                level[n]=level[t]+1;
                Q.push(n);
            }
        }
    }
    return level[T] >= 0;
}
void addEdge(int u, int v, int c){
    Edge g (v, c, Rabbits[v].size());
    Edge r (u, 0, Rabbits[u].size());

    Rabbits[u].push_back(g);
    Rabbits[v].push_back(r);
}

int DFS(int S, int T, int F){

    if(S == T){
        return F;
    }

    for(; visited[S]<Rabbits[S].size(); visited[S]++){
        int n = Rabbits[S][visited[S]].v;
        int c = Rabbits[S][visited[S]].c;
        int r = Rabbits[S][visited[S]].r;

        if(level[n] > level[S] && c > 0){
            int flow = DFS(n, T, min(F, c));

            if (flow > 0) {
                Rabbits[S][visited[S]].c -= flow;
                Rabbits[n][r].c += flow;
                return flow;
            }
        }
    }
    return 0;
}
int MCBM(int S, int T){
    int maxFlow = 0;
    while (BFS(S, T)){
        memset(visited, 0, sizeof (visited));

        while(int flow = DFS(S, T, 1e9)){
            maxFlow += flow;
        }
    }
    return maxFlow;
}
void reset(int T){
    for(int i=0; i<=T; i++){
        Rabbits[i].clear();
    }
}
int main() {
    int R, S, T, I, N;
    while(cin >> R){
        S = 2*R; T = S+1;
        reset(T);
        for(int i=0; i<R; i++){
//            scanf("%d: (%d)", I, N);
            cin>>I; getchar(); getchar(); getchar(); cin>>N; getchar();
            addEdge(S, I, 1);
            addEdge(I+R, T, 1);

            while(N--){
                int r; cin>>r;
                addEdge(I, r+R, 1);
            }
        }
        cout<<R-MCBM(S, T)/2<<endl;
    }
}
//7
//0: (3) 4 5 6
//1: (2) 4 6
//2: (0)
//3: (0)
//4: (2) 0 1
//5: (1) 0
//6: (2) 0 1
//3
//0: (2) 1 2
//1: (1) 0
//2: (1) 0
