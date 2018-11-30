#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    vector<string> cpy;
    cpy.push_back(grid.at(0));
    for(auto i = grid.begin()+1; i< grid.end()-1; i++)
    {
        string input;
        input.push_back(i->at(0));
        auto count =1;
        for (auto c = i->begin() + 1; c < i->end() - 1; c++, count++) {
          int d = (int)(*c);
          int up = (int)((i - 1)->at(count));
          int down = (int)((i + 1)->at(count));
          int left = (int)((i)->at(count-1));
          int right = (int)((i)->at(count + 1));
          if(d>up && d>down && d>left && d>right)
          {
            input.push_back('X');
          }
          else
          {
            input.push_back(*c);
          }
        }
        input.push_back(i->at(count));
        cpy.push_back(input);
    }
    if (grid.size()!=1)
      cpy.push_back(grid.at(grid.size() - 1));
    return cpy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
