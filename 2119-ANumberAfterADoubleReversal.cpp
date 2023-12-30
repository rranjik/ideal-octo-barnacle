class Solution {
public:
    bool isSameAfterReversals(int num) {
        auto sn = to_string(num);
        cout<<"sn = "<<sn<<endl;
        
        reverse(begin(sn), end(sn));
        cout<<"reversed sn = "<<sn<<endl;
        
        int rn = stoi(sn);
        cout<<"rn = "<<rn<<endl;
        
        auto rsn = to_string(rn);
        cout<<"rsn = "<<rsn<<endl;
        
        reverse(begin(rsn), end(rsn));
        cout<<"rsn = "<<rsn<<endl;
        
        int rrn = stoi(rsn);
        cout<<"rrn = "<<rrn<<endl;
        
        return rrn == num;
    }
};
