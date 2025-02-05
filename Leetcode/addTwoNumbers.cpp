/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <iostream>
#include <cmath>

using namespace std; 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1 = vectorFromListNode(l1);
        vector<int> num2 = vectorFromListNode(l2);
        int sum1 = sumVector(num1);
        int sum2 = sumVector(num2);
        int sum = sum1 + sum2;
        vector<int> nums = intToVector(sum);
        cout << nums[0];
        
        ListNode* x = nullptr;
        ListNode* last;
    
        for(int i; i < nums.size(); i++){
            ListNode* tmp = new ListNode(nums[i]);
            

            if(x == nullptr){
                x = tmp;  
                last = tmp;
            }
            else
                last -> next = tmp;
                last = tmp;
        }
        return x;
    }

    vector<int> vectorFromListNode(ListNode* l1){
        vector<int> num1 {};
        bool flag = true;
        while(flag == true){
            int a = l1->val;
            if (l1->next == nullptr){
                num1.insert(num1.end(), a);
                flag = false;
            }
            else{
                num1.insert(num1.end(), a);
                l1 = l1->next;
            }
        }
        return num1;
    }

    int sumVector(vector<int> num1) {
        int sum1 = 0;
        for(int i = 0; i < num1.size(); i++){
            sum1 += num1[i]*pow(10, i);           
        }
        return sum1;
    }

    vector<int> intToVector(int sum){
        vector<int> nums;

        if (sum == 0){
            nums.insert(nums.end(), sum);
            return nums;    
        }

        else{
            int size = trunc(log10(sum)) + 1;
            for(int i = 0; i < size; i++){
                int x = sum%10;
                sum = sum/10;
                nums.insert(nums.end(), x);
            }

            return nums;    
        }

        
    }


};