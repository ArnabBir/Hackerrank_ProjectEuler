#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int triangle_number(int n){
    return ((n * (n+1))/2);
}

int count_divisor(int n){
    int count = 1;
    if (n == 1) return 1;
    if(n == 2) return 2;
    for(int i = 2;i <= sqrt(n); ++i){
        if(n % i == 0 && i == n / i) ++count;
        if(n % i == 0 && i != n / i) count += 2;
    }
    return (count + 1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,N;
    cin>>T;
    
    while(T--){
        cin>>N;
        int i;
        if(N == 1) i = 2;
        else
            for ( i = 2; count_divisor(triangle_number(i)) <= N; ++i){/*cout<<count_divisor(triangle_number(i))<<endl;*/}
        cout<<triangle_number(i)<<endl;
    }
    return 0;
}