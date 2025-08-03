#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    bool isAlphaNumeric(char ch){
            if((tolower(ch) >= 'a' && tolower(ch) <= 'z') || (ch >= '0' && ch <='9')) return true;
            else return false;
    }
    bool isPalindrome(string s) {
        int str=0, end=s.length()-1;
        
        while(str<end){
            if(!isAlphaNumeric(s[str])){
                str++;
                continue;
            } 
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[str])!=tolower(s[end])){
                return false;
            }
            str++,end--;
        }
        return true;
    }
};