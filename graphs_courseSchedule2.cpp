/*
210. Course Schedule II
Solved
Medium
Topics
Companies
Hint

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    ai != bi
    All the pairs [ai, bi] are distinct.


*/

/*SOLUTION*/
// Pass 2
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prereq[numCourses];
        vector<int> inorder(numCourses, 0);
        vector<int> schedule;
        queue<int> q;

        if(numCourses == 0) return schedule;
        if(numCourses == 1) 
        {
            schedule.push_back(0);
            return schedule;
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
            return schedule;
        }
        else
        {
            schedule.erase(schedule.begin(), schedule.end());
            return schedule;
        }

    }
};
/*class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<int> prereq[numCourses];
      vector<int> indegree(numCourses, 0);
      queue<int> q;
      vector<int> courseOrder;
      int ctr=0, i;
      if(prerequisites.size() == 0 && numCourses == 1) 
      { 
          courseOrder.push_back(0);
          return courseOrder;
      }
      for(i = 0; i < prerequisites.size();i++)  
      {
          prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
      }
      for(i =0; i <  numCourses; i++)
      {
        for (int adjNode : prereq[i]){
              indegree[adjNode]++; // calculating indegree of every node
          }
      }
      for(i = 0; i < numCourses;i++)  
      {
        if(indegree[i] == 0) {
          ///cout<< "pushed";
          q.push(i);
        }
      }
      while(!q.empty()){
        int node = q.front();
        q.pop();
        //ctr++; 
        courseOrder.push_back(node);
        for(auto &i:prereq[node]){
          indegree[i]--;
          if(indegree[i] == 0)
          {
            q.push(i);
          }
        }
      }
      if(courseOrder.size() == numCourses) {
        //cout<<"ctr" << ctr;
        reverse(courseOrder.begin(), courseOrder.end());
        return courseOrder;
      }
      vector<int> empty;
      return empty;*/
