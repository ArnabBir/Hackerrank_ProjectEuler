#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void min_edit( int * min_sum, int sum, int K){
        //cout<<"Hello!"<<endl;
        for (int k = 0; k < K; ++k){
            if(min_sum[k] > sum){
                for (int l = k; l < K; ++l){
                    swap(min_sum[l], sum);
                }
            }
        }
}

void min_subtriangle(int * min_sum, int * a, int row, int col, int N, int K){
    //cout<<"Hello!"<<endl;
    //int sum = a[(row * (row + 1)) / 2 + col];
    int sum = 0;
    cout<<"sum0 = "<<sum<<endl;
    for (int i = row ,temp = 1; i < N; ++i, ++temp){
        for (int j = col; (j < N) && (j < (col + 2 * temp)); ++j ){
            sum += a[(i * (i + 1)) / 2 + j];
        }
        //sum -= a[(row * (row + 1)) / 2 + col];
        min_edit(min_sum, sum, K);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,K;
    cin>>N>>K;
    int * a = new int [(N * (N + 1)) /2 ];
    for (int i = 0; i < N; ++i){
         //a[i] = new int [i];
         for (int j = 0; j <= i; ++j){
             cin>>a[(i * (i + 1)) / 2 + j];
         }
    }
    int * min_sum = new int[K];
    for (int k = 0; k < K; ++k)
        min_sum[k] = 2147483647;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= i; ++j){
            min_subtriangle(min_sum, a, i, j, N, K);
            //if(i == 0 && j ==0) sort(a, a + K);
        }
    }
    for (int k = 0; k < K; ++k) cout<<min_sum[k]<<endl;
    return 0;
}
