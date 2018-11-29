#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int errors = 0;
    int num_of_messages = s.length()/3;
    char correct_char = 'S';
    int counter = 0;
    for(const auto& c:s)
    {
        if(c!=correct_char)
            errors++;
        if(counter == 0)
        {
          correct_char = 'O';
          counter = 1;
        }
        else if(counter == 1)
        {
          correct_char = 'S';
          counter = 2;
        } 
        else if (counter == 2) {
          correct_char = 'S';
          counter = 0;
        }
    }
    return errors;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
