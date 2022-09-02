/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 210323
 * Submitted at:  2022-04-13 11:40:59
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    508
 * Problem Name:  Gene Matching
 */

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

#define MAX_N 100010

char T[MAX_N], P[MAX_N];
int RA[MAX_N], tempRA[MAX_N], SA[MAX_N], tempSA[MAX_N], c[MAX_N], n, m;

void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof(c));

    for(int i=0; i<n; i++) { // This loop counts the frequency of each integer rank
        int ix;

        if (i + k < n) ix = RA[i+k];
        else ix = 0;

        c[ix]++;
    }

    for(i=sum=0; i<maxi; i++) { // count sort routine
        int t = c[i];
        c[i]=sum;
        sum+=t;
    }

    for(int i=0; i<n; i++) {
        int ix;

        if (SA[i] + k < n){
            ix = RA[SA[i]+k];
        } else {
            ix = 0;
        }
        ix = c[ix]++;
        tempSA[ix] = SA[i];
    }

    for(int i = 0; i < n; i++) {
        SA[i] = tempSA[i];
    }
}
void constructSA() {
    int i, k, r;

    for(i=0; i<n; i++) {
        RA[i]=T[i];
        SA[i]=i;
    }

    for(k=1; k<n; k<<=1) {
        countingSort(k);
        countingSort(0);

        tempRA[SA[0]] = r = 0;

        for (i = 1; i < n; i++) {
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        }

        for (i = 0; i < n; i++) {
            RA[i] = tempRA[i];
        }

        if (RA[SA[n-1]] == n-1) break;
    }
}
int geneMatching() {
    int lower, upper, l=0, h = n-1, mid = l;

    while (l < h) {
        mid = (l + h) / 2;
        int r = strncmp(T + SA[mid], P, m);

        if (r >= 0) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    if (strncmp(T + SA[l], P, m) != 0) return 0;

    lower = l;
    l = 0; h = n - 1; mid = l;

    while (l < h) {
        mid = (l + h) / 2;
        int r = strncmp(T + SA[mid], P, m);

        if (r > 0) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }

    if(strncmp(T + SA[h], P, m) != 0) h--;

    upper = h;

    return upper-lower+1;
}
int main(){
    int N, count=1; cin>>N;
    getchar(); getchar();

    while(N--) {
        memset(T, '\0', sizeof (T));

        n = strlen(gets(T));
        T[n++] = '$';

        constructSA();

        printf("Case #%d\n", count++);

        int nsub; cin>>nsub; getchar();

        while(nsub--) {
            memset(P, '\0', sizeof (P));

            m = strlen(gets(P));
            cout<<geneMatching()<<endl;
        }
        getchar();
    }
}

//3
//
//ATCGTCATCGGATGCATT
//2
//AT
//CG
//
//AAAAA
//3
//A
//AA
//AAA
//
//CGCGCGCGCG
//2
//CG
//CCC
