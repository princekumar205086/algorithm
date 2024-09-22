/*

Minimize the number
Accuracy: 0.0%Submissions: 0Points: 25
Given an array arr[]  of positive integers having size  n. Find the minimum positive number x such that  x%arr[i] is same (not neccesarily equal to x) for all arr[i] (1 ≤ i ≤ n).

Example 1:

Input:
n = 5
arr = [7, 10, 4, 3, 15]
Output: 1
Explanation: 
We can easily observe that
1 % 7 == 1
1 % 10 == 1
1 % 4 == 1
1 % 3 == 1
1 % 15 == 1
Hence, 1 is the smallest positive integer such that 1 % a[i] for each valid i is same.
Example 2:

Input:
n = 2
k = 1
arr = [2, 2]
Output: 1
Explanation: 
1 % 2 == 1
1 % 2 == 1
Again, 1 is the smallest number such that modulo is same for all elements in the array.Hence, 1 is the smallest positive integer such that 1 % a[i] for each valid i is same.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minMod() which takes the array arr[] and n as input and return the minimum possible value such that it satifies the given condition. 

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 15


class Solution {
  public:
    int minMod(int n, int arr[]) {
        // code here
    }
};

test case 1:

For Input: 
5
13 5 14 1 2

It's Correct output is: 
910

test case 2:

For Input: 
6
7 10 4 3 20 15

Expected Output: 
1


super hint:

Think about case when answer is not 1 and when all of the modulos will become 0 .
*/

#include <algorithm>

class Solution {
  public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    int minMod(int n, int arr[]) {
        // Check if 1 satisfies the condition
        bool allOnes = true;
        for (int i = 0; i < n; ++i) {
            if (arr[i] != 1) {
                allOnes = false;
                break;
            }
        }
        if (allOnes) {
            return 1;
        }

        // Compute the LCM of all elements in the array
        int result = arr[0];
        for (int i = 1; i < n; ++i) {
            result = lcm(result, arr[i]);
        }
        return result;
    }
};
