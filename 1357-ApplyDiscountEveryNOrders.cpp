class Cashier {
public:
    unordered_map<int, int> m;
    int k = 1;
    int roll{};
    int d{};
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        roll = n;
        for(int i = 0; i<products.size(); i++){
            m[products[i]] = prices[i];
        }
        d = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res{};
        for(int i = 0; i<product.size(); i++){
            res+=(m[product[i]]*amount[i]);
        }
        if(k==roll){
            k = 0;
            res = res - (d*res)/100;
        }
        k++;
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
