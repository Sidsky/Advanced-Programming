/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 201743
 * Submitted at:  2022-02-19 12:41:32
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    172
 * Problem Name:  Rough Roads (UVa 10356)
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int oo=1e9;

struct Node{
    int v, d;
    Node(int aV, int aD){
        v=aV;
        d=aD;
    }

    bool operator < (const Node &n) const{
        return d > n.d;
    }
};

int main() {
    priority_queue<Node> Q;

    int n,r;
    int c=1;

    while (~scanf("%d %d", &n, &r)){

        vector<Node> map[n+1];
        vector<Node>reducedmap[n+1];

        int x, y, w;

        while(r--){
            scanf(" %d %d %d", &x, &y, &w);
            map[x].push_back(Node(y, w));
            map[y].push_back(Node(x, w));
        }

        queue<int> RQ;
        RQ.push(0);
        unordered_set<int> done;

        while(!RQ.empty()){
            int v=RQ.front(); RQ.pop();
            done.insert(v);
            for(int i =0; i<map[v].size(); i++){
                int nv = map[v][i].v;

                for(int j=0; j <map[nv].size(); j++){
                    int nvv = map[nv][j].v;
                    if (done.find(nvv) == done.end()) {
                        reducedmap[v].push_back(Node(nvv, map[v][i].d + map[nv][j].d));
                        reducedmap[nvv].push_back(Node(v, map[v][i].d + map[nv][j].d));
                        RQ.push(nvv);
                    }
                }
            }
        }

        int distance [n+1];
        for(int i=0; i<=n; i++) distance[i]=oo;
        distance[0]=0;

        for(int i=0; i<reducedmap[0].size(); i++){
            Q.push(Node(reducedmap[0][i].v, reducedmap[0][i].d));
            distance[reducedmap[0][i].v]= reducedmap[0][i].d;
        }

        while (!Q.empty()){
            Node t = Q.top(); Q.pop();

            for(int i=0; i<reducedmap[t.v].size(); i++) {
                Node  nn = reducedmap[t.v][i];
                if(distance[nn.v] > nn.d + distance[t.v]) {
                    int d = min(distance[nn.v], nn.d + distance[t.v]);
                    distance[reducedmap[t.v][i].v] = d;
                    Q.push(Node(reducedmap[t.v][i].v, d));
                }
            }
        }

        printf("Set #%d\n", c++);
        if(distance[n-1]>=oo){
            printf("?\n");
        } else {
            printf("%d\n", distance[n-1]);
        }
    }
    return 0;
}
//5 6
//0 1 10
//1 2 10
//0 2 10
//2 3 10
//2 4 10
//4 5 10
