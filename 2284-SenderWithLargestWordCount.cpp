class Solution {
public:
    int count(string& s){
        int res = 0;
        for(const auto& c : s){
            if(c==' '){
                res++;
            }
        }
        res++;
        return res;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> c;
        for(int i = 0; i<messages.size(); i++){
            c[senders[i]]+=count(messages[i]);
        }
        string res;
        int mc = 0;
        for(const auto& [p, n]:c){
            if(n>mc){
                res = p;
                mc = n;
            }else if(n==mc){
                res = max(p, res);
            }
        }
        return res;
    }
};
