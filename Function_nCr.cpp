#include<iostream>
using namespace std;

int comb(int n, int r){
    int num_1=1, num_2=1, num_3=1;
    int nCr;

    for(int i=1; i<=n; i++){
        num_1 *= i;
    }
    for(int i=1; i<=r; i++){
        num_2 *= i;
    }
    for(int i=1; i<=(n-r); i++){
        num_3 *= i;
    }

    nCr = ((num_1/num_2)/ num_3);

    return nCr;
}
int main(){
    int a,b;

    cout<<"Enter n: "; cin>>a;
    cout<<"\nEnter r: "; cin>>b;
    comb(a,b);
    cout<<"\nnCr = "<<comb(a,b);

    return 0;
}