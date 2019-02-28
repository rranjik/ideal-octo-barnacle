
#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> stk;
    for(auto& c : s){
        if(c == '{'||c == '['||c == '(')
            stk.push(c);
        else{
            if(stk.empty()){
                return "NO";
            }
            else{
                char tp = stk.top();
                switch(tp){
                    case '[':{
                        if(c!=']')
                            return "NO";
                        else{
                            stk.pop();
                            break;
                        }
                    }
                    case '{':{
                        if(c!='}')
                            return "NO";
                        else{
                            stk.pop();
                            break;
                        }
                    }
                    case '(':{
                        if(c!=')')
                            return "NO";
                        else{
                            stk.pop();
                            break;
                        }
                    }
                    default: 
                        return "NO";
                }
            }
        }
    }
    if(stk.empty())
        return "YES";
    else 
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
