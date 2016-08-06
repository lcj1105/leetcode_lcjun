class Solution {
public:
    bool isPowerOfThree(int n) {
        double logAns = log10(n) / log10(3);
        return (logAns - int(logAns) == 0) ? true : false;
    }
};