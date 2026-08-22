class Solution {
public:
    bool checkDivisibility(int n) {
        int k = 0;
        int pus = 0;
        int prod = 1;
        int n1=n;
        while (n != 0) {
            pus += n % 10;
            prod *= n % 10;
            n /= 10;
        }
        k = pus + prod;
        return (n1 % k == 0) ? true : false;
    }
};