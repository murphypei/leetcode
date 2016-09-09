// Count Primes

// Count the number of prime numbers less than a non-negative number, n.


class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        else if(n <= 3)
            return 1;
        
        int primes[n/2] = {0};
        
        int idx = 1;
        primes[0] = 2;
        
        int k;
        int p = 3;
        // 从3开始, 找到所有比n小的素数
        while(p < n) {
            k = 0;
            // p若不为素数，必有一个素数因子小于m，则这个因子一定在primes数组序列中
            while(primes[k] * primes[k] <= p) {
                if(p % primes[k] == 0) 
                    break;
                else
                    ++k;
            }
            
            // 如果primes中找不到p的因子, 则p是素数
            if(primes[k] * primes[k] > p)
                primes[idx++] = p;
            
            p += 2;
        }
        
        return idx;
        
    }
};