#include <bits/stdc++.h>
using namespace std;

/*
You are given a balanced bracket string s containing only the characters '(' and ')'.
Each pair of brackets contributes to the total score according to these rules:
A simple pair "()" has a score of 1.
If the string is formed by concatenating two balanced parts A and B, then the total score is:
score(A) + score(B).
If a balanced part A is wrapped inside a pair of brackets like "(A)", then its score becomes:
2 × score(A).
Your task is to compute the total score of the given balanced string s.
Example 1
Input: "()""
Output: 1
Explanation: The string "()" is a simple pair, so its score is 1.
*/
  //     (()())(())
int calculateScore(string str){
    int n = str.length();
    if(n<=0)return 0;
    stack<int>st;

    for(char c : str){
        if(c=='('){
            st.push(-1);
        }
        else{
                int sum = 0;
                while(!st.empty() && st.top()!=-1){
                    sum+=st.top();
                    st.pop();
                }
                st.pop();
                if(sum == 0){
                    sum = 1;
                }
                else{
                    sum = sum * 2;
                }
                st.push(sum);
            }
    }
    int s = 0;
    while(!st.empty()){
        s += st.top();
        st.pop();
    }
    return s;
}

int main(){
    string str = "((()())(()))";

    int score = calculateScore(str);

    cout<<score<<endl;
    return 0;
}