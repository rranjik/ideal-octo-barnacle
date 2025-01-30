class Solution {
public:
    pair<int, int> cnt(string s){
        int z = 0;
        int o = 0;
        for(const auto& c : s){
           if(c=='0'){
               z++;
           }else{
               o++;
           }
        }
        return {z, o};
    }
    int corr(string s, char r){
        int res = 0;
        for(const auto& c : s){
            if(c!=r){
                res++;
            }
            r=(r=='0'?'1':'0');
        }
        cout<<s<<" "<<res<<endl;
        return res/2;
    }
    int minSwaps(string s) {
        auto [zs, os] = cnt(s);
        bool okay = false;
        if(zs==os||(abs(zs-os)==1)){
            okay = true;
        }
        if(!okay) return -1;
        if(os>zs){
            return corr(s, '1');
        }else if(os<zs){
            return corr(s, '0');
        }
        return min(corr(s, '0'), corr(s, '1'));
    }
};
