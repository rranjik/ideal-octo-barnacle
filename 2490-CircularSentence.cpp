class Solution {
public:
    vector<string> wordify(string s){
        stringstream ss;
        ss << s;
        vector<string> res;
        string w;
        while(getline(ss, w, ' ')){
            res.push_back(w);
        }
        return res;
    }
    bool isCircularSentence(string sentence) {
        auto w = wordify(sentence);
        for(const auto& x : w) cout<<x<<", "; cout<<endl;
        for(int i = 0; i<w.size()-1; i++){
            if(w[i][w[i].size()-1]!=w[i+1][0])
                return false;
        }
        int n = w.size();
        return w[n-1][w[n-1].size()-1] == w[0][0];
    }
};
