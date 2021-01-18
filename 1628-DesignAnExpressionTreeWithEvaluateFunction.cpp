/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    
};

enum class opType{
    add, subtract, mult, div, none
};

struct Op{
    int operator()(opType opt, int a, int b){
        if(opt==opType::add){
            return a+b;
        }else if (opt==opType::subtract){
            return a-b;
        }else if (opt==opType::mult){
            return a*b;
        }else if (opt==opType::div){
            return a/b;
        }
        return 0;
    }
};

class ENode : public Node{
public:
    ENode* left;
    ENode* right;
    opType opt{opType::none};
    int val;
    int evaluate() const override{
        if(opt==opType::none) return val;
        return Op()(opt, left->evaluate(), right->evaluate());
    }
    ENode(int v):val(v){}
    ENode(opType op):opt(op){}
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<ENode*> stk;
        for(int i = 0; i<postfix.size(); i++){
            if(postfix[i]=="+"){
                auto right = stk.top(); stk.pop();
                auto left = stk.top(); stk.pop();
                auto nn = new ENode(opType::add);
                nn->left = left;
                nn->right = right;
                stk.push(nn);
            }
            else if(postfix[i]=="-"){
                auto right = stk.top(); stk.pop();
                auto left = stk.top(); stk.pop();
                auto nn = new ENode(opType::subtract);
                nn->left = left;
                nn->right = right;
                stk.push(nn);
            }
            else if(postfix[i]=="*"){
                auto right = stk.top(); stk.pop();
                auto left = stk.top(); stk.pop();
                auto nn = new ENode(opType::mult);
                nn->left = left;
                nn->right = right;
                stk.push(nn);
            }
            else if(postfix[i]=="/"){
                auto right = stk.top(); stk.pop();
                auto left = stk.top(); stk.pop();
                auto nn = new ENode(opType::div);
                nn->left = left;
                nn->right = right;
                stk.push(nn);
            }
            else{
                auto nn = new ENode(stoi(postfix[i]));
                stk.push(nn);
            }
        }
        return stk.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
