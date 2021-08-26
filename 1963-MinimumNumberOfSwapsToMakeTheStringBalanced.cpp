class Solution {
public:
    int minSwaps(string s) {
        int m = 0;
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            auto c = s[i];
            if(c=='['){
                st.push(c);
            }else{
                if(!st.empty()){
                    st.pop();
                }else {
                    m++;
                }
            }
        }
        return (m+1)/2;
    }
};
