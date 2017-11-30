class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x ^ y;
        return countBit(r);
    }
private:
    int countBit(int x) {
        int cnt = 0;
        while(x > 0) {
            x = x & (x-1);
            cnt++;
        }
        return cnt;
    }
};