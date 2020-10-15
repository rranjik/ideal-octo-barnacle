class Solution {
public:
    int compress(vector<char>& chars) {
        int pivot = 0;
        int write = 0;
        for(int r = 0; r<chars.size(); r++){
            if(r+1 == chars.size()||chars[r+1]!=chars[r]){
                chars[write] = chars[pivot];
                write++;
                if(r-pivot>0){
                    for(const auto& c :
                        to_string(static_cast<int>(r-pivot+1))){
                        chars[write] = c;
                        write++;
                    }
                }
                pivot = r+1;
            }
        }
        chars.erase(chars.begin()+write, chars.end());
        return write;
    }
};
