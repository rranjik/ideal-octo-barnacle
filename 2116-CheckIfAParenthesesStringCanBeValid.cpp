class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2) return false;
        int bal = 0;
        int wild = 0;
        for(int i = 0; i<s.size()&&wild+bal>=0; i++){
            if(locked[i]=='1'&&s[i]=='('){
                bal++;
            }else if(locked[i]=='1'&&s[i]==')'){
                bal--;
            }else{
                wild++;
            }
        }
        if(wild+bal<0) return false;
        bal = 0;
        wild = 0;
        for(int i = s.size()-1; i>=0&&wild+bal>=0; i--){
            if(locked[i]=='1'&&s[i]==')'){
                bal++;
            }else if(locked[i]=='1'&&s[i]=='('){
                bal--;
            }else{
                wild++;
            }
        }
        if(wild+bal<0) return false;
        return true;
    }
};
