#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int read=0;

        int sum=0;
        while(read<n){
            sum+=(read+1)*(26-(s[read]-'a'));
            read++;
        }
        return sum;
    }
};