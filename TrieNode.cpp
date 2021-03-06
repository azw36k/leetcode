struct TrieNode {
    vector<int> indices;
    vector<TrieNode*> children;
    TrieNode() : children(26, NULL) {}
};
TrieNode* build(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < words.size(); ++i) {
        TrieNode *t = root;
        for (int j = 0; j < words[i].size(); ++j) {
            if (!t->children[words[i][j] - 'a']) 
                t->children[words[i][j] - 'a'] = new TrieNode();
            t = t->children[words[i][j] - 'a'];
            t->indices.push_back(i);
        }
    }
    return root;
}
