class Solution {
public:
    double myPow(double x, long long n) {
        if(x==0 || x==1) return x;
        if(n<0) return myPow(1/x,-n);
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0) return myPow(x*x,n/2);
        if(n%2==1) return x*myPow(x*x,n/2);

        return 0;
    }
};