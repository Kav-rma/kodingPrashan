#include<iostream>
using namespace std;

class Solution {
public:

    pair<int,int> expand(const string& s, int left, int right){

        int count;
        int size = s.length();

        while(left>=0 && right<size && s[left] == s[right]){
            left--;
            right++;
        }

        count = right - left - 1;

        return {left+1, count};
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 0;
        pair<int, int> p1;
        int str;

        for(int i=0; i<n; i++){
            p1 = expand(s, i, i);
            if(p1.second > max_len){
                max_len = p1.second;
                str = p1.first;
            }
            if(i+1 < n && s[i] == s[i+1]){
                p1 = expand(s,i, i+1);
                if(p1.second > max_len){
                    max_len = p1.second;
                    str = p1.first;
                }
            }        }

        return s.substr(str, max_len);
    }
};