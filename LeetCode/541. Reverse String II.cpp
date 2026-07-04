#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int read=0;
        int mark=0;
        int n=s.length();

        while(read<n){
            int count=0;
            while(read<n && count!=2*k){
                read++;
                count++;
            }
            if(count < k){
                reverse(s.begin() + mark, s.end());
            }else{
                reverse(s.begin() + mark, s.begin() + mark + k);
            }
            count=0;
            mark = read;
        }
        return s;
    }
};