/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 204235
 * Submitted at:  2022-03-09 15:41:20
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    227
 * Problem Name:  Smart Customer
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    double unitPrice;
    int M;
    double memo [101];
    int C=1;

    while (cin>>unitPrice>>M){

        for(int i=0; i<101; i++) memo[i]= 1e9;

        memo[1]=unitPrice;

        double P; int U;

        while(M--){
            cin>>U>>P;
            memo[U]=min(memo[U], P);
        }
        while (getchar()!='\n');

        string line; getline(cin, line);

        stringstream  sin(line);
        int n; vector<int> queries;

        while(sin>>n) queries.push_back(n);

        for(int i=1; i<=100; i++){
            for(int j=i-1; j>=(i/2); j--){
                memo[i] = min(memo[i], memo[j]+memo[i-j]);
            }
        }
        printf("Case %d:\n", C++);

        for(int i=0; i<queries.size(); i++){
            printf("Buy %d for $%.2f\n", queries[i], memo[queries[i]]);
        }
    }
}
//22.00 2
//2 22.00
//4 60.00
//2 4
//25.00 2
//2 48.00
//2 46.00
//2
//22.00 2
//2 22.00
//4 40.00
//1 2 3 4
