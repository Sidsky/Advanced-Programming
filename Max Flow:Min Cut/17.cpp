/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 207961
 * Submitted at:  2022-03-30 08:28:17
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    17
 * Problem Name:  The Problem with the Problem Setter
 */

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int graph[1022][1022];
int resGraph[1022][1022];

bool bfs(int source, int sink, int *parent){
    int visited[sink+1];
    memset(visited, 0, sizeof (visited));
    memset(parent, -1, sizeof (parent));

    visited[source]=1;
    parent[source] = source;

    queue<int> Q;
    Q.push(source);

    while(!Q.empty()){
        int t;
        t = Q.front(); Q.pop();

        for(int i=0; i<=sink; i++) {
            if(!visited[i] && resGraph[t][i] > 0){
                Q.push(i);
                parent[i]=t;
                visited[i]=1;
                if(i==sink){
                    return true;
                }
            }
        }
    }
    return false;
}

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;
    int parent[sink+1];

    while(bfs(source, sink, parent)){
        int resFlow = 1e9;

        for(int i=sink; i!=source; i=parent[i]){
            resFlow = min(resFlow, resGraph[parent[i]][i]);
        }
        for(int i=sink; i!= source; i=parent[i]){
            resGraph[parent[i]][i] -= resFlow;
            resGraph[i][parent[i]] += resFlow;
        }
        maxFlow+=resFlow;
    }
    return maxFlow;
}

int main(){
    int categories, problems;

    while(cin>>categories>>problems && categories){
        int source = 0;
        int sink = categories + problems + 1;
        int totalFlow = 0;

        for(int i=0; i<=sink; i++){
            for(int j=0; j<=sink; j++){
                graph[i][j]=0;
                resGraph[i][j]=0;
            }
        }

        for(int i=1; i<=categories; i++){
            int c; cin>>c;
            graph[source][i]=c;
            resGraph[source][i]=c;
            totalFlow += c;
        }

        for(int i=categories + 1; i < sink; i++){
            int s; cin>>s;
            graph[i][sink] = 1;
            resGraph[i][sink] = 1;

            while(s--){
                int c; cin>>c;
                graph[c][i] = 1;
                resGraph[c][i] = 1;
            }
        }

        int maxFlow = fordFulkerson(source, sink);

        int result = maxFlow==totalFlow?1:0;
        cout<<result<<endl;

        if (result==1) {
            for (int i = 1; i <= categories; i++) {
                bool first=true;
                for (int j = categories + 1; j < sink; j++) {
                    if (resGraph[j][i]==1) {
                        if (!first) cout<<" ";

                        cout<<j-categories;
                        first= false;
                    }
                }
                cout<<endl;
            }
        }
    }
}
//3 15
//3 3 4
//2 1 2
//1 3
//1 3
//1 3
//1 3
//3 1 2 3
//2 2 3
//2 1 3
//1 2
//1 2
//2 1 2
//2 1 3
//2 1 2
//1 1
//3 1 2 3
//3 15
//7 3 4
//2 1 2
//1 1
//1 2
//1 2
//1 3
//3 1 2 3
//2 2 3
//2 2 3
//1 2
//1 2
//2 2 3
//2 2 3
//2 1 2
//1 1
//3 1 2 3
//0 0
