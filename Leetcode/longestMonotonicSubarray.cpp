/*
You are given an array of integers nums. Return the length of the longest 
subarray
 of nums which is either 
strictly increasing
 or 
strictly decreasing
.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int longestMonotonicSubarray(vector<int>& nums) {
            vector<int> num = {1};
            int max = 0;
            int j = 1;

            for(int i = 0; i < nums.size()-1; i ++){
                if(i == nums.size() - 2){
                    if(nums[i] < nums[i+1]){
                        j++;
                        num.insert(num.begin(), j);
                    }
                    else{
                        num.insert(num.begin(), j);
                    }
                }
                else if (nums[i] < nums[i+1]){
                    j++;
                }
                else{
                num.insert(num.begin(), j);
                j = 1;  
                }
            }

            j = 1;

            for(int i = 0; i < nums.size()-1; i ++){
                if(i == nums.size() - 2){
                    if(nums[i] > nums[i+1]){
                        j++;
                        num.insert(num.begin(), j);
                    }
                    else{
                        num.insert(num.begin(), j);
                    }
                }
                else if (nums[i] > nums[i+1]){
                    j++;
                }
                else{
                num.insert(num.begin(), j);
                j = 1;  
                }
            }
    
            for(int i = 0; i < num.size(); i++){
                
                if (num[i] > max){
                    max = num[i];
                }
            }

        return max;
        }
};
