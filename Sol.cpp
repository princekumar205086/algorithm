/*

A subarray is considered good if the XOR of its elements is odd and its length is even. Given an array arr of length n, return the number of good subarrays. 

Example 1:

Input:
n = 3
arr = [1, 2, 3]
Output: 2
Explanation: 
Good subarrays are [1,2], [2,3].
Example 2:

Input:
n = 5
arr = [4, 2, 3, 2, 1]
Output: 4
Explanation: 
Good subarrays are [4,2,3,2], [2,3], [3,2], [2,1].
Your Task:
You don't need to read input or print anything. Your task is to complete the function countoddSubarrays() which takes integer n and an array arr as input and returns the count of good subarrays. 

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 109

//cpp 5.4.0

class Solution {
  public:
    long long countoddSubarrays(int n, vector<int> &arr) {
        // code here
    }
};

test case 1:

For Input: 
3
1 2 3

Expected Output: 
2

test case 2:

For Input: 
2
7 6

It's Correct output is: 
1

test case 3:

For Input: 
8
2 4 7 3 6 9 9 9

It's Correct output is: 
9


super hint for optimization:

mandatory to use prefix xor
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countoddSubarrays(int n, vector<int> &arr) {
        long long count = 0;
        int prefix_xor = 0;
        unordered_map<int, int> xor_freq;
        xor_freq[0] = 1;
        
        for (int i = 0; i < n; i++) {
            prefix_xor ^= arr[i];
            
            if (prefix_xor % 2 != 0) {
                count += xor_freq[prefix_xor ^ 1];
            } else {
                count += xor_freq[prefix_xor];
            }
            
            xor_freq[prefix_xor]++;
        }
        
        return count;
    }
};
