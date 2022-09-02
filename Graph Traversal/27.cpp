/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 199666
 * Submitted at:  2022-01-27 23:46:58
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    27
 * Problem Name:  Gems in the maze
 */

//
//  main.cpp
//  Gems in the maze
//
//  Created by Siddharth Mehrotra on 27/1/2022.
//

#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

void dfs (int &i, vector<int> adj[], int &possibleGems, int &n){

    stack<int> S;

    bool *visited = new bool[n];

//    for (int j=0; j<n; j++) visited[j]=false;
    memset(visited, false, sizeof(bool)*n);

    S.push(i);
    visited[i] = true;
    int count = 1;

    while (!S.empty()){
        int top = S.top();
        S.pop();

        if(!visited[adj[top][0]]) {
            count++;
            visited[adj[top][0]] = true;
            S.push(adj[top][0]);
        }
    }

    possibleGems = count>possibleGems?count:possibleGems;
}

int main (){
    int T; scanf("%d", &T);

    while(T--){
        int a, b, c, n; scanf("%d %d %d %d", &a, &b, &c, &n);

        vector<int> *adj = new vector<int> [n];

        for (int i=0; i<n; i++) {
            adj[i].push_back(((a*i*i) + (b*i) + c) % n);
        }

        int possibleGems = 1;

        for (int i=0; i<n; i++){
            dfs(i, adj, possibleGems, n);
        }
        printf("%d\n",possibleGems);
    }
}A
