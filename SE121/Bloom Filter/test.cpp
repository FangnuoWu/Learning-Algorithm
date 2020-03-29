#include "BloomFilter.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h> 
#include <random>
#include <string>

using namespace std;

unsigned int BKDRHash(char *str);
unsigned int APHash(char *str);
unsigned int DJBHash(char *str);
unsigned int JSHash(char *str);

static uint64_t FILTER_SIZE = 100*pow(2, 20);
static uint64_t DATA_SIZE = 100*pow(2, 20);

int main()
{
	bool *cellOne1 = (bool*)malloc(sizeof(bool) * FILTER_SIZE/2);
	bool *cellOne2 = (bool*)malloc(sizeof(bool) * FILTER_SIZE/2);
	bool *cellTwo = (bool*)malloc(sizeof(bool) * FILTER_SIZE);
	for (size_t i = 0; i < FILTER_SIZE; i++)
	{
		cellTwo[i] = false;
	}
	for (size_t i = 0; i < FILTER_SIZE/2; i++)
	{
		cellOne1[i] = false;
		cellOne2[i] = false;
	}

	srand((unsigned)time(NULL));
	
	cout << "Starting bloom filter!" << endl;
	cout << "FILTER_SIZE:" << FILTER_SIZE << endl;
	cout << "DATA_SIZE:" << DATA_SIZE << endl;

	string filename = to_string(FILTER_SIZE / pow(2, 20)) + "M";
	ofstream outfile(filename+".txt", ios::out);
	if (!outfile)
	{
		cerr << "Failed to open the file!";
		return 1;
	}
	cout << "File opened" << endl;

	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, UINT32_MAX);
	char* data = new char[32];

	uint64_t errorNumberTwo = 0;
	uint64_t errorNumberOne = 0;	
	
	for (int i = 1; i <= DATA_SIZE; i++)
	{		
		_itoa_s(u(e), data, 32, 10);

		//filter two
		unsigned int hash1 = BKDRHash(data)%FILTER_SIZE;
		unsigned int hash2 = APHash(data)%FILTER_SIZE;
		unsigned int hash3 = DJBHash(data)%FILTER_SIZE;
		unsigned int hash4 = JSHash(data)%FILTER_SIZE;
		if (cellTwo[hash1] == true || cellTwo[hash2] == true || cellTwo[hash3] == true || cellTwo[hash4] == true)
			errorNumberTwo+=1;
		cellTwo[hash1] = true;
		cellTwo[hash2] = true;
		cellTwo[hash3] = true;
		cellTwo[hash4] = true;

		//filter one
		hash1 = BKDRHash(data) % (FILTER_SIZE/2);
		hash2 = APHash(data) % (FILTER_SIZE / 2);
		hash3 = DJBHash(data) % (FILTER_SIZE / 2);
		hash4 = JSHash(data) % (FILTER_SIZE / 2);
		if (cellOne1[hash1] == true || cellOne1[hash2] == true || cellOne2[hash3] == true || cellOne2[hash4] == true)
			errorNumberOne += 1;
		cellOne1[hash1] = true;
		cellOne1[hash2] = true;
		cellOne2[hash3] = true;
		cellOne2[hash4] = true;

		if(i%100==0)
			outfile << i << " " << errorNumberOne << " " << errorNumberTwo << "\n";
	
	}
	outfile.close();
	cout << "File closed" << endl;
	delete data;
	delete cellOne1;
	delete cellOne2;
	delete cellTwo;
}

unsigned int BKDRHash(char *str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

unsigned int APHash(char *str)
{
	unsigned int hash = 0;
	int i;

	for (i = 0; *str; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
		}
	}

	return (hash & 0x7FFFFFFF);
}

unsigned int DJBHash(char *str)
{
	unsigned int hash = 5381;

	while (*str)
	{
		hash += (hash << 5) + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}

unsigned int JSHash(char *str)
{
	unsigned int hash = 1315423911;

	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF);
}
