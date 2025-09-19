#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    bool ifFreqSame(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freqS1[26] = {0};
        for(int i=0; i<s1.length(); i++){
            freqS1[s1[i]-'a']++;
        }

        for(int i=0; i<s2.length(); i++){
            int windIdx =0; int idx = i;
            int freqWind[26]={0};

            while(windIdx<s1.length() && idx<s2.length()){
                freqWind[s2[idx]-'a']++;
                idx++; windIdx++;
            }
            
            if(ifFreqSame(freqS1,freqWind)){
                return true;
            }
        }
        return false;
    }
};