/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202228
 * Submitted at:  2022-02-24 01:19:07
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    373
 * Problem Name:  Falling Pineapple From Sky
 */

#include <queue>
#include <cstdio>
#include <map>

using namespace std;

struct City {
    int x, y, w;
    City(int aX, int aY, int aW){
        x=aX, y=aY; w=aW;
    }
    bool operator<(const City &c) const{
        return w>c.w;
    }
};
class Kruskal{
private:
    int *rank;
    int *parent;
public:
    Kruskal(int n){
        this -> rank = new int [n+1];
        this -> parent = new int [n+1];

        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    int find(int i){
        if(parent[i] != i){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union (int a, int b){
        int pA = find(a);
        int pB = find(b);

        if(rank[pA] > rank[pB]){
            parent[pB] = pA;
        }
        else if(rank[pB] > rank[pA]){
            parent[pA] = pB;

        }
        else {
            rank[pA] += 1;
            parent[pB] = pA;
        }
    }
};
int main() {
    int P, R;

    while(scanf("%d %d", &P, &R)) {
        if(P==0 && R==0) break;
        priority_queue<City> Q;
        priority_queue<int, vector<int>, greater<int>> Res;
        int distance=0;

        int a, b, w;
        for(int i=0; i<R; i++){
            scanf(" %d %d %d", &a, &b, &w);
            Q.push(City(a, b, w));
        }

        Kruskal kruskal(P);
        int edges=0;
        while(!Q.empty()) {
            City c = Q.top(); Q.pop();

            if(kruskal.find(c.x) != kruskal.find(c.y)){
                kruskal.Union(c.x, c.y);
                distance += c.w; edges++;
            } else {
                Res.push(c.w);
            }
        }

        if(P - 1 == edges) {
            printf("Min cost: %d\n", distance);

            if(!Res.empty()) {
                while (!Res.empty()) {
                    printf("%d", Res.top());
                    Res.pop();
                    if(Res.size()!=0) printf(" ");
                }
            }
            printf("\n");
        }
        else {
            printf("\\(^o^)/ pray to god\n");
        }
    }
    return 0;
}
//3 7
//1 2 19
//2 3 11
//3 1 7
//1 3 5
//2 3 89
//3 1 91
//1 2 32
//
//5 7
//1 2 5
//2 3 7
//2 4 8
//4 5 11
//3 5 10
//1 5 6
//4 2 12
//
//0
