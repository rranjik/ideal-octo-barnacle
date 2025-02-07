class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        stack<int> t;
        for(const auto& c : s){
            if(c=='('){
                if(t.empty()||t.top()==2){
                    //first (
                    t.push(2);//set expectation
                }else{
                    //1 on top already (means looking for a ')')
                    t.pop();res++;//add the missing ) manually
                    t.push(2); //set expectation for current (
                }
            }else{
                if(t.empty()){
                    //loner
                    t.push(1);//set expectation for another )
                    res++; //for the missing (
                }else if(t.top()==1){
                    t.pop();//proper match!
                }else{
                    //2 on top; already expecting two )
                    //and here's one right now
                    t.pop();
                    t.push(1);
                }
            }
        }
        while(!t.empty()){
            res+=t.top();
            t.pop();
        }
        return res;
    }
};
