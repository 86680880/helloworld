#include<iostream>
using namespace std;

int binary(int arr[], int len, int key)
{//���ֲ���
	int l = 0, r = len, m = 0;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (key < arr[m])
		{
			r = m - 1;
		}
		else if (key > arr[m])
		{
			l = m + 1;
		}
		else
		{
			return m;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,4,6,8,10,13,14,17,20 };
	int len = size(arr), a;
	cin >> a;
	int j = binary(arr, len - 1, a);
	if (j >= 0)
	{
		cout << "�����ֵ��±�Ϊ��" << j << endl;
	}
	else
	{
		cout << "j=0" << endl;
	}
}