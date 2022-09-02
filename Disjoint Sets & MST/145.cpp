/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202200
 * Submitted at:  2022-02-23 23:18:09
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    145
 * Problem Name:  Arctic Network (UVa 10369)
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

struct Outpost{
    int x, y;
    double w;
    Outpost(int aX, int aY, double aW){
        x=aX; y=aY; w=aW;
    }

    bool operator<(const Outpost&o)const{
        return w>o.w;
    }
};
struct Coordinates{
    int x, y;
    Coordinates(int aX, int aY){
        x=aX; y=aY;
    }
};
class Kruskal{
private:
    int *rank;
    int *parent;

public:
    Kruskal(int n) {
        this->rank = new int[n+1];
        this->parent = new int[n+1];

        for(int i=0; i<n; i++){
            rank[i]=1;
            parent[i]=i;
        }
    }

    int find(int i){
        if(parent[i]!=i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    int Union(int a, int b){
        int parentA = find(a);
        int parentB = find(b);

        if(rank[parentA] > rank[parentB]){
            parent[parentB] = parentA;
        } else if (rank[parentB]>rank[parentA]){
            parent[parentA] = parentB;
        } else {
            rank[parentA] += 1;
            parent[parentB] = parentA;
        }
    }
};
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int S, P;
        vector<Coordinates> CO;

        scanf("%d %d", &S, &P);

        int x, y;
        for(int i=0; i<P; i++){
            scanf(" %d %d", &x, &y);
            CO.push_back(Coordinates(x, y));
        }

        priority_queue<Outpost> Q;

        for(int i=0; i<CO.size(); i++){
            for(int j=i+1; j<CO.size(); j++) {
                double d = sqrt( pow(CO[i].x - CO[j].x, 2) + pow(CO[i].y - CO[j].y, 2));
                Q.push(Outpost(i, j, d));
            }
        }
        Kruskal kruskal(P);
        vector<double> MST;

        while(!Q.empty()){
            Outpost O = Q.top(); Q.pop();

            if(kruskal.find(O.x) != kruskal.find(O.y)){
                kruskal.Union(O.x, O.y);
                MST.push_back(O.w);
            }
        }
        printf("%.2f\n", MST[MST.size() - 1 - (S - 1)]);
    }
}
//1
//2 4
//0 100
//0 300
//0 600
//150 750
