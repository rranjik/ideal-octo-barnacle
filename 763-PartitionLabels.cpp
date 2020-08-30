class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> freq(26, 0);
        for(const auto& c : S){
            freq[c-'a']++;
        }
        vector<int> res;
        int l = 0; 
        int r = 0;
        int ccost = freq[S[r]-'a'];
        ccost--;
        set<char> cseen;
        cseen.insert(S[r]);
        while(r<S.length()){
            if(ccost==0){
                res.push_back(r-l+1);
                cseen.clear();
                r++;
                if(r<S.length()){
                    cseen.insert(S[r]);
                    l=r;
                    ccost+=freq[S[r]-'a'];
                    ccost--;
                }
            }else{
                r++;
                if(r<S.length()){
                    if(cseen.find(S[r])!=cseen.end()){
                        ccost--;
                    }
                    else{
                        cseen.insert(S[r]);
                        ccost+=freq[S[r]-'a'];
                        ccost--;
                    }
                }
            }
        }
        return res;
    }
};
