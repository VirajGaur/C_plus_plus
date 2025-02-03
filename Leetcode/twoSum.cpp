/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1;
        int num2;
        vector<int> result;


        
        for(int i = 0; i < nums.size(); i ++){
            num1 = i;
            num2 = nums.size() - 1;
            
            for(int j = 0; j < nums.size(); j++){
                if (i == j){
                    break;
                }
                if(nums[i] + nums[j] == target){
                    num2 = j;
                    break; 
                }
            }

            if (nums[num1] + nums[num2] == target){
                cout<< nums[num1] << "\n" ;
                break;
            }

        }

        result.insert(result.begin(), num1);
        result.insert(result.begin(), num2);
        return result;    
    
    }
};