class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        pair<int, int> p1;
        pair<int, int> p2;
        pair<int, int> p3;
        p1.first = points[0][0];
        p1.second = points[0][1];
        p2.first = points[1][0];
        p2.second = points[1][1];
        p3.first = points[2][0];
        p3.second = points[2][1];
        if(p1==p2||p2==p3||p3==p1) return false;
        double s1 = ((p2.second-p1.second)*1.0)/((p2.first-p1.first)*1.0);
        double s2 = ((p3.second-p2.second)*1.0)/((p3.first-p2.first)*1.0);
        cout<<"s1= "<<s1<<"; s2 = "<<s2<<endl;
        return s1!=s2;
    }
};
