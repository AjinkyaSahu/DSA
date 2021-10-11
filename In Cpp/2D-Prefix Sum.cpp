/*
An Implementation Of 2-D Prefix Sum and suffix sum.
To find the minimum no of operation required for making a submatrix of (rows >= 5 and columns >= 4) a good submatrix in a binary matrix(only 0 and 1), Where a good submatrix is a matrix :

whose edges should always be 1
corners can be anything
Inside all the cells should be 0.
And an operation is of type :
1 operation is counted if we convert a 0 to 1 or vice versa.

Sample Input:
9 9
001010001
101110100
000010011
100000001
101010101
110001111
000001111
111100000
000110000

Sample Output:
5

*/
#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define V vector
#define INF LLONG_MAX

using namespace std;

int main(){
    //Fast input otput
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // n -> no of rows, m -> no of colums.
    ll n, m;
    cin >> n >> m;
    string s[n];
    // binary matrix.
    ll a[n][m];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++)
            a[i][j] = s[i][j]-'0';
    }
    // psum is the 2d prefix sum of the binary matrix which stores the minimum no of operations required to make the cell 1 to 0.
    // rsum is the 1d prefix sum of each row similarly ssum.
    V<V<ll>> psum(n, V<ll>(m,0)), rsum(n, V<ll>(m,0)), csum(n, V<ll>(m,0));
    // here we are making 2d prefix sum.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            // prefix[i][j] means the sum of the matrix from (1,1) to (i,j);
            if(i == 0 && j == 0)    psum[i][j] = a[i][j];
            else if(i == 0) psum[i][j] = psum[i][j-1]+a[i][j];
            else if(j == 0) psum[i][j] = psum[i-1][j]+a[i][j];
            else
                psum[i][j] = psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1]+a[i][j]; // As the matrix (1,1) to (i,j) is repeated twice we subtract it here.
        }
    // 1d prefix row sum matrix for n rows.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(j)    rsum[i][j] = rsum[i][j-1];
            if(!a[i][j])    rsum[i][j]++;
        }
    // 1d prefix column sum matrix for n rows.
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            if(j) csum[j][i] = csum[j-1][i];
            if(!a[j][i])    csum[j][i]++;
        }
    ll res = INF;
    for(int r1 = 0; r1 < n; r1++){
        for(int r2 = r1+4; r2 < n; r2++){
            // in the above loops we are keeping the up and down boundaries using r1 and r2 and the least distance between then should be 4 i.e length 5 including r1.
            // each i in v stores the minimum no of operations required to make the matrix (r1,1), (r2,i) a goodsubmatrix which is calculated sum of:
            // 1. prefix sum of matrix (r1+1,1) to (r2-1, i) i.e, to convert 0 to 1.
            // 2. sum of edges i.e, to convert 1 to 0.
            V<ll> v(m,0), suf(m,INF);
            for(int i = 0; i < m; i++){
                if(i) v[i] = psum[r2-1][i-1]-psum[r1][i-1];
                if(i) v[i] += rsum[r1][i-1]+rsum[r2][i-1];
                v[i] += csum[r2-1][i]-csum[r1][i];
            }
            // suf is the minimum suffix vector of v.
            for(int i = m-1; i >= 0; i--){
                if(i == m-1)    suf[i] = v[i];
                else    suf[i] = min(suf[i+1], v[i]);
            }
            //Here for each i we are taking the minimum no of operation required for matrix whose column > i using suf.
            //c is the minimum operation required for making matrix (r1,1), (r1,i) a good submatrix.
            for(int i = 0; i < m-3; i++){
                ll c = psum[r2-1][i]-psum[r1][i]+rsum[r1][i]+rsum[r2][i];
                ll val = suf[i+3]-c;
                // no the operation required to make the matrix left edge ending at i a goodedge(edge of goodsubmatrix).
                val += csum[r2-1][i]-csum[r1][i];
                res = min(res, val);
            }
        }
    }
    cout << res << endl;
    return 0;
}
// Time Complexity : O(n*n*m).
