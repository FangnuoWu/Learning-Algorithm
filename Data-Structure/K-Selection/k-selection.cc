#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <array>
#include <chrono>  

#define Q 5
#define LEN 1000000
int L[LEN/2];
int G[LEN/2];
int E[100];
int median[1+LEN/5];
using namespace std;

int quickSelect(vector<int> A, size_t k) {
	for (size_t lo = 0, hi = A.size() - 1; lo < hi;) {
		size_t i = lo, j = hi;
		int pivot = A[lo];
		while (i < j) {
			while (i < j && pivot <= A[j])j--;
			A[i] = A[j];
			while (i < j && A[i] <= pivot)i++;
			A[j] = A[i];
		}
		A[i] = pivot;
		if (k <= i)hi = i - 1;
		if (i <= k)lo = i + 1;
	}
	return A[k];
}

/* 数组规模不大时蛮力求第k大的数 */
int trivialSelect(int* A, size_t n, size_t k) {
	sort(A, A + n);
	return A[k - 1];
}

/* 寻找乱序数组的中位数 */
int findMedian(int* A, size_t n){
	sort(A, A + n);
	return A[n/2];
}

/* linearSelect：寻找乱序数组中第k大的值， n为数组长度 */
int linearSelect(int* A, size_t k, size_t n) {
	/* 递归基，数组规模不大时蛮力求第k大的数 */
	if (n <= Q)return trivialSelect(A, k, n);

	size_t i;
	for (i = 0; i < n / Q; i++) /* 将A均匀划分为 n/Q 个子序列 */
		median[i] = findMedian(A + i * Q, Q); /* 寻找该序列中位数并计入median */
	if (i * Q < n) /* 对最后不满Q的数组 */
		median[i] = findMedian(A + i * Q, n % Q);
	int medOfMed = findMedian(median, (n + 4) / Q); /* 寻找中位数的中位数 */

	/* 根据相对medofMed的大小，将A中元素划分为三个子集 */
	int l = 0, e = 0, g = 0; /* 记录三个子集的大小，子集数组为全局变量 */
	for (size_t i = 0; i < n; ++i) {
		if (A[i] < medOfMed) {L[l] = A[i]; l++;}
		else if (A[i] > medOfMed) {G[g] = A[i]; g++;}
		else {E[e] = A[i]; e++;}
	}
	/* L足够长，第k个元素与子序列E、G的存在与否无关，将其剪除在L中做选择 */
	if (l >= k) return linearSelect(L, k, l); 
	/* L<k，加入E后可以覆盖k，E中每个元素必然都是要寻找的对象，直接返回 medOfMed */
	else if (l + e >= k) return medOfMed;
	/* L和E长度总和仍不够长，第k个元素必然在G中且应该位于第 k-l-e 个 */
	else return linearSelect(G, k - l - e, g);
}

int main()
{
	//default_random_engine e;
	//uniform_int_distribution<unsigned> u(0, INT_MAX);

	int A[LEN];
	for (size_t i = 0; i < LEN; i++)
	{
		A[i] = rand();
	}
	auto start = chrono::system_clock::now();

	int res = linearSelect(A, 100, LEN);

	auto end = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "答案是 " << res <<
		" 花费了 "
		<< double(duration.count()) * chrono::microseconds::period::num / chrono::microseconds::period::den;
}