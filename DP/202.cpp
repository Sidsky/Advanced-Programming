/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 202983
 * Submitted at:  2022-03-02 07:25:42
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    202
 * Problem Name:  Maximum Sum (UVa 108)
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int maxContigousSum(int *array, int n, int mSoFar, int max){
    mSoFar += array[n];
    if(mSoFar > max){
        max=mSoFar;
    }

    if(n==0) {
        return max;
    }
    if(mSoFar<0) mSoFar=0;

    return maxContigousSum(array, n-1, mSoFar, max);
}
int main() {
    int n;
    scanf("%d", &n);
    int array[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int number;
            scanf(" %d", &number);
            array[i][j]=number;
        }
    }

    int middle[n];
    int maximumSum=-1;

    for(int i=0; i<n; i++) {

        memset(middle, 0, sizeof (middle));

        for(int j=i; j<n; j++){

            for(int k=0; k<n; k++){
                middle[k]+=array[k][j];
            }

            int maxSum = maxContigousSum(middle, n-1, 0, 0);
            maximumSum = max(maximumSum, maxSum);
        }
    }

    printf("%d\n", maximumSum);
    return 0;
}
//4
//0 -2 -7 0
//9 2 -6 2
//-4 1 -4 1
//-1 8  0 2
