class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s;
        string proc;
        stringstream ss(preorder);
        string i;
        while (getline(ss, i, ',')) {
         //cout << i << endl;
         if(i!="#")
             proc+='1';
         else proc+='#';
        }
        for(const auto& c : proc){
            if(c!=','){
                if(c=='#'){
                    //cout<<"it was a #"<<endl;
                    if(!s.empty()){
                        //... #
                        if(s.top()=='#'){
                            s.pop();
                            //... (#)
                            if(!s.empty()&&s.top()!='#'){
                                //... n (#)
                                s.pop();
                                //... (n) (#) - (#)
                                //... # (n) (#) - (#)
                                while(!s.empty()&&s.top()=='#'){
                                    s.pop();
                                    //... (#) (n) (#) - (#)
                                    if(!s.empty()&&s.top()!='#'){
                                        s.pop();
                                    }
                                    else return false;
                                }
                                s.push('#');
                            }
                            //... # # 
                            else return false;
                        }
                        //... n 
                        else s.push(c);
                    }
                    else s.push(c);
                }
                else {
                    //cout<<"it was the number "<<c<<
                    s.push(c);
                }
            }
            //else cout<<"it is just a "<<c<<endl;
        }
        if(!s.empty()&&s.size()==1&&s.top()=='#')
            return true;
        else return false;
    }
};
