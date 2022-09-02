/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 198490
 * Submitted at:  2022-01-19 12:28:58
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    548
 * Problem Name:  Magic binary dot card
 */

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int lli;

int main() {
    lli S, E;

    while (scanf("%lld %lld", &S, &E) != EOF){

        lli mask = 1;

        while(true){
            if(S>=E) break;

            if((mask & S)==0){
                S = S|mask;
            } else {
                mask = mask<<1;
            }
        }
        printf("%lld\n", S);
    }
}
