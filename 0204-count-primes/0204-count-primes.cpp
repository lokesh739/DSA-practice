class Solution {
public:
  int countPrimes(int n) {
    int count=0;
    if(n<=2) return 0;
    int primes[n+1];
    for(int i=2;i<=n;i++){
        primes[i]=1;
    }
    for(int i=2;i*i<=n;i++){
        if(primes[i]==1){
            for(int j=i*i;j<=n;j+=i){
                primes[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(primes[i]==1){
            count++;
        }
    }
    return count;
    }
};