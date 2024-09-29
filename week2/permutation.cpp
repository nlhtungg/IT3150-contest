#include <bits/stdc++.h>
using namespace std;
void Swap(int &x, int &y)
{
    int tg;
    tg = x;
    x = y;
    y = tg;
}
void khoitaocauhinhbandau(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        a[i] = i;
}
void incauhinh(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    cout << a[i] << " ";
    cout <<endl;
}
void sapxeptang (int a[], int n, int vt)
{
    for (int i = vt; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (a[i] > a[j])
                Swap(a[i],a[j]);
        }
    }
}   
int main() 
{
    int a[100];
    int n; cin >> n;
    khoitaocauhinhbandau(a,n);
    incauhinh(a, n);
    while(true)
    {
        int i;
        for (i =n; i > 0; i--)
        {
            if (i==1)
                return 0;
            if (a[i-1] < a[i])
                break;
        }
        for (int j =n; j >= i; j--)
        {
            if (a[j] > a[i-1])
            {
                Swap(a[j],a[i-1]);
                sapxeptang(a, n, i);
                incauhinh(a, n);
                break;
            }
        }
    }
}