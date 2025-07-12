#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
        long binaryForm = n;
        double ans=1.00;

        if(n==0) return 1.00;
        if(x==0) return 0.00;
        if(x==1) return 1.00;
        if(x==-1 && n%2==0) return 1.00; 
        if(x==-1 && n%2!=0) return -1.00; 
        if(n<0){
            binaryForm = -binaryForm;
            x = 1/x;
        }
        
        while(binaryForm>0){
            if(binaryForm % 2 == 1){
                ans *= x;
            }
            x *= x;
            binaryForm /= 2;
        }
        return ans;
    }
};

