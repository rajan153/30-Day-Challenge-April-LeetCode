Node* dfs(Node* node, unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto it : node->neighbors)
        {
            if(mp.find(it) != mp.end())
                neighbour.push_back(mp[it]);
            else
                neighbour.push_back(dfs(it, mp));
        }
        newNode->neighbors = neighbour;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node == NULL)
            return NULL;

        if(node->neighbors.size() == 0){
            Node* newNode = new Node(node->val);
            return newNode;
        }
        return dfs(node, mp);
    }
