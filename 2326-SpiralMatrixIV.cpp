/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<int, int> getNext(int x, int y, int m, int n, int& dx, int& dy){
        map<pair<int, int>, pair<int, int>> d = {
            {{0, 1}, {1, 0}},
            {{1, 0}, {0, -1}},
            {{0, -1}, {-1, 0}},
            {{-1, 0}, {0, 1}},
        };
        int xx = x+dx; int yy = y+dy;
        //cout<<xx<<", "<<yy<<endl;
        if(xx>=0&&xx<m&&yy>=0&&yy<n&&s.find({xx, yy})==s.end()){
            //cout<<"okay"<<endl;
            return {xx, yy};
        }
        auto [ndx, ndy] = d[{dx, dy}];
        dx = ndx; dy = ndy;
        return {x+dx, y+dy};
    }
    set<pair<int, int>> s;
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v = vector<vector<int>>(m, vector<int>(n, -1));
        int x = 0; int y = -1;
        int dx = 0; int dy = 1;
        while(head){
            auto c = head->val;
            head = head->next;
            auto l = getNext(x, y, m, n, dx, dy);
            s.insert(l);
            x = l.first; y = l.second;
            v[l.first][l.second] = c;
        }
        return v;
    }
};
