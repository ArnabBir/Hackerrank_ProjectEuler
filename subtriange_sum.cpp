#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void min_edit( int * min_sum, int sum, int K){
        for (int k = 0; k < K; ++k){
            if(min_sum[k] > sum){
                for (int l = k; l < K; ++l){
                    swap(min_sum[l], sum);
                }
            }
        }
}

void min_subtriangle(int * min_sum, int ** a, int row, int col, int N, int K){
    int sum = a[row][col];
    for (int i = row + 1 ,temp = 1; i < N; ++i, ++temp){
        for (int j = col; (j < N) && (j < (col + 2 * temp)); ++j ){
            sum += a[i][j];
        }
        min_edit(min_sum, sum, K);
    }
}

int main() {
    int N,K;
    cin>>N>>K;
    int ** a = new int *[N];
    for (int i = 0; i < N; ++i){
         a[i] = new int [i];
         for (int j = 0; j <= i; ++j){
             cin>>a[i][j];
         }
    }
    int * min_sum = new int[K];
    for (int k = 0; k < K; ++k)
        min_sum[k] = 999999;
    for (int i = 0; i < N; ++i){
        bool flag = false;
        for (int j = 0; j <= i; ++j){
            min_subtriangle(min_sum, a, i, j, N, K);
            if(i == 0 && j ==0) sort(a, a + K);
        }
    }
    for (int k = 0; k < K; ++k) cout<<min_sum[k]<<endl;
    return 0;
}
