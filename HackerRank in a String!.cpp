#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string copy = s;
    const std::string pattern = "hackerrank";
    bool found = true;
    for(const auto& p:pattern)
    {
        if(string::npos!=copy.find_first_of(p))
        {
            copy = std::string(copy.begin()+copy.find_first_of(p)+1, copy.end());
            std::cout<<"copy is: "<<copy<<endl;
        }
        else
        {
            found = false;
            break;
        }
    }
    return (found)?"YES": "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
