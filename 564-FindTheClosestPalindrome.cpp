class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size()==1) return to_string(stoi(n)-1);
        int d = n.size();
        vector<long> c;//candidats
        c.push_back(pow(10, d-1)-1);//# of digits in answer is less. 9, 99, 999, etc
        c.push_back(pow(10, d)+1);//# of digits in answer is more. 101, 1001, etc
        int m = (d+1)/2;
        long prefix = stol(n.substr(0, m));
        vector<long> pc{prefix, prefix-1, prefix+1};//prefix candidates
        for(const auto& prefix : pc){
            auto postfix = to_string(prefix);
            if(d%2) postfix.pop_back();//throw away extra repeated digit 
            reverse(postfix.begin(), postfix.end());
            auto nc = to_string(prefix)+postfix;
            c.push_back(stol(nc));
        }
        auto mind = numeric_limits<long>::max();
        auto res = 0l;
        auto num = stol(n);
        for(const auto& cc : c){
            cout<<"next candidate = "<<cc<<endl;
            if(cc!=num&&abs(cc-num)<mind){
                mind = abs(cc-num);
                res = cc;
            }else if(abs(cc-num)==mind){
                res = min(res, cc);
            }
        }
        return to_string(res);
    }
};
