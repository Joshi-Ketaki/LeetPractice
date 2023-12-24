/*
356. Line Reflection
Solved
Medium
Topics
Companies
Hint

Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.

In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points' set is the same as the reflected ones.

Note that there can be repeated points.

 

Example 1:

Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.

Example 2:

Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.

 

Constraints:

    n == points.length
    1 <= n <= 104
    -108 <= points[i][j] <= 108

 

Follow up: Could you do better than O(n2)?

*/

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
       if(points.size() < 2) return true;
       
       //map<pair<int, int>, int> myMap;
       set<pair<int, int>> mySet;
       int xmin, xmax;
       xmin = xmax = points[0][0];
       for(auto p: points)
       {
           xmin = min(xmin, p[0]);
           xmax = max(xmax, p[0]);
           mySet.insert({p[0], p[1]});
           //myMap[{p[0], p[1]}]++;;
       }

       float xmirror = xmin + xmax;
       xmirror = xmirror/2.0;
       // iterate through points to find complement in set....not through set
       for(auto p: points)
       {
           //if(myMap.find({(2*xmirror) - p[0], p[1]}) == myMap.end())

           // the natural way I thought about this is first create a map where y coordinate will be keys
           // and all x coords will be values. then the qsthn is how to find pairs among these
           // set of x-coords....you could sort them and the min and max will be one pair... keep coming inwards
           //so x2,x1 and x3,x4 are pairs if x2+x1/2 = xmirror = x3+x4/2 etc

           // eg [1,0], [0,0], [-1, 0]

           // y-> -1,0,1
           // so -1 and 1 are going to be a pair. 0 wth itself is a pair
           // which is -1+1/2 = 0/2 =0
           // so...xmid = x1+x2/2...so if we knwo x1, x2=xmid-x1/2 and x2 should have same y as x1. so if such a point exists then we are good.
           // using set/map is better for lookup given p[1] rather than select one point and then go over all points and keep track f you find a pair etc. that would be O(n^2)
           if(mySet.find({(2*xmirror) - p[0], p[1]}) == mySet.end())
                return false;
       }
       return true;
    }
};
