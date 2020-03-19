public:
    static constexpr int null = numeric_limits<int>::min();
    vector<int> split(const string& s){
        vector<int> res;
        int from = 0;
        int pos = 0;
        while((pos = s.find('|', from))!=string::npos){
            string field = s.substr(from, pos-from);
            from = pos+1;
            res.push_back(stoi(field));
        }
        return  res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        auto res = help_serialize(root);
        cout<<res<<endl;
        return res;
    }
    
    string help_serialize(TreeNode* root){
        string res;
        if(!root){
            res+=to_string(null);
            res+="|";
        }else {
            res+=to_string(root->val);
            res+="|";
            res+=help_serialize(root->left);
            res+=help_serialize(root->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> spl = split(data);
        for(const auto& s : spl){
            cout<<s<<" ";
        }
        cout<<endl;
        TreeNode* res = nullptr;
        int start = 0;
        res = help_deserialize(0, spl, start);
        cout<<"start = "<<start<<endl;
        return res;
    }
    
    TreeNode* help_deserialize(int i, const vector<int>& d, int& res){
        cout<<"i = "<<i<<endl;
        if(i>d.size()){
            cout<<"something's wrong "<<endl;
            return nullptr;
        }else {
            if(d[i]==null) {
                cout<<"i = "<<i<<" (null) returned "<<i+1<<endl;
                res = i+1;
                return nullptr;
            }
            TreeNode* root = new TreeNode(d[i]);
            int left = -1, right = -1;
            //TreeNode* left = nullptr; TreeNode* right = nullptr;
            root->left = help_deserialize(i+1, d, left);
            root->right = help_deserialize(left, d, right);
            //res->left = left;
            //res->right = right;
            cout<<"i = "<<i<<" sets res to "<<right<<" root = "<<
                root->val<<(root->left?root->left->val:-1)<<
                (root->right?root->right->val:-1)<<endl;
            res = right;
            return root;
        }
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
