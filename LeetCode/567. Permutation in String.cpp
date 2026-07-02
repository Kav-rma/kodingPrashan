#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length()) return false;

        //We get the frequency of s1 string.
        int freq[26]={0};
        for(int i=0; i<s1.length(); i++){
            freq[s1[i]-'a']++;
        }

        //frequency of first window of s2.
        int winfreq[26] = {0};
        for(int j=0; j<s1.length(); j++){
            winfreq[s2[j]-'a']++;
        }
        if(isFreqSame(freq,winfreq)) return true;

        //now we are shifting the window towards right.
        for(int i=0; i<s2.length()-s1.length(); i++){
            //remove left
            winfreq[s2[i]-'a']--;
            //add right
            winfreq[s2[i+s1.length()]-'a']++;
            if(isFreqSame(freq,winfreq)) return true;
        }
        return false;
    }
};