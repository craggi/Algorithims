#include <bits/stdc++.h> 
#define MAX INT_MAX
#define MIN INT_MIN 
#define ll long long int
#define for(i,s,e) for(ll i=(s);i<(e);i++)
#define  mod 1e9+7
using namespace std; 
ll partition(ll a[] ,ll l,ll r)
{
	ll x=a[r];
	ll j=l-1;
	for(i,l,r)
	{
		if(a[i]<=x)
		{
		j++;
		swap(a[j],a[i]);
		}
	}
	swap(a[j+1],a[r]);
	return j+1;
}
ll smallest_element(ll a[],ll l,ll n,ll k)
{	
if(k>0 && k<= n-l+1)
{
	ll pos=partition(a,l,n);
	if(pos-l==k-1)
	{
		return a[pos];
	}
	if(pos-l>k-1)
	{
		return smallest_element(a,l,pos-1,k);
	}
	return smallest_element(a,pos+1,n,k-pos+l-1);
}

return 0;
}
int main() 
{ 
 std::ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(i,0,n)
  	cin>>a[i];
  cout<<smallest_element(a,0,n-1,n-k+1);
  // for largest element it is k=n-k+1
} 

/*
kth largest Leetcode
*/
class Solution {
public:
    int part(vector<int>&a,int l,int r)
    {
        int j=l-1;
        for(int i=l;i<r;i++)
        {
            if(a[i]<=a[r])
            {
                j++;
                swap(a[i],a[j]);
            }
}
        swap(a[j+1],a[r]);
        return j+1;
}
    int ans(vector<int>&a,int l,int r,int k)
    {
        if(k>0 && k<=r-l+1)
        {
            int pos=part(a,l,r);
            if(pos-l==k-1)
                return a[pos];
            if(pos-l>k-1)
                return ans(a,l,pos-1,k);
            return ans(a,pos+1,r,k-pos+l-1);
}
        return -1;
    }
    int findKthLargest(vector<int>&a, int k) {
      return ans(a,0,a.size()-1,a.size()-k+1);
    }
};
