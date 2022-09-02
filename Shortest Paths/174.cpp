/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 201880
 * Submitted at:  2022-02-20 19:50:32
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    174
 * Problem Name:  Minimum Transport Cost (UVa 523)
 */

#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int oo = 1e9;

struct Junction{
    int J, P;

    Junction(int aJ, int aP){
        J=aJ; P=aP;
    }
    bool operator<(const Junction &JT) const{
        return P>JT.P;
    }
};

void path(int s, int e, int *parents, vector<int> &route){
    while(s != e){
        path(e, parents[e], parents, route);
        break;
    }
    route.push_back(s);
}
void printPath(int s, int e, int *distance, int *parents){
    vector<int> route;
    printf("From %d to %d :\n", s, e);
    printf("Path: ");
    path(e, parents[e], parents, route);

    for(int i=0; i<route.size(); i++){
        printf("%d", route[i]);
        if(i+1!=route.size()){
            printf("-->");
        }
    }
    printf("\nTotal cost : %d\n", distance[e]);
}

int main() {

    int T;
    scanf("%d", &T);

    while(getchar() != '\n'); while(getchar() != '\n');

    while(T--){
        vector<int> nums;
        string f;
        getline(cin, f);
        stringstream sin(f);

        int num;
        while(sin>>num){
            nums.push_back(num);
        }
        int size = nums.size() + 1;

        int KMB[600][600];

        for(int i=0; i<nums.size(); i++){
            KMB[1][i+1]=nums[i];
        }

        for(int i=2; i<size; i++){
            for(int j=1; j<size; j++){
                int number; scanf(" %d", &number);
                KMB[i][j]=number;
            }
        }

        int tax[size];
        for(int i=1; i<size; i++){
            scanf(" %d", &tax[i]);
        }

        while(getchar() != '\n');

        string ss;bool flag=false;
        while(true) {
            getline(cin, ss);
            if(ss.length()==0)break;
            if(flag==true)
                printf("\n");
            flag=true;
            stringstream sin(ss);
            int s, e; sin>>s>>e;

            int distance[600];
            int parents[600];

            for(int i=0; i<size; i++) {
                distance[i] = oo;
                parents[i]=i;
            }

            priority_queue<Junction> Q;

            distance[s]=0;

            for(int i=1; i<size; i++){
                if(KMB[s][i]!=0 && KMB[s][i] != -1){
                    Q.push(Junction(i, KMB[s][i]));
                    distance[i]=KMB[s][i];
                    parents[i]=s;
                }
            }
            while(!Q.empty()) {
                Junction curr = Q.top(); Q.pop();
                for(int i=1; i<size; i++) {
                    if(KMB[curr.J][i] != 0 &&  KMB[curr.J][i] != -1 && distance[i] > distance[curr.J] + KMB[curr.J][i] + tax[curr.J]){
                        int d = distance[curr.J] + KMB[curr.J][i] +tax[curr.J];
                        Q.push(Junction(i,d));
                        distance[i]=d;
                        parents[i]=curr.J;
                    }
                }
            }
            printPath(s, e, distance, parents);
        }
        if(T){
            printf("\n");
        }
    }
}
//2
//
//0 3 22 -1 4
//3 0 5 -1 -1
//22 5 0 9 20
//-1 -1 9 0 4
//4 -1 20 4 0
//5 17 8 3 1
//1 3
//3 5
//2 4
//
//0 3 22 -1 4
//3 0 5 -1 -1
//22 5 0 9 20
//-1 -1 9 0 4
//4 -1 20 4 0
//5 17 8 3 1
//1 3
//3 5
//2 4
