/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 211612
 * Submitted at:  2022-04-21 06:26:35
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    617
 * Problem Name:  Candy Matching
 */

#include <iostream>

using namespace std;

int main() {
    string candy;

    while(cin>>candy) {
        string mod; int pairs=0;
        int i=1;

        while(i < candy.length()) {
            for(; i<candy.length(); i++){
                if (candy[i] == candy[i - 1]) {
                    candy.erase(i-1, 2);
                    pairs++; i=0;
                }
            }
            if (candy.length()>1 && candy[0] == candy[candy.length()-1]){
                candy.erase(0,1);
                candy.erase(candy.length()-1, 1);
                pairs++;
            }
            else if (candy.length()>=3){
                candy.erase(0, 3);
                pairs++;
            } else if (candy.length()==2){
                break;
            }
            i=1;
        }
        cout<<pairs<<endl;
    }
    return 0;
}
//BBYBYBYY
