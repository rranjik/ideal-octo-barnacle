class Solution {
public:
    string simplifyPath(string path) {
        stack<string> f;
        vector<string> dirs;
        int last_pos = 0;
        int pos = 0;
        while((pos = path.find('/', last_pos))!=string::npos){
            string dir = path.substr(last_pos, pos-last_pos);
            if(dir.length())
                dirs.push_back(dir);
            cout<<dir<<endl;
            last_pos = pos+1;
        }
        string ldir = path.substr(last_pos, string::npos);
        if(ldir.length())
        dirs.push_back(ldir);
        cout<<ldir<<endl;
        for(const auto& dir : dirs){
            if(dir==".."){
                if(!f.empty()){
                    f.pop();
                }
            }else if(dir != "."){
                f.push(dir);
            }
        }
        stack<string> rs;
        while(!f.empty()){
            rs.push(f.top());
            f.pop();
        }
        string res="/";
        while(!rs.empty()){
            cout<<"dir = "<<rs.top()<<endl;
            res+=rs.top();
            res+="/";
            rs.pop();
        }
        if((res.length()>1)&&res[res.length()-1]=='/') res.pop_back();
        return res;
    }
};
