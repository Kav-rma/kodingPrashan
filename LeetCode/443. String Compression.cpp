#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& v) {
        // two pointer
        int read=0;
        int write=0;

        int n = v.size();

        while(read<n){
            int count=0;
            char curent = v[read];
            
            while(read<n && v[read] == curent){
                read++;
                count++;
            }

            v[write++] = curent;

            if(count > 1){
                string s = to_string(count);
                for(char c : s) v[write++] = c;
            }
        }

        return write;
    }
};