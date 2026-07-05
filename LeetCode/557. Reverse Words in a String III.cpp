#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int read=0;
        int mark=0;
        int n = s.length();

        while(read<n){
            while(read<n && s[read] != ' ') read++;
            reverse(s.begin()+mark, s.begin()+read);
            read++;
            mark = read;
        }
        return s;
    }
};