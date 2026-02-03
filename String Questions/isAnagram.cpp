#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n!=m)return false;
        // using hashmap 
        /*
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        for(char c : s)mp1[c]++;
        for(char c : t)mp2[c]++;
        
        for(char c : s){
            if(mp1[c]!=mp2[c])return false;
        }
        return true;
        */

        // using Array data Structure
        vector<int>arr(26,0);
        for(int i=0; i<n; i++){
            arr[s[i]-'a']++;
        }
        for(int i=0; i<n; i++){
            arr[t[i]-'a']--;
        }
        for(int i : arr){
            if(i!=0)return false;
        }
        return true;
        
    }

int main(){
    string s = "anagram", t = "nagaram";
    cout<<isAnagram(s,t);

    return 0;
}