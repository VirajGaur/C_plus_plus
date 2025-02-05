#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int i=-1, j=-1;

        for(int k = 0; k < s2.size(); k++){
            if(s2[k] != s1[k]){
                count ++;
                if (i == -1) {
                    i = k;
                } 
                
                else if (j == -1) {
                    j = k;
                }
            }
        }

        if (count == 0) {
            return true;
        } 
        else if (count == 2 && s1[i] == s2[j] && s1[j] == s2[i]) {
            return true;
        }
        return false;
    }
};