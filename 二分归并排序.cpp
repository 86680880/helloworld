#include<iostream>
using namespace std;
#define maxn 999
int a[maxn], temp[maxn];
void sort(int left, int right)
{
	if (left == right) return;

	int mid = (left + right) / 2;
	sort(left, mid);
	sort(mid + 1, right);
	int p = left, i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (a[i] > a[j])
			temp[p++] = a[j++];
		else
			temp[p++] = a[i++];
	}
	while (i <= mid)
		temp[p++] = a[i++];
	while (j <= right)
		temp[p++] = a[j++];
	for (int k = left;k <= right;k++)
	{
		a[k] = temp[k];
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(1, n);
	for (int i = 1;i <= n;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}