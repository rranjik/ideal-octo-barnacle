class Solution {
public:
    using pii = pair<int, int>;
    bool isvalid(pii t){
        if(t.first>=0&&t.first<=23&&t.second>=0&&t.second<=59) return true;
        return false;
    }
    pii compare(pii t1, pii t2){
        if(!isvalid(t1)&&!isvalid(t2)) return {-1, -1};
        if(isvalid(t1)&&!isvalid(t2)){
            return t1;
        }else if(!isvalid(t1)&&isvalid(t2)) {
            return t2;
        }
        if(t1.first==t2.first) {
            if(t1.second>t2.second) return t1;
            return t2;
        } else if(t1.first>t2.first) return t1;
        return t2;
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        pii res = {-1, -1};
        do{
            res = compare(res, {A[0]*10+A[1], A[2]*10+A[3]});
        }while(next_permutation(A.begin(), A.end()));
        if(res.first==-1||res.second==-1) return "";
        string rres;
        if(res.first<=9) rres+="0";
        rres += to_string(res.first);
        rres+=":";
        if(res.second<=9) rres+="0";
        rres += to_string(res.second);
        return rres;
    }
};
