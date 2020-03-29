#include <iostream>
#include <cstdio>

using namespace std;

int a[100001] = { 0 };

int search(int low, int high, int target) {
	while (low < high) {
		int mid = (low + high) / 2;
		if (a[mid] > target)high = mid; 
		else low = mid + 1;
	}
	return low-1;
}

int main()
{
	int n, nowa;

	cin >> n;
	for (int i = 1; i <= n; ++i)scanf("%d", &a[i]);

	int k, b, c;
	cin >> k;

	while (k-- > 0) {
		scanf("%d%d", &b, &c);

		if (c == 0)printf("%d\n", n);
		else {
			int maxa = (b*b) / (4.0 * c);
			printf("%d\n", search(1, n, maxa)); 
		}
	}
	return 0;
}