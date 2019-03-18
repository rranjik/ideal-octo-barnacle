
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <stack>
using namespace std;

int main()
{
    string cr;
    stack<std::function<void()>> stk;
    int q;
    cin>>q;
    while (q) {
        int ins;
        cin >> ins;
        switch (ins) {
            case 1: {
                string nxt;
                cin >> nxt;
                cr.append(nxt);
                auto Udelete = [&cr, nxt]() { cr = cr.substr(0, cr.length() - nxt.length()); };
                stk.push(Udelete);
            }break;
            case 2: {
                int dl;
                cin >> dl;
                string deleted = cr.substr(cr.length() - dl);
                cr = cr.substr(0, cr.length() - dl);
                auto UAppend = [&cr, deleted]() { cr.append(deleted); };
                stk.push(UAppend);
            }break;
            case 3: {
                int k;
                cin >> k;
                cout << cr[k-1] << endl;
            }break;
            case 4: {
                auto tp = stk.top();
                tp();
                stk.pop();
            }break;
        }
        q--;
    }
    //std::cout << "Hello World!\n"; 
}

