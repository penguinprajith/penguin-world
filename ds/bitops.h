#ifndef BITOPS_H
#define BITOPS_H

//macros to set,reset and toggle bits
#define _setbit(x,bitno) 	(x |= (1<< bitno))
#define _resetbit(x,bitno)	(x &= ~(1<< bitno))
#define _togglebit(x,bitno)	(x ^= (1<< bitno))

//to determine whether the give number is power of 2
#define _ispower2(x)		((x & (x-1)) == 0)

//simple xor logic to determine number equivalence
#define _isequal(x,y)		((x ^ y) == 0)	

#define _getbit(x,bitno)	( x & (1 << bitno))


//set n bits of a variable x starting from index i to a given value b(0/1)
// 'i' is the index
// 'n' is number of bits
// 'b' is bitvalue (0 or 1)
// 'x' is the variable
// This can be used when the data in the memory location is not known and we
// need to set/reset the bits forcefully

#define _mask(i,n)			(((1<<n)-1) << i) 
#define _resetx(x,i,n)		( (x & _mask(i,n)) ^ x )
#define _setx(x,i,n)		( (_resetx(x,i,n) ^ _mask(i,n)) )
#define _if(x,i,n,b)		( (((b << 31)>>31) & _setx(x,i,n)) | \
							(((!b << 31)>>31) & _resetx(x,i,n)))


#define _setvalue(x,i,n,b)	(x = (_if(x,i,n,b)))

#define _extractbits(x,i,n) ( x & _mask(i,n))

#define _swapn(x)	( ((x & 0x0F) << 4) | ((x & 0xF0) >> 4) )
#define _swapb(x)	( ((x & 0x00FF) << 8) | ((x & 0xFF00) >> 8) )
#define _swapw(x)	( ((x & 0x000000FF) << 24) | ((x & 0xFF000000) >> 24) | ((x & 0x0000FF00) << 8) | ((x & 0x00FF0000) >> 8) )


int last1bit(int x);
void printbinary(int x);
int bitreverse(int x);
int paritycount(int x);
int onecount(int x);
int zerocount(int x);
int abs(int x);
char toupper(char ch);
char tolower(char ch);
int bin2gray(int);


#endif

