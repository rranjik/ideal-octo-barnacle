class Solution {
public:
    bool isNumber(string s) {
        int i = 0; 
        while(i<s.length()&&s[i]==' ') i++;
        s = s.substr(i);
        while(s.size()&&s[s.size()-1]==' ') s.erase(prev(s.end()));
        if(s.size()==0) return false;
        int state = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='+'||s[i]=='-'){
                if(state==0||state==3) state++;
                else return  false;
            }
            else if(s[i]=='.'){
                if(state==0||state==1) state = 6;
                else if(state==2) state = 2;
                else return false;
            }
            else if(s[i]=='e'||s[i]=='E'){
                if(state==2||state==7) state = 3;
                else return false;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                if(state==0||state==3) state+=2;
                else if(state==1||state==4||state==6) state++;
            }
            else return false;
        }
        if(state==2||state==5||state==7) return true;
        
        return false;
    }
};
