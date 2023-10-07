/*
117. Populating Next Right Pointers in Each Node II
Solved
Medium
Topics
Companies

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 6000].
    -100 <= Node.val <= 100

 

Follow-up:

    You may only use constant extra space.
    The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/

/*SOLUTION*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue <Node*> q;
        if(root == NULL) return NULL;
        q.push(root);
        int ctr = 0;
        Node* node;
        int n = q.size();
        while(!q.empty())
        {
            n = q.size();
            cout << "\n n" << n;
            ctr = ctr + n;
            assert(n >= 0 && n <= 6000);
            for(int i = 0; i < n; i++){
                node = q.front();   
                if(node)
                {
                    assert(node->val >= -100 && node->val <=100);
                    //cout << "\nnode" << node->val;
                }
                q.pop();
                // note this. only within current level
                // if using q.empty(), it sets next ptrs to child level
                // while iterating current
                if(i < n-1)
                    node->next = q.front();
                if(node->left) 
                {
                    //cout << "\n left node" << node->left->val;
                    q.push(node->left);
                }
                if(node->right) 
                {
                    //cout << "\nroght node" << node->right->val;
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
