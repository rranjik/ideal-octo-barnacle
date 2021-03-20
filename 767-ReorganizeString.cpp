class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26);
        for(const auto& c : s){
            f[c-'a']++;
        }
        auto comp = [&](const char& c1, const char& c2){
            return f[c1-'a']<f[c2-'a'];
        };
        priority_queue<char, vector<char>, decltype(comp)> q(comp);
        string res;
        for(int i = 0; i<26; i++){
            if(f[i]>0) q.push((char)'a'+i);
        }
        while(q.size()>1){
            //most frequent
            auto mf = q.top(); q.pop();
            //next frequent
            auto nf = q.top(); q.pop();
            res+=mf; res+=nf;
            f[mf-'a']--;
            f[nf-'a']--;
            if(f[mf-'a']) q.push(mf);
            if(f[nf-'a']) q.push(nf);
        }
        if(q.size()==1){
            if(f[q.top()-'a']>=2) return "";
            res+=q.top();
        }
        return res;
    }
};
