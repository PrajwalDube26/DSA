class Solution {
public:
    double pow(double x, long long n)
    {
        if(n==0)
        {
            return 1;
        }

        if(n%2==1)
        {
            return x*pow(x,n-1);
        }
        else
        {
            return pow(x*x,n/2);
        }
    }
    double myPow(double x, int n)
    {
        long long N=n;
        if(n<0)
        {
            x=(double) 1/x;
            return x*pow(x,-N-1);
        }

        return pow(x,N);
    }
};