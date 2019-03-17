
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

enum class OpType{
    Append,
    Delete
};

struct Op{
    OpType type;
    string op;
    int num;

    Op(OpType _type, string _op, int _num):
    type(_type),
    op(_op),
    num(_num)
    {
    }

    void operator()(string& curr){
        switch(type){
            case OpType::Append:{
                //cout<<"undoing append on "<<curr<<" with "<<op<<endl;
                curr.append(op);
                //cout<<"after undoing append "<<curr<<endl;
            }break;
            case OpType::Delete:{
                //cout<<"undoing delete on "<<curr<<" with "<<num<<endl;
                curr = curr.substr(0, curr.length() - num);
                //cout<<"after undoing delete "<<curr<<endl;
            }break;
        }
    }
};

class Editor {
public:
  string crr;
  stack<Op> stk;
    Editor(){
        crr = string();
        stk = stack<Op>();
    }
    void Append(string str) {
        // cout<<"append called"<<endl;
        // cout<<"crr: "<<crr<<endl;
        // cout<<"op: "<<str<<endl;
        crr.append(str);
        auto undo = Op(OpType::Delete, "", str.length());
        stk.push(undo);
        // cout<<"append finished"<<endl;
        // cout<<"crr: "<<crr<<endl;
    }
    void Delete(int& num) {
    //   cout << "Delete called" << endl;
    //   cout << "crr: " << crr << endl;
    //   cout << "num: " << num<< endl;
      string deleted;
      while (num) {
        deleted.append(string(1, crr.back()));
        crr.pop_back();
        num--;
        }
        reverse(deleted.begin(), deleted.end());
        //cout<<"deleted string was "<< deleted<<endl;
        auto undo = Op(OpType::Append, deleted, -1);
        stk.push(undo);
    //   cout << "Delete finished" << endl;
    //   cout << "crr: " << crr << endl;
    }
    void Undo(){
        auto tp = stk.top();
        // if(tp.type == OpType::Append){
        //     cout<<"this is a append undo "<<endl;
        // }
        // if(tp.type == OpType::Delete){
        //     cout<<"this is a delete undo "<<"arg is "<< tp.num <<endl;
        // }
        tp(crr);
        stk.pop();
    }
    void show(const int& k)const {
      //cout << "show called" << endl;
      //cout << "crr: " << crr << endl;
      //cout << "num: " << k << endl;
      cout << crr[k - 1] << endl;
    //   cout << "show finished" << endl;
    //   cout << "crr: " << crr << endl;
    }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int q;
  cin>>q;
  Editor ed;
  while(q){
      int op;
      cin>>op;
      switch(op){
        case 1:{
            string op;
            cin>>op;
            ed.Append(op);
        }break;
        case 2:{
            int num;
            cin>>num;
            //cout << "yelo delete" << ed.crr << endl;
            ed.Delete(num);
        }break;
        case 3:{
            int k;
            cin>>k;
            ed.show(k);
            //cout<<"yelo "<<ed.crr<<endl;
        }break;
        case 4:{
          ed.Undo();
        }break;
      }
      q--;
  }
  return 0;
}
