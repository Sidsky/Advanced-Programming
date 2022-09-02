/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202211
 * Submitted at:  2022-02-24 00:22:07
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    168
 * Problem Name:  Networking
 */

#include <queue>
#include <cstdio>
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
        this -> rank = new int [n+2];
        this -> parent = new int [n+2];

        for(int i=1; i<=n; i++){
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

    while(scanf("%d", &P) && P) {
        scanf(" %d", &R);

        priority_queue<City> Q;
        int network=0;

        int a, b, w;
        for(int i=0; i<R; i++){
            scanf(" %d %d %d", &a, &b, &w);
            Q.push(City(a, b, w));
        }
        while(getchar()!='\n');
        while(getchar()!='\n');

        Kruskal kruskal(P);

        while(!Q.empty()) {
            City c = Q.top(); Q.pop();

            if(kruskal.find(c.x) != kruskal.find(c.y)){
                kruskal.Union(c.x, c.y);
                network += c.w;
            }
        }
        printf("%d\n", network);
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
