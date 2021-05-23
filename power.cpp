int power(int base, int n,int M) 
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    int halfn=power(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
