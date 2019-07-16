class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r){
            cout<<"l ="<<l<<" r = "<<r<<endl;
            cout<<"area = "<<area<<endl;
            area = max(area, ((r-l)*min(height[l], height[r])));
            if(height[l]< height[r])
                l+=1;
            else
                r-=1;
        }
        return area;
    }
};
