/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202289
 * Submitted at:  2022-02-24 21:26:34
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    207
 * Problem Name:  Minimum Effort
 */

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

const int oo=1e9;

struct Block {
    int x, w;
    Block(int aX, int aW){
        x=aX; w=aW;
    }
    bool operator<(const Block &b)const{
        return w>b.w;
    }
};
void getPath(vector<int> &paths, int &des, int *parents){
    if(parents[des]!=des){
        getPath(paths, parents[des], parents );
    }
    paths.push_back(des);
}
int Dijktras(vector< vector<Block > > &School, int N, int src, int des, vector<int> &path) {

    int dis[N+1];
    int parent[N+1];

    for(int i=0; i<N; i++) {
        dis[i]=oo;
        parent[i]=i;
    }

    priority_queue<Block> Q;

    for(int i=0; i<School[src].size(); i++){
        int next = School[src][i].x;
        int weight = School[src][i].w;
        Q.push(Block(next, weight));
        dis[next]=weight;
        parent[next]=src;
    }

    dis[src]=0;

    while(!Q.empty()) {
        Block cT = Q.top(); Q.pop();
        int curr = cT.x;
        int cost = cT.w;

        if(curr == des) {
            dis[des]= min (dis[des], cost);
            break;
        }

        for(int i=0; i<School[curr].size(); i++) {
            int next = School[curr][i].x;
            int nextCost = School[curr][i].w;

            if(dis[next] > cost + nextCost){
                dis[next] = cost + nextCost;
                Q.push(Block(next, cost+nextCost));
                parent[next]=curr;
            }
        }
    }
    getPath(path, des, parent);
    return dis[des];
}

int main() {
    int N;

    while(~scanf("%d", &N)){
        unordered_map<string, int> loc;
        unordered_map<int, string> iLoc;

        vector<vector<Block> > School (N+1);
        while(getchar()!='\n');
        for(int i=0; i<N; i++) {
            string s;
            getline(cin, s);
            loc.insert({s, i});
            iLoc.insert({i, s});
        }
        int P;
        scanf("%d", &P);
        while(getchar()!='\n');
        while(P--){
            string line; getline (cin, line);
            bool one=false, second=false;
            string p1="", p2="", p3="";
            bool empty=false;

            for(int i=0; i<line.length(); i++) {
                if(!one){
                    if(line[i]!=':'){
                        p1+=line[i];
                    } else {
                        one = true;
                    }
                }
                else if (!second){
                    p2 += line[i];
                    if(p2==" " && !empty){
                        empty=true;
                        if(loc.find("")!=loc.end()) {
                            second= true;
                            p2="";
                        }
                    }
                    if(!second && loc.find(p2)!=loc.end()){
                        second= true;
                    }
                } else {
                    p3+=line[i];
                }
            }
            stringstream sin(p3);
            int d;
            vector<int> weights;

            while(sin>>d){
                weights.push_back(d);
            }
            int x = loc.at(p1);
            int y = loc.at(p2);

            School[x].push_back(Block(y, weights[0]));

            if(weights.size()>1){
                School[y].push_back(Block(x, weights[1]));
            }
        }

        vector<int> paths;

        int src = loc.find("office")->second;
        int des = loc.find("hall")->second;
        int ans=0;

        ans+=Dijktras(School, N, src, des, paths);
        paths.pop_back();
        ans+=Dijktras(School, N, des, src, paths);

        printf("%d\n", ans);
        for(int i=0; i<paths.size(); i++) {
            cout<<iLoc.at(paths[i]);
            if(i+1 != paths.size()){
                cout<<" -> ";
            }
        }
        printf("\n\n");
    }
    return 0;
}
