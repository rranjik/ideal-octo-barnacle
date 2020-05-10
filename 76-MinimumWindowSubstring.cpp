class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int count = 0;
        for(const auto& c : t){
            count++;
            if(m.find(c)!=m.end()) m[c]++;
            else m[c] = 1;
        }
        int l = 0, r = 0, mini = numeric_limits<int>::max(), minl = 0, minr = 0;
        while(r<s.size()){
            //cout<<"r = "<<r<<endl;
            //if present decrement count 
            if(m.find(s[r])!=m.end()){
                m[s[r]]--;
                //cout<<"found "<<s[r]<<" setting freq to "<<m[s[r]]<<endl;
                if(m[s[r]]>=0) {
                    count--;
                    //cout<<"decrementing count. set count to "<<count<<endl;
                }
            }
            while(count==0){
                //update min
                if(mini>(r-l+1)) {
                    mini = (r-l+1);
                    minl = l;
                    minr = r;
                }
                if(m.find(s[l])!=m.end()){
                    if(m[s[l]]==0) {
                        m[s[l]]++;
                        //cout<<"found "<<s[l]<<" setting freq to "<<m[s[l]]<<endl;
                        count++;
                        //cout<<"incrementing count. set count to "<<count<<endl;
                    }else 
                        m[s[l]]++;
                }
                l++;
            }
            r++;
        }
        return mini==numeric_limits<int>::max()?"":s.substr(minl, (minr-minl+1));
    }
};
