/*
253. Meeting Rooms II
Solved
Medium
Topics
Companies
Hint

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1

 

Constraints:

    1 <= intervals.length <= 104
    0 <= starti < endi <= 106


*/


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        //min heap
        // greater: allows smallest element to be on top
        priority_queue<int, vector<int>, greater<int>>pq;

        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++)
        {
            int t = pq.top();
            // if topmost i.e. smallest time room free, use that
            if(intervals[i][0] >= t)
            {
                pq.pop();
            }
            //add to the queue irrespective of room free or not
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};
