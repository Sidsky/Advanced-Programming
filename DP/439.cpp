/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 208738
 * Submitted at:  2022-04-06 13:22:19
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    439
 * Problem Name:  String Partition
 */

#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX 2147483647

using namespace std;

int main(){
    int T; cin>>T;
    string s;

    while(T--) {
        cin>>s;
        long long DP[s.size()+1], mask, num;
        bool overflow;

        memset(DP, 0, sizeof (DP));

        for (int i = s.size(); i >= 0; i--) {
            overflow = false; mask = 1; num = 0;

            for (int j = i-1; j >= 0 && !overflow; j--) {
                num += (mask * (s[j] - '0')); mask *= 10 ;
                overflow = num <= MAX ? false : true;

                if(!overflow)
                    DP[j]= max(DP[j], num + DP[i]);
            }
        }
        cout<<DP[0]<<endl;
    }
}
//7
//1234554321
//5432112345
//000
//121212121212
//2147483648
//11111111111111111111111111111111111111111111111111111
//740948824551711527614232216857618927954312
