/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        stack<char> numstk;
        stack<char> opstk;
        for(int i = 0; i<s.size(); i++){
            if('0'<=s[i]&&'9'>=s[i]){
                numstk.push(s[i]);
            }else if(s[i]=='*'){
                while(!opstk.empty()&&(opstk.top()=='/'||opstk.top()=='*')){
                    numstk.push(opstk.top());
                    opstk.pop();
                }
                opstk.push('*');
            }else if(s[i]=='/'){
                while(!opstk.empty()&&(opstk.top()=='*'||opstk.top()=='/')){
                    numstk.push(opstk.top());
                    opstk.pop();
                }
                opstk.push('/');
            }else if(s[i]=='+'){
                while(!opstk.empty()&&
                      (opstk.top()=='+'||opstk.top()=='*'||opstk.top()=='-'||opstk.top()=='/')){
                    numstk.push(opstk.top());
                    opstk.pop();
                }
                opstk.push('+');
            }else if(s[i]=='-'){
                while(!opstk.empty()&&
                      (opstk.top()=='+'||opstk.top()=='*'||opstk.top()=='-'||opstk.top()=='/')){
                    numstk.push(opstk.top());
                    opstk.pop();
                }
                opstk.push('-');
            }else if(s[i]=='('){
                opstk.push('(');
            }else if(s[i]==')'){
                while(opstk.top()!='('){
                    numstk.push(opstk.top());
                    opstk.pop();
                }
                opstk.pop();
            }
        }
        while(!opstk.empty()){
            numstk.push(opstk.top());
            opstk.pop();
        }
        string prefix;
        while(!numstk.empty()){
            prefix += numstk.top();
            numstk.pop();
        }
        reverse(prefix.begin(), prefix.end());
        cout<<prefix<<endl;
        Node* root = nullptr;
        stack<Node*> nstk;
        //eval stack
        stack<char> estk;
        for(int i = 0; i<prefix.size(); i++){
            if(prefix[i]=='/'||prefix[i]=='*'||prefix[i]=='+'||prefix[i]=='-'){
                auto mnode = new Node(prefix[i]);
                mnode->right = nstk.top();
                nstk.pop();
                mnode->left = nstk.top();
                nstk.pop();
                nstk.push(mnode);
            }else{
                auto nnode = new Node(prefix[i]);
                nstk.push(nnode);
            }
        }
        return nstk.top();
    }
};
