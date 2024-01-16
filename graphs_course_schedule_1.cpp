/*
207. Course Schedule
Solved
Medium
Topics
Companies
Hint

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.
*/

/*SOLUTION*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)  {
        vector<int> prereq[numCourses];
        vector<int> inorder(numCourses, 0);
        vector<int> schedule;
        queue<int> q;

        if(numCourses == 0) return true;
        if(numCourses == 1) 
        {
            schedule.push_back(0);
            return true;
        }

        for(int i = 0; i < prerequisites.size(); i++)
        {
            //index = course, values=dependencies
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            for(auto adjNode: prereq[i]){
                inorder[adjNode]++;
            }
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(inorder[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            schedule.push_back(c);
            // one incoming as self as well
            inorder[c]--;
            if(inorder[c] == 0) 
                q.push(c);
            // reduce incoming of all those who this c depended on
            for(auto &pr: prereq[c])
            {
                inorder[pr]--;
                if(inorder[pr] == 0)
                    q.push(pr);
            }
            

        }

        reverse(schedule.begin(), schedule.end());
        if(schedule.size() >= numCourses)
        {
            return true;
        }
        else
        {
            //schedule.erase(schedule.begin(), schedule.end());
            return false;
        }

    }
};
