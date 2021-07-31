class Solution {
public:
    string entityParser(string text) {
        //replacements
        unordered_map<string, string> reps = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
        };
        string res;
        for(int i = 0; i<text.size(); i++){
            if(text[i]=='&'){
                //'&'to'&' or '&'to';' accumulator
                string accum;
                while(i<text.size()){
                    accum+=text[i];
                    if(text[i]==';'&&reps.find(accum)!=reps.end()){
                        res+=reps[accum];
                        accum = "";
                        break;
                    }
                    else i++;
                    //subpattern
                    if(text[i]=='&'){
                        //
                        i--;
                        break;
                    }
                }
                res+=accum;
            }else res+=text[i];
        }
        return res;
    }
};
/*
            if(text[i]=='&')
            {
                string s;
                while(i<text.size())
                {
                    s+=text[i];
                    
                    if((text[i]==';')&&m.find(s)!=m.end())
                    {
                        ans+=m[s];
                        s="";
                        break;
                    }
                    else i++;
                    if(text[i]=='&')
                    {
                        i--;
                        break;
                    }
                }
                ans+=s;
            }
            else
            {
                ans+=text[i];
            }
        }
        return ans;
    }
*/
