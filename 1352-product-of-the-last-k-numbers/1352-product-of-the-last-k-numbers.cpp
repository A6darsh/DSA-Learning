class ProductOfNumbers {
    vector<int> arr;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        arr.push_back(num);
    }

    int getProduct(int k) {
        int mul = 1;
        int n = arr.size();
        for(int i = n-1; i >= n-k; i--) {
            mul *= arr[i];
        }

        return mul;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */