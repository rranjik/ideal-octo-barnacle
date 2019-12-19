class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()>0&&needle.size()==0)
            return 0;
        if(haystack.size()==0&&needle.size()>0)
            return -1;
        if(haystack.size()==0&&needle.size()==0)
            return 0;
        if(needle.size()==0)
            return -1;
        if(needle.size()>haystack.size())
            return -1;
        for(int i = 0; i<haystack.size(); i++){
            int c = i;
            int j = 0;
            for(;j<needle.size(); j++){
                if(needle[j]!=haystack[c])
                    break;
                c++;
            }
            if(j==needle.size())
                return i;
        }
        return -1;
    }
};
