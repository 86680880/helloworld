#include<iostream>
using namespace std;
int sequential(int arr[], int len, int key)
{
	for (int i = 0;i < len;i++)
	{
		if (arr[i] == key)
			return i;
	}
}

int main()
{
	int arr[] = { 1,2,4,6,8,10,13,14,17,20 }, a;
	cin >> a;
	int k = sequential(arr, sizeof(arr), a);
	if (k == -1)
	{
		cout << "j=0" << endl;
	}
	else
	{
		cout << "该数字的下标为：" << k << endl;
	}

}