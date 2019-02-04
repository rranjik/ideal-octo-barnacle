#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string res;
    int rows = ceil(sqrt(s.length()));
    int columns = (rows>=sqrt(s.length()))?(rows):(rows+1);
    cout<<"rows: "<<rows<<" columns: "<<columns<<endl;
    for(int c = 0; c<columns; c++){
        for(int r=c; r<=s.length()-1; r+=columns) 
            res+=string(1, s[r]); 
        res+=" ";
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
