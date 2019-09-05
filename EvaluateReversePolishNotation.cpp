class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        
        for(const auto& t : tokens){
            //cout<<"processing: "<<t<<endl;    
                if(t == "+"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    //cout<<"op1: "<<op1<<"op2: "<<op2<<" +"<<endl;
                    st.push(op1+op2);
                }
                else if(t == "-"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    //cout<<"op1: "<<op1<<"op2: "<<op2<<" -"<<endl;
                    st.push(op2-op1);
                }
                else if(t == "*"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    //cout<<"op1: "<<op1<<"op2: "<<op2<<" *"<<endl;
                    st.push(op1*op2);
                }
                else if(t == "/"){
                    int op1 = st.top();
                    st.pop();
                    int op2 = st.top();
                    st.pop();
                    //cout<<"op1: "<<op1<<"op2: "<<op2<<" /"<<endl;
                    int res = op2/op1;
                    st.push(res);
                }
                else {
                    int op = stoi(t);
                    //cout<<"just pushing: "<<op<<endl;
                    st.push(op);
                }
            }
        return st.top();
        }
};
