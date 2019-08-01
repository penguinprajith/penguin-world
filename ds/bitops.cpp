
#include <iostream>
#include "bitops.h"



int last1bit(int x)
{
	return x & -x;	
}

void printbinary(int x)
{
	int mask = 1 << 31;
	for(int count = 1; count < 33; ++count)
	{
		(x & mask) ? putchar('1'):putchar('0');
		x = x << 1; 	
		if(count %4 == 0)
			std::cout << " ";
	}
	std::cout << std::endl;	
	
}

int bitreverse(int x)
{
	x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
	x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;
	x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
	
	return x;
}

int paritycount(int x)
{
	int count = 0;
	int v = x;
	while(v)
	{
		count++;
		v = v & v-1;
	}
	return count;	
}

int onecount(int x)
{
	return paritycount(x);
}

int zerocount(int x)
{
	return (sizeof(x)*8) - onecount(x);	
}

int abs(int x)
{
	x = (x ^ (x >> 31)) - (x >> 31);	
	return x;
}

char toupper(char ch)
{
	//check the range [a-z]

	if (ch >= 'a' && ch <= 'z')
	{
		if (ch & 0x20)
			ch = ch & 0xDF;
	}

	return ch;
}

char tolower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		if (!(ch & 0x20))
			ch = ch | 0x20;
	}
	
	return ch;
}

int bin2gray(int c)
{
	int nbits = sizeof(c) * 8;
	int result = 0;

	for (int i = 0; i < nbits; i++)
	{
		result = result | (((_getbit(c, i) >> i) ^ (_getbit(c, i + 1) >> (i + 1))) << i);
	}

	return result;
}
