/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 211183
 * Submitted at:  2022-04-18 22:15:03
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    280
 * Problem Name:  Maximum sum(II)
 */

#include <cstdio>
#include <vector>

using namespace std;

#define MIN -2e9

int prefixSum[50001];

void computePrefix(vector<int> &vec, int n, int sum, int curMax) {
    for(int i=0; i<n; i++) {
        sum += vec[i];
        if (sum > curMax){
            curMax = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
        prefixSum[i+1]=curMax;
    }
}
int main() {
    int T;
    scanf("%d", &T); getchar();

    while (T--) {
        int n; scanf("%d", &n);
        vector<int> vec;
        int sum=0;
        int curMax = MIN;

        for(int i=0; i<n; i++){
            int num;
            scanf("%d", &num);
            vec.push_back(num);
        }

        computePrefix(vec, n, sum, curMax);

        getchar();
        int right = MIN;
        sum = 0;
        int maxSumTwo = MIN;

        for(int i=vec.size()-1; i > 1; i--){
            sum += vec[i];

            if (sum > right) {
                right = sum;
            }
            maxSumTwo = max(maxSumTwo, right + prefixSum[i]);
            if (sum < 0) {
                sum = 0;
            }
        }
        printf("%d\n", maxSumTwo);
    }
    return 0;
}
//2
//
//10
//1 -1 2 2 3 -3 4 -4 5 -5
//
//10
//1 -1 2 2 3 -3 4 -4 5 -5
