#include<iostream>
using namespace std;

class Solution {
public:
    int digitProd(int x){
        int ans=1;

        while(x > 0){
            ans *= (x%10);
            x /= 10;
        }

        return ans;
    }

    int smallestNumber(int n, int t) {

        while(true){
            int prod = digitProd(n);

            if(prod % t == 0) return n;
            n++;
        }
        
    }
};