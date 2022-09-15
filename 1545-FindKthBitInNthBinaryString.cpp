class Solution {
public:
    string invert(const string& s){
        string res = s;
        for(auto& c : res){
            if(c=='0'){
                c = '1';
            }else{
                c = '0';
            }
        }
        return res;
    }
    char findKthBit(int n, int k) {
        string curr = "0";
        int i = 0;
        while(i<n){
            auto prev = curr;
            auto inv = invert(prev);
            reverse(inv.begin(), inv.end());
            curr = prev+"1"+inv;
            i++;
        }
        return curr[k-1];
    }
};
