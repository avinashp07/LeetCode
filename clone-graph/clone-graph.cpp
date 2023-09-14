/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*,Node*>& mp)
    {
        vector<Node*> neighbors;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto neigh : node->neighbors)
        {
            if(mp.find(neigh)!=mp.end())
            {
                neighbors.push_back(mp[neigh]);
            }
            else
            {
                neighbors.push_back(dfs(neigh,mp));
            }
        }
        clone->neighbors = neighbors;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mp;
        if(node==NULL) return NULL;

        if(node->neighbors.size()==0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }
        else
        return dfs(node,mp);
    }
};