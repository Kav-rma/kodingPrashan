#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for(int i=0; i<n; i++){
            if((i+1)%3==0 && (i+1)%5==0){
                answer.push_back("FizzBuzz");
            }
            else if((i+1)%3 == 0){
                answer.push_back("Fizz");
            }
            else if((i+1)%5 == 0){
                answer.push_back("Buzz");
            }
            else{
                answer.push_back(to_string(i+1));
            }
        }

        return answer;
    }
};