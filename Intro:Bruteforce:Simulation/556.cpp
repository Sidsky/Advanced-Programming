/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 211913
 * Submitted at:  2022-04-22 09:04:41
 *
 * User ID:       878
 * Username:      55354954
 * Problem ID:    556
 * Problem Name:  Propositional Satisfiability
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <bitset>

using namespace std;

unordered_map<char, int> M;
stack<char> S;
unordered_map<char, int> :: iterator it;
int idx = 0;

void reset() {
    idx = 0;
    M.clear();
    while(!S.empty()) S.pop();
}

int precedence(char c) {
    if (c=='!'){
        return 3;
    }
    else if (c=='&'){
        return 2;
    }
    else if (c=='+'){
        return 1;
    }
    else
        return 0;
}

string convertToPostfix(string infix){
    string postfix;

    for(int i=0; i<infix.length(); i++){
        char l = infix[i];
        if (l>='a' && l<='z') {
            postfix += l;

            it = M.find(l);
            if(it==M.end()){
                M.insert({l, idx++});
            }

        } else if (l=='('){
            S.push(l);
        } else if (l==')'){
            while (S.top()!='('){
                postfix+=S.top(); S.pop();
            }
            S.pop();
        } else if (l!= ' '){
            while(!S.empty() && precedence(S.top()) > precedence(l)){
                postfix += S.top();S.pop();
            }
            S.push(l);
        }
    }
    while (!S.empty()){
        postfix+=S.top(); S.pop();
    }
    return postfix;
}
bool calculateExpression(string postfix, bitset<32> base){
    stack<bool> PS;
    for (int i=0; i<postfix.size(); i++){
        char l = postfix[i];
        if(l>='a' && l<='z'){
            PS.push(base[M.at(l)]);
        } else {

            if (l=='!'){
                bool A = PS.top(); PS.pop();
                PS.push(!A);
            } else {
                bool A = PS.top(); PS.pop();
                bool B = PS.top(); PS.pop();

                if(l=='+'){
                    PS.push(A || B);
                } else {
                    PS.push(A && B);
                }
            }
        }
    }
    bool f = PS.top();PS.pop();
    return f;
}

bool calculateAllExpressions(string postfix, int idx){

    for(int i=0; i< (1<<idx); i++){
        bitset<32> r(i);
        if(calculateExpression(postfix, r))
            return true;
    }
    return false;
}
int main() {
    string infix, postfix;

    while(getline(cin, infix)){
        reset();

        postfix = convertToPostfix(infix);
        string fPS = calculateAllExpressions(postfix, idx) ? "YES":"NO";
        cout<<fPS<<endl;
    }
    return 0;
}
//!p & !q + !r & (!s + !t)
