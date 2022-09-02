/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 215064
 * Submitted at:  2022-05-02 19:49:12
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    126
 * Problem Name:  Risk (UVa 567)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 21
using namespace std;

vector<int> R [MAX_N];
int visited[MAX_N];
queue<int> Q;

int BFS(int S, int T){

    memset(visited, -1, sizeof (visited));
    while (!Q.empty()) Q.pop();

    visited[S]=0;
    Q.push(S);

    while (!Q.empty()){
        int t = Q.front(); Q.pop();
        if(t == T){
            return visited[t];
        }
        for (int i=0; i<R[t].size(); i++){
            int n = R[t][i];

            if(visited[n]<0){
                visited[n] = visited[t]+1;
                Q.push(n);
            }
        }
    }
    return 0;
}
void reset(){
    for (int i=0; i<21; i++){
        R[i].clear();
    }
}
int main() {
    int count=1;

    while(true){
        reset();
        for (int i=1; i<20; i++){
            int numCountries; cin>>numCountries;
            if(numCountries==EOF) return 0;

            while(numCountries--){
                int c; cin>>c;
                R[i].push_back(c);
                R[c].push_back(i);
            }
        }
        int q; cin>>q;

        printf("Test Set #%d\n", count++);

        while (q--){
            int a, b; cin>>a>>b;
            printf("%2d to %2d: %d\n", a, b,BFS(a, b));
        }
        printf("\n");
    }
    return 0;
}
//1 3
//2 3 4
//3 4 5 6
//1 6
//1 7
//2 12 13
//1 8
//2 9 10
//1 11
//1 11
//2 12 17
//1 14
//2 14 15
//2 15 16
//1 16
//1 19
//2 18 19
//1 20
//1 20
//5
//1 20
//2 9
//19 5
//18 19
//16 20
