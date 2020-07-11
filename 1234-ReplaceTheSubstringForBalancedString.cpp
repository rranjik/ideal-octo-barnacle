class Solution {
public:
    unordered_map<char, int> m{
        {q, 0},
        {w, 0},
        {e, 0},
        {r, 0},
    };
    const char q = 'Q';
    const char r = 'R';
    const char w = 'W';
    const char e = 'E';
    bool valid(){
        if((m[q]<=n/4)&&(m[r]<=n/4)&&
           (m[w]<=n/4)&&(m[e]<=n/4)) {
            //cout<<"valid "<<endl;
            return true;
        }
        //cout<<"invalide "<<endl;
        return false;
    }
    int n;
    void print(){
        cout<<"Q :"<<m[q]<<"; W :"<<m[w]<<"; E :"<<m[e]<<"; R :"<<m[r]<<endl;
    }
    int balancedString(string s) {
        for(const auto& c : s){
            m[c]++;
        }
        n = s.size();
        if(m[q]==n/4&&m[w]==n/4&&m[e]==n/4&&m[r]==n/4)return 0;
        int l = 0; 
        int r = 0;
        int res = numeric_limits<int>::max();
        while(r<n){
            m[s[r]]--;
            //print();
            while(valid()&&(l<n)){
                res = min(res, (r-l+1));
                m[s[l]]++;
                l++;
                //print();
            }
            r++;
        }
        return res;
    }
};
