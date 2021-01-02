class Solution {
public:
    string reformatNumber(string number) {
        vector<int> n;
        for(const auto& c : number){
            if(c>='0'&&c<='9'){
                n.push_back(c-'0');
            }
        }
        auto left = n.size();
        string res;
        int i = 0;
        while(left>4){
            res.push_back(static_cast<char>('0'+n[i]));
            res.push_back(static_cast<char>('0'+n[i+1]));
            res.push_back(static_cast<char>('0'+n[i+2]));
            res.push_back('-');
            left-=3;
            i+=3;
        }
        if(left==4){
            res.push_back(static_cast<char>('0'+n[i]));
            res.push_back(static_cast<char>('0'+n[i+1]));
            res.push_back('-');
            res.push_back(static_cast<char>('0'+n[i+2]));
            res.push_back(static_cast<char>('0'+n[i+3]));
        }else if(left == 3){
            res.push_back(static_cast<char>('0'+n[i]));
            res.push_back(static_cast<char>('0'+n[i+1]));
            res.push_back(static_cast<char>('0'+n[i+2]));
        }else {
            res.push_back(static_cast<char>('0'+n[i]));
            res.push_back(static_cast<char>('0'+n[i+1]));
        }
        return res;
    }
};
