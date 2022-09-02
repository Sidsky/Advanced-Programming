/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 199384
 * Submitted at:  2022-01-25 15:17:21
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    22
 * Problem Name:  Prime Path
 */

//
//  main.cpp
//  Prime Path
//
//  Created by Siddharth Mehrotra on 20/1/2022.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <cstring>

#define SMALL 2
#define LARGE 10000

using namespace std;

typedef vector<int> vi;
typedef list<int> li;
typedef map<int, int> mi;

vi adj[1061];
mi numbers;

void init(vi &prime, mi &map, mi &numbers) {
    bool primes [10000];
    memset(primes, true, sizeof(primes));

    for(int i=SMALL; i*i<LARGE; i++){
        if(primes[i]==true){
            for(int j=i*i; j<LARGE; j+=i){
                primes[j]=false;
            }
        }
    }
    for(int i=1000; i<LARGE; i++){
        if(primes[i]){
            map.insert({i, prime.size()});
            numbers.insert({prime.size(), i});
            prime.push_back(i);
        }
    }
}

bool oneDigit(int a, int b){
    int count=4;
    for(int i=0; i<4; i++){
        int aa = a%10; int bb = b%10;

        if (aa==bb)
            count--;

        a=a/10; b=b/10;
    }
    return count==1;
}

void createGraph(vi &prime){

    for(int i=0; i<prime.size(); i++){
        for(int j=i+1; j<prime.size(); j++){
            if(oneDigit(prime[i], prime[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

int primePath(int s, int e){
    int visited[1061]={0};

    queue<int> Q;
    Q.push(s);
    visited[s]=1;
    if (s==e) return 1;
    while(!Q.empty()){
        int top = Q.front(); Q.pop();
        int topdec = numbers.find(top)->second;

        for (int i=0; i<adj[top].size(); i++){
            if(!visited[adj[top][i]]){
                int curr =numbers.find(adj[top][i])->second;

                visited[adj[top][i]] = visited[top]+1;
                Q.push(adj[top][i]);
            }
            if(adj[top][i] == e) {
                return visited[adj[top][i]];
            }
        }
    }
    return -1;
}
int main() {
    vi prime;
    mi map;


    init(prime, map, numbers);
    createGraph(prime);

    int T; scanf("%d", &T);

    while(T--) {
        int S, E; scanf("%d %d", &S, &E);

        int shortestPath = primePath(map.find(S)->second, map.find(E)->second);

        if (shortestPath != -1){
            printf("%d\n", shortestPath-1);
        } else {
            printf("%s\n", "Impossible");
        }
    }
    return 0;
}
