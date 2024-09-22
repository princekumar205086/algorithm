/*

There are n students in Geekland numbered from 1 to n and m schools numbered from 1 to m .We are given an array arr whose length is n which represents that ith students  belongs to arr[i] school intially .We are given an integer array strength of length n where strength[i] represents the strength of ith student.

Now we are given an 2D integer array transfers[][] whose length is q where transfers[i]=[childi,schooli] means that after ith transfer childi belongs to schooli. After each transfer we calculate the oddness of each school and return the maximum oddness among all schools.Oddness of a school is defined as the minimum strength of all the students studying in that school . So we have to return an array of length transfers where ith element corresponds to the maximum oddness among all schools after the ith transfer took place .Transfers should be performed in same order as given in the 2D integer array transfers[][].

Note: if school has no student its oddness is considered as 0.

Example 1:

Input:
n=3
m=3
q=2
arr={1,2,3}
strength={1,3,4}
transfer={{1,3},{3,1}}

Output:
{3,4}

Explanation:
After 1st transfer student 2 belongs to school 2 and student 1,3 belongs to school 3 . Now oddness of school 1 is 0 as no student . oddness of school 2 is 3 . oddness of school 3 is 1 min(1,4) . so maximum values among all oddness is 3.
so 3 is the result after 1st tranfer.

After 2nd tranfer happens student 1 belongs to school 3 and student 2 belongs school 2 and student 3 belongs school 1. 
Now oddness of school 1,2,3  are  4,3,1 respectively so maximum values among all oddness is 4. So 4 is the result after 2nd tranfer.
Example 2:

Input:
n=4
m=4
q=2
arr={1,2,3,2}
strength={1,3,4,5}
transfer={{1,4},{4,1}}
Output:
{4,5}
Explanation:
After 1st transfer student 2,4 belongs to  school 2 and student 3 belongs to school 3 and student 1 belongs to school 4 .Now oddness of school 1 is 0 as no student .Oddness of school 2 is 3{min(3,5)}.Oddness of school 3 is 4 .Oddness of school 4 is 1.So maximum values among all oddness is 4.

After 2nd tranfer student 1 belongs to school 4 ,student 2 belongs to school 2 and student 3 belongs school 3 and student 4 belongs to school 1. Now oddness of school 1,2,3,4 are 5,3,4,1 respectively so maximum values among all oddness is 5. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxStudent() which takes an integer n ,integer m, integer q , an array of integers arr and an integer array strength and a 2 d array transfers and returns the integer array whose length is eqaul to tranfers where ith element corresponds to the maximum oddness among all schools after the ith transfer took place.

Constraints:
1 ≤ n ≤ 105
1 ≤ m ≤ 105
1 ≤ q ≤ 105
1 ≤ arr[i] ≤ m
1 ≤ strength[i] ≤ 105
1 ≤ transfer[i][0] ≤ n
1 ≤ transfer[i][1] ≤ m

//cpp 5.4.0


class Solution{
public:
    vector<int> maxStudent(int n,int m,int q,vector<int> &arr,vector<int> &strength,vector<vector<int>> &transfers){
        // Code here
    }
};


test case 1:
For Input: 
8 5 10
1 3 3 2 1 2 1 1
8 2 8 9 8 6 4 8
5 1
3 2
8 1
2 5
1 4
3 3
8 4
5 5
3 5
1 2

It's Correct output is: 
6 6 6 6 8 8 8 8 8 8

test case 2:

For Input: 
3 3 2
1 2 3
1 3 4
1 3
3 1

Expected Output: 
3 4

super hint for optimization:

We can see that with each transfer will effect at max  2 of the schools rest data will be same so we can maintain some sort of data and see the change happened to these two schools and return answer accordingly .

*/


#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> maxStudent(int n, int m, int q, vector<int> &arr, vector<int> &strength, vector<vector<int>> &transfers) {
        unordered_map<int, multiset<int>> school_students;
        unordered_map<int, int> school_oddness;
        
        for (int i = 0; i < n; ++i) {
            int school = arr[i];
            int student_strength = strength[i];
            school_students[school].insert(student_strength);
        }
        
        for (int i = 1; i <= m; ++i) {
            if (!school_students[i].empty()) {
                school_oddness[i] = *school_students[i].begin();
            } else {
                school_oddness[i] = 0;
            }
        }
        
        vector<int> result;
        for (const auto &transfer : transfers) {
            int student = transfer[0] - 1;
            int new_school = transfer[1];
            int old_school = arr[student];
            int student_strength = strength[student];
            
            school_students[old_school].erase(school_students[old_school].find(student_strength));
            if (school_students[old_school].empty()) {
                school_oddness[old_school] = 0;
            } else {
                school_oddness[old_school] = *school_students[old_school].begin();
            }
            
            school_students[new_school].insert(student_strength);
            school_oddness[new_school] = *school_students[new_school].begin();
            
            arr[student] = new_school;
            
            int max_oddness = 0;
            for (const auto &entry : school_oddness) {
                max_oddness = max(max_oddness, entry.second);
            }
            result.push_back(max_oddness);
        }
        
        return result;
    }
};

