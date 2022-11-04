class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res{};
        vector<string> p;
        p.push_back("main");
        for(const auto& l : logs){
            if(l=="../"){
                if(p.size()>1) p.pop_back();
            }else if(l!="./"){
                p.push_back(l);
            }
        }
        return p.size()-1;
    }
};
