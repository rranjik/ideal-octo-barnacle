#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int i = w.length()-1;
    while(i>0 && w[i-1]>=w[i])
        i--;
    if(i<=0){
        return "no answer";
    }
     int j = w.length()-1;
     while(w[j]<=w[i-1])
        j--;
    
    swap(w[i-1], w[j]);

    j = w.length()-1;
    while(i<j){
        swap(w[i], w[j]);
        i++;
        j--;
    }

    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
