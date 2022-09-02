/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 201208
 * Submitted at:  2022-02-11 20:00:33
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    507
 * Problem Name:  Zodiac Fever
 */

#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
#include<map>

using namespace std;

int getNextLoc (int p, int ring, unordered_map<int, pair<char, int>> &traps){

    if(traps.find(p)!=traps.end()) {

        pair<int, int> trap = traps.at(p);

        if(trap.first=='+') {
            ring += trap.second;
        } else if (trap.first=='-'){
            ring -= trap.second;
        } else if (trap.first=='*'){
            ring *= trap.second;
        } else {
            ring = trap.second;
        }

        if (ring>12) {
            ring%=12;
        }
        while(ring<=0){
            ring+=12;
        }
    }
    return ring;
}
void ZodiacFever (const vector< vector <pair<int, int> > > &maze, unordered_map<int, pair<char, int>> &traps, int &S, int &I, int &E, int &O){

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > Q;

    map<pair<int, int>, int> visited;
    map<pair<int, int>, int> distance;

    Q.push(make_tuple(0, S, I));

    visited.insert({make_pair(S, I), 1});
    distance.insert({make_pair(S, I), 0});

    while(!Q.empty()) {

        tuple<int, int, int> toptuple = Q.top(); Q.pop();
        pair<int, int> top = make_pair(get<1>(toptuple), get<2>(toptuple));

        int loc = top.first;
        int ring = top.second;

        for (int i=0; i<maze[loc].size(); i++){

            int nextLoc = maze[loc][i].first;
            int nextRing = getNextLoc(maze[loc][i].first, ring, traps);

            pair<int, int> nextLocRing= make_pair(nextLoc, nextRing);

            if (visited.find(nextLocRing) == visited.end()) {
                int d = distance.at(top) + maze[loc][i].second;
                Q.push(make_tuple(d, nextLoc, nextRing));
                visited.insert({nextLocRing, 1});
                distance.insert({nextLocRing, d});

            } else if (distance.at(nextLocRing) > distance.at(top) + maze[loc][i].second) {
                Q.push(make_tuple(distance.at(top) + maze[loc][i].second, nextLoc, nextRing));
                distance.find(nextLocRing) -> second = distance.at(top) + maze[loc][i].second;
            }
        }
    }
    if(distance.find({E, O}) != distance.end())
        printf("%d\n", distance.at({E,O}));
    else
        printf("Pray!\n");
}

int main() {
    int R, C, T, S, I, E, O;
    vector< vector< pair<int, int> > > maze (1001) ;

    while(scanf("%d %d %d %d %d %d %d", &R, &C, &T, &S, &I, &E, &O) != EOF){
        for (int i=0; i<1001; i++){
            maze[i].clear();
        }

        while(C--){
            int x, y, w;
            scanf(" %d %d %d", &x, &y, &w);
            maze[x].push_back(make_pair(y, w));
            maze[y].push_back(make_pair(x, w));
        }

        unordered_map<int, pair<char, int> > traps;

        while(T--){
            int x; char c; int n;
            scanf(" %d %c %d", &x, &c, &n);
            traps.insert({x, make_pair(c, n)});
        }
        ZodiacFever(maze, traps, S, I, E, O);
    }
    return 0;
}
//3 3 1 1 7 3 8
//1 2 1
//2 3 1
//1 3 1
//2 + 1

//5 8 3 1 0 4 11
//1 5 3
//1 2 5
//1 4 4
//2 5 2
//2 3 1
//5 3 1
//5 4 7
//4 3 9
//5 + 2
//2 + 7
//3 + 2
