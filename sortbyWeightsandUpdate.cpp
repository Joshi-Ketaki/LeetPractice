/*

if you are constantly sorting and upadting size etc, then use  priority queue


1046. Last Stone Weight
Solved
Easy
Topics
Companies
Hint

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:

Input: stones = [1]
Output: 1

 

Constraints:

    1 <= stones.length <= 30
    1 <= stones[i] <= 1000
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //using explicit sort
        size_t sz = stones.size();
        int firstMax, secondMax, store;
        /*while(sz > 1)
        {
            sort(stones.begin(), stones.end());
            firstMax = stones[sz-1];
            secondMax = stones[sz-2];
            store = firstMax - secondMax;
            // x==y
            if(store == 0 && sz > 2)
            {
                stones.resize(sz-2);
                sz=sz-2;
            }
            else
            {
                stones.resize(sz-1);
                sz = sz-1;
                //cout<<"store is" << store;
                stones[sz-1] = store;
            }
        }
        if (sz > 0) return stones[sz-1];
        else return 0; */

        //using priority queue:
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1)
        {
            firstMax = pq.top();
            pq.pop();
            secondMax = pq.top();
            pq.pop();
            store = firstMax - secondMax;
            if(store > 0)
            {
                pq.push(store);
            }
        }
        if(pq.size()==1) return pq.top();
        else return 0;
    }
};
