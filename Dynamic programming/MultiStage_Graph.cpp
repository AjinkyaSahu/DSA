#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
int main()
{
    int stages = 4, min, n = 8, cost[9], d[9], path[stages];
    int c[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 0, 6, 7, 0, 0},
        {0, 0, 0, 0, 0, 6, 8, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    cost[n] = 0;
    for(int i=n-1; i>=0; i--)
    {
        min = INT_MAX;
        for(int k= i+1; k<=n; k++)
        {
            if(c[i][k] != 0 and (c[i][k] + cost[k]) < min)
            {
                min = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }

    path[1] = 1;
    path[stages] = n;
    for(int i=2; i<=stages-1; i++)
    {
        path[i] = d[path[i-1]];
    }

    for(int i=1; i<stages; i++)
    {
        cout<<path[i]<<"->";
    }
    cout<<path[4];
    return 0;
}