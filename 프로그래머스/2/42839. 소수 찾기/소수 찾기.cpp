#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;
    
    for (int i=2; i*i<=num; ++i) {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    set<int> primes;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int l=1; l<=numbers.size(); ++l) {
            int num = stoi(numbers.substr(0, l));
                
            if (isPrime(num)) {
               primes.insert(num); 
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return primes.size();
}