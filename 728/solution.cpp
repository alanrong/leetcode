class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i = left; i <= right; i++) {
            if (isDivid(i)) {
                v.push_back(i);
            }
        }   
        return v;
    }
private:
    bool isDivid(int n) {
        int m = n;
        vector<int> v;
        while(n > 0) {
            int r = n%10;
            if (r == 0) {
                return false;
            }
            v.push_back(r);
            n = n/10;
        }
        for(int i = 0; i < v.size(); i++) {
            if (m % v[i] != 0) {
                return false;
            }
        }
        return true;
    }
};