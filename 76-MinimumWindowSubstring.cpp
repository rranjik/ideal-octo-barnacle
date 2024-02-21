class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        unordered_map<char, int> orifreq;
        for(const auto& c : t) freq[c]++;
        orifreq = freq;
        int i = 0; int j = 0;
        int m = s.size(); int n = t.size();
        int count = n;
        int reslen = 1e9;
        int start = 0; int end = m-1;
        while(j<m){
            //cout<<j<<endl;
            if(freq.find(s[j])!=freq.end()){
                //cout<<"found "<<endl;
                freq[s[j]]--;
                if(freq[s[j]]>=0){
                    count--;
                }
            }
            while(count==0){
                if(reslen>(j-i+1)){
                    reslen = j-i+1;
                    start = i; end = j;
                }
                if(freq.find(s[i])!=freq.end()){
                    freq[s[i]]++;
                    if(freq[s[i]]>0){
                        count++;
                    }
                    //if(freq[s[i]]==1) count++;
                }
                i++;
            }
            //cout<<count<<endl;
            //for(const auto& [c, f] : freq) cout<<c<<" "<<f<<endl;
            j++;
        }
        return reslen==1e9?"":s.substr(start, end-start+1);
    }
};
