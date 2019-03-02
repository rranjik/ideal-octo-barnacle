
#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    int n1 = 1;
    int n2 = 2;
    int n3 = 4;
    if(n == 1){
        return n1;
    }
    else if(n==2){
        return n2;
    }
    else if(n==3){
        return n3;
    }
    else{
        int ans =0;
        for(int i=4; i<=n; i++){
          ans = ((n3 + n2 + n1)%10000000007);
          n1 = n2 % 10000000007;
          n2 = n3 % 10000000007;
          n3 = ans % 10000000007;
        }
        return ans % 10000000007;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
