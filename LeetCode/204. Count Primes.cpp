#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mark(n,true);
        int count=0;
        for(int i = 2; i<n; i++){
            
            if(mark[i]!=0) count++;

            for(int j=i; j<n; j+=i){
                mark[j]=false;
            }

        }
        return count;
    }
};