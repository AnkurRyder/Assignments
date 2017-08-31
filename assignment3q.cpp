#include <bits/stdc++.h>

using namespace std;
typedef vector<long long> vl;
typedef vector<pair<int,int> > vpii;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;


void swap(pii *a,pii *b)
{

	int t;
	t= a->second;
	a->second = b->second;
	b->second = t;
    t=a->first;
    a->first = b->first;
	b->first = t;
}

int partition (vpii &b, int low, int high,int k)
{
	int l=high;
	int pivot = b[l].second; // pivot
	int i = low-1; // Index of smaller element
	int j;
    for(int i = low; i <= high-1; i++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (b[j].second <= pivot)
		{
			 // increment index of smaller element
			i++;
			swap(&b[i], &b[j]);
		}
	}
    swap(&b[i+1],&b[high]);
	return (i+1);
}

void quickSort(vpii &b, int low, int high,int k)
{

		int pi = partition(b, low, high,k);
	if (k==pi)
	{
		return;
	}
	else if(k<pi)
    {
	return quickSort(b, low, pi-1,k);
    }
	else
	{
	return quickSort(b, pi + 1, high,k);
	}
	//	quickSort(b, pi + 1, high,k);

}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	vpii b;
	int x,k;
	cin>>x>>k;
	for(int i = 0; i < n; i++)
	{
		b.push_back(make_pair(arr[i],abs(arr[i]-x)));
	}
	int i;
	int g=k;
	quickSort(b, 0, n-1,k);
	for(int i = 0; i < k; i++)
	{
			cout<<b[i].first<<" ";

	}
	cout<<endl;
}
}
