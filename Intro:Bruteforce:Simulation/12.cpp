/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 198330
 * Submitted at:  2022-01-12 19:34:00
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    12
 * Problem Name:  Yodaness Level
 */

//
//  main.cpp
//  Yodaness Level
//
//  Created by Siddharth Mehrotra on 12/1/2022.


//  Idea- Count the number of inversions using merge sort

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<string, int> si;

int yodanessLevel(int yoda[]){
    int level=0;

    return level;
}

int merge(int yoda[], int array[], int const left, int const mid, int const right){
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    
    while ( (i <= mid - 1) && (j <= right)){
        if (yoda[i] < yoda[j]) {
            array[k++] = yoda[i++];
        } else {
            array[k++] = yoda[j++];
            inv_count += mid - i;
        }
    }
    
    while (i <= mid-1){
        array[k++] = yoda[i++];
    }
    while (j <= right){
        array[k++] = yoda[j++];
    }
    
    for (int i=left; i<=right; i++){
        yoda[i] = array[i];
    }
    return inv_count;

}

int mergeSort(int yoda[], int array[], int left, int right){
    int mid, invcount=0;

    if (right > left){

        mid = (right+left) / 2;
        invcount += mergeSort(yoda, array, left, mid);
        invcount += mergeSort(yoda, array, mid + 1, right);
        invcount += merge(yoda, array, left, mid + 1, right);
    }
    return invcount;
}

int yodanessLevel(int yoda[], int length){
    int array[length];

    return mergeSort(yoda, array, 0, length-1);;
}
int main() {
    int T; cin>>T;

    while (T--){
        int n; cin>>n;
        si sentence;

        string *yodaness = new string[n];

        for(int i=0; i<n; i++){
            string word; cin>>word;
            yodaness[i] = word;
        }

        for (int i=0; i<n; i++){
            string word; cin>>word;
            sentence.insert({word, i});
        }
        
        int *yoda = new int[n];

        for (int i=0; i<n; i++){
            yoda[i] = sentence.find(yodaness[i]) -> second;
        }
        cout<<yodanessLevel(yoda, n)<<endl;
    }
    return 0;
}
