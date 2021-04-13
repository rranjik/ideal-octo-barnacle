class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int j = 0; j<words.size();){
            auto linel = 0;
            //word widths (w/o spaces)
            auto ww = 0;
            vector<string> line;
            while(j<words.size()&&linel<maxWidth&&(linel+words[j].length())<=maxWidth){
                line.push_back(words[j]);
                linel+=words[j].size();
                ww+=words[j].size();
                linel+=1;
                j++;
            }
            if(j<words.size()){
                //number of spaces 1(a b), 0(a ), 2(a b c)
                auto ns = line.size()-1;
                if(ns){
                    auto spaces = maxWidth-ww;
                    if(spaces%ns){
                        int rem = spaces%ns;
                        int nsrem = ns-rem;
                        string r;
                        int i = 0;
                        for(; i<rem; i++){
                            r+=line[i];
                            r+=string(spaces/ns+1, ' ');
                        }
                        r+=line[i];
                        i++;
                        int k = 0;
                        for(;k <nsrem; k++, i++){
                            r+=string(spaces/ns, ' ');
                            r+=line[i];
                        }
                        res.push_back(r);
                    }else{
                        string r;
                        int i = 0;
                        for(; i<ns; i++){
                            r+=line[i];
                            r+=string(spaces/ns, ' ');
                        }
                        r+=line[i];
                        res.push_back(r);
                    }
                }else{
                    string r;
                    r+=line[0];
                    r+=string(maxWidth-line[0].size(), ' ');
                    res.push_back(r);
                }
            }else{
                string r;
                int i =0;
                for(i = 0; i<line.size(); i++){
                    r+=line[i];
                    r+=string(1, ' ');
                }
                r.pop_back();
                if(maxWidth-linel>=0){
                    r+=string(1, ' ');
                    r+=string(maxWidth-linel, ' ');
                }
                res.push_back(r);
            }
        }
        return res;
    }
};
