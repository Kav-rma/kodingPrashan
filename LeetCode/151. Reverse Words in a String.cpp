#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();

        // Step 1: Reverse the whole string
        reverse(s.begin(), s.end());

        // Step 2: Reverse each word
        int start = 0;

        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        // Step 3: Remove extra spaces in-place
        int read = 0;
        int write = 0;

        while (read < n) {

            // Skip all spaces
            while (read < n && s[read] == ' ')
                read++;

            // Copy one word
            while (read < n && s[read] != ' ')
                s[write++] = s[read++];

            // Skip spaces after the word
            while (read < n && s[read] == ' ')
                read++;

            // Add one space only if another word exists
            if (read < n)
                s[write++] = ' ';
        }

        // Resize string to remove leftover characters
        s.resize(write);

        return s;
    }
};