#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxFreq(const vector<int>& freq){
        return *max_element(freq.begin(), freq.end());
    }

    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;

        vector<int> freq(26,0);
        
        int ans=0;

        while(right < s.length()){
            freq[s[right]-'A']++;

            int winlen = right - left + 1;
            int replace = winlen - maxFreq(freq);

            if(replace > k){
                freq[s[left]-'A']--;
                left ++;
            }else{
                ans = max(ans, winlen);
            }
            right++;
        }
        return ans;
    }
};