/* A c++11 version 
 * use a lot of vector so the linear select is very slow
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <chrono>  

#define Q 5

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

int trivialSelect(vector<int> A, size_t k) {
	sort(A.begin(), A.end());
	return A[k - 1];
}

int findMedian(vector<int> A)
{
	sort(A.begin(), A.end());
	return A[A.size() / 2];
}

int linearSelect(vector<int> A, size_t k) {
	size_t n = A.size();
	if (n <= Q)return trivialSelect(A, k);

	vector<int> median((n + 4) / Q);
	size_t i;
	for (i = 0; i < n / Q; i++)
		median[i] = findMedian(vector<int>(A.begin() + i * Q, A.begin() + i * Q + Q));
	if (i * Q < n) //For last group with less than 5 elements 
		median[i] = findMedian(vector<int>(A.begin() + i * Q, A.end()));
	int medOfMed = findMedian(median);

	vector<int> L, E, G;
	for (auto c : A) {
		if (c > medOfMed)G.push_back(c);
		else if (c < medOfMed)L.push_back(c);
		else E.push_back(c);
	}

	if (L.size() >= k) return linearSelect(L, k);
	else if (L.size() + E.size() >= k) return medOfMed;
	else return linearSelect(G, k - L.size() - E.size());
}

int main()
{
	vector<int>A;
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, INT_MAX);
	for (size_t i = 0; i < 1000000; i++)
	{
		A.push_back(rand());
	}
	auto start = chrono::system_clock::now();
	int res = linearSelect(A, 100);
	auto end = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "答案是 " << res <<
		" 花费了 "
		<< double(duration.count()) * chrono::microseconds::period::num / chrono::microseconds::period::den;
}