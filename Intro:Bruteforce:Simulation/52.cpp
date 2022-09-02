/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 199571
 * Submitted at:  2022-01-27 08:30:18
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    52
 * Problem Name:  Hanging Nests
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Nest{
    int spots;
    Nest *left;
    Nest *right;
};
class Hanger{

private:
    Nest* root;
    int IF=-1;
    int spots=0;
    int nests[5001]={0};

    Nest *addInHanger(Nest *root, int spots){
        if (root == NULL){
            root = new Nest;
            root -> spots = spots;
            root ->left = NULL;
            root -> right = NULL;
        }
        else if (spots < root->spots){
            root -> left = addInHanger(root->left, spots);
        } else {
            root -> right = addInHanger(root->right, spots);
        }
        return root;
    }

public:
    Hanger(){
        root=NULL;
    }
    void addNest(int &spots) {
        if (root != NULL){
            addInHanger(root, spots);
        } else {
            root = new Nest;
            root -> spots = spots;
            root -> left = NULL;
            root -> right = NULL;
        }
    }
    int getHeight(Nest *root){
        if (root == NULL){
            return -1;
        }
        int l, r;
        l = 1+getHeight(root->left);
        r = 1+getHeight(root->right);

        nests[root->spots] = abs(l-r);
        return max(l, r);
    }
    int findMostUnabalancedNest(unordered_map<int, int> &order){
        getHeight(root);

        for(int i=1; i<=order.size(); i++){
            int spot= order.find(i)->second;
            int factor = nests[spot];

            if(factor>IF){
                IF=factor;
                spots=spot;
            }
        }

        return spots;
    }
};

int main() {
    int T; scanf("%d", &T);

    for(int i=1; i<=T; i++){
        int N; scanf("%d", &N);
        Hanger *hanger = new Hanger;
        unordered_map<int, int> order;
        int place=1;

        while (N--) {
            int S; scanf("%d", &S);
            order.insert({place++, S});
            hanger -> addNest(S);
        }
        printf("Flock #%d: %d\n\n", i, hanger -> findMostUnabalancedNest(order));
        delete hanger;
    }
}
