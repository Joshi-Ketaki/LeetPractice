/*
49. Group Anagrams
Solved
Medium
Topics
Companies

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.


*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // way 1
        //map<map<char, int>, vector<string>> mp;
        // way 2
        map<string, vector<string>> mp;
        size_t i;
        vector<vector<string>> ans;
        for(i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            string cs = s;
            map<char, int> tmp;
            vector<string> tmpCur;


            // The map here is such that key is sorted string and
            // value is vector of anangrammed strings
            // faster as you dont iterate through each charachter of each string
            sort(s.begin(), s.end());
            //cout << "Unsorted " << cs << "  Sorted. " << s;
            if(mp.count(s)) tmpCur = mp[s];
            tmpCur.push_back(cs);
            mp[s] = tmpCur;

            // This method creates a map where key is char-count map and 
            // value is the group of anagrammed strings i.e
            // map<map<char, int>, vector<string>> mp;
            // slower as it goes thriugh each charachter of every string
            /*for(size_t j = 0; j < s.size(); j++)
            {
                if(tmp.count(s[j])) tmp[s[j]]++;
                else tmp[s[j]] = 1;
            }

            if(mp.count(tmp)) tmpCur = mp[tmp];
            tmpCur.push_back(s);
            mp[tmp] = tmpCur;*/
        }

        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
