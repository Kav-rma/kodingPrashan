#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] == s[right]){
                left++; right--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int rm_ch = 0;
        int i = 0; int j = s.length()-1;

        while(i<j){
            if (rm_ch > 1) return false;
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};