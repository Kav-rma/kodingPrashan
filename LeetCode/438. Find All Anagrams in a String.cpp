#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(p.length()>s.length()) return v;

        int freq[26] = {0};
        for(int i=0; i<p.length(); i++){
            freq[p[i]-'a']++;
        }

        int winfreq[26]={0};
        for(int i=0; i<p.length(); i++){
            winfreq[s[i]-'a']++;
        }
        if(isFreqSame(freq,winfreq)){
            v.push_back(0);
        }

        for(int i=0; i<s.length()-p.length(); i++){
            //remove left
            winfreq[s[i]-'a']--;

            //add right
            winfreq[s[i+p.length()]-'a']++;

            if(isFreqSame(freq,winfreq)){
                v.push_back(i+1);
            }
        }
        return v;
    }
};