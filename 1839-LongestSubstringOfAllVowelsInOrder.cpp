class Solution {
public:
    int longestBeautifulSubstring(string w) {
        int i = 1; int j = 0;
        char ls = w[0];
        int res{};
        int s{1};
        while(i<w.size()){
            //cout<<"i = "<<i<<" j = "<<j<<" ls = "<<ls<<" res = "<<res<<" s = "<<s<<endl;
            if(ls<w[i]){
                s++;
                ls = w[i];
            }else if(ls==w[i]){
                
            }
            else{
                if(ls=='u'&&s == 5)
                    res = max(res, i-j);
                j = i;
                ls = w[i];
                s = 1;
            }
            i++;
        }
        if(ls=='u'&&s == 5)
            res = max(res, i-j);
        return res;
    }
};
