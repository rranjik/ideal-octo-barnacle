class Solution {
public:
    string largestMerge(string a, string b) {
        if(!a.size()||!b.size()) return a+b;
        if(a<b) return b[0]+largestMerge(a, b.substr(1));
        return a[0]+largestMerge(a.substr(1), b);
    }
};
