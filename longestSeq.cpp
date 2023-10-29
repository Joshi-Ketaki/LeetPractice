/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109


*/
/*SOLUTION*/
class Solution {
public:
    void printArr(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            cout<< " " <<nums[i];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1 || (nums.size() == 2 && nums[0] == nums[1])) return 1;
        sort(nums.begin(), nums.end());
        int cntr = 0;
        vector<int> seq(nums.size(), 0);

        //printArr(nums);
        for(int i = 0; i < nums.size()-1; i++)
        {
            
            if(nums[i] != nums[i+1])
            {
               
                if(nums[i+1]-nums[i] == 1)
                {
                    //cout << "\nin here";
                    //cout << " " <<nums[i+1];
                    //cout << " " <<nums[i];
                    cntr++;
                }
                else{
                    // reset if loss of consecutivity
                    //cout << "resetting";
                    //if(cntr > 0) cntr++;
                    //cout << "pushing" << cntr;
                    cntr++;
                    seq.push_back(cntr);
                    cntr = 0;
                }
            }
  
        }
        cntr = cntr+1;
        seq.push_back(cntr);
        printArr(seq);
        int max = 0;
        for (int i = 0; i < int(seq.size()); i++)
        {
            if(seq[max] < seq[i]){
                //cout << "in here2";
                max = i;
            }
        }
        //cout << "max" << seq[max];
        return seq[max];
    }
};
