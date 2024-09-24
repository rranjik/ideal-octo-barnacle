class Solution {
public:
    //string move(string s){
    //    auto res = s;
    //    for(int i = 0; i<s.size(); i++){
    //        if(s[i]=='L'){
    //            int j = i;
    //            while(j-1>=0&&res[j-1]=='_'){
    //                res[j-1] = 'L';
    //                res[j] = '_';
    //                j--;
    //            }
    //        }
    //    }
    //    for(int i = s.size()-1; i>=0; i--){
    //        if(s[i]=='R'){
    //            int j = i;
    //            while(j+1<s.size()&&res[j+1]=='_'){
    //                res[j+1] = 'R';
    //                res[j] = '_';
    //                j++;
    //            }
    //        }
    //    }
    //    return res;
    //}
    pair<int, int> count(string s){
        int ls = 0;
        int rs = 0;
        for(const auto& c : s){
            if(c=='L') ls++;
            if(c=='R') rs++;
        }
        return {ls, rs};
    }
    bool canChange(string s, string t) {
        if(s==t) return true;
        if(count(s)!=count(t)) return false;
        int j = 0;
        for(int i = 0; i<t.size(); i++){
            if(t[i]=='L'){
                if(s[i]=='L') continue;
                int j = i;
                while(j+1<s.size()&&s[j]=='_'){
                    j++;
                }
                if(j>=s.size()||s[j]!='L') return false;
            }
        }
        for(int i = t.size()-1; i>=0; i--){
            if(t[i]=='R'){
                if(s[i]=='R') continue;
                int j = i;
                while(j-1>=0&&s[j]=='_'){
                    j--;
                }
                if(j<0||s[j]!='R') return false;
            }
        }
        return true;
        //if(start==target) return true;
        //auto s = move(start);
        //cout<<s<<endl;
        //return s==target;
    }
};
