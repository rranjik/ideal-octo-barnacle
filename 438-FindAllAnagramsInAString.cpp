class Solution {
public:
    void print(const unordered_map<char, int>& m){
        for(auto it = m.begin(); it!=m.end(); it++)
            cout<<it->first<<": "<<it->second<<"; ";
        cout<<endl;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> f;
        for(const auto& c : p){
            //if(f.find(c)!=f.end())
            f[c]++;
            //else{
            //    f[c] = 1;
            //}
        }
        vector<int> res;
        int count = p.length();
        int l = 0;
        int r = p.length()-1;
        for(int i = l; i<=r; i++){
           if(f.find(s[i])!=f.end()){
               f[s[i]]--;
               if(f[s[i]]>=0)
                   count--;
           }
        }
        if(!count) res.push_back(l);
        while(r<s.length()){
            //print(f);
            //cout<<"count = "<<count<<endl;
            l++; r++;
            if(r<s.length()){
                if(f.find(s[l-1])!=f.end()){
                   f[s[l-1]]++;
                   if(f[s[l-1]]>0)
                       count++;
                }
                if(f.find(s[r])!=f.end()){
                   f[s[r]]--;
                   if(f[s[r]]>=0)
                       count--;
                }
                if(count==0) res.push_back(l);
            }
        }
        return res;
    }
};
