
#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    long long int res = 0;
    long long int factor = 1;
    for(int i = n.length()-1; i>=0; i--){
        res = (res+((n[i]-'0')*factor*(i+1)))%(1000000007);
        factor = ((factor*10)+1)%(1000000007);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
