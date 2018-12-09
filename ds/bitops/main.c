
#include "bitops.h"
#include <stdio.h>

//compiled with gcc version 7.3.0

//Driver code to test binary operation

int main(int argc, char** argv)
{

	unsigned int test_bits_1 = 0x55AA55AA;
	unsigned int test_bits_2 = 0x55AA55AA;
	
	
	//20th bit is set. Expected Result: 0x55BA55AA 
	printf("%x\n", _setbit(test_bits_1,20));
	//12th bit is reset. Expected Result: 0x55BA45AA
	printf("%x\n", _resetbit(test_bits_1,12));
	//25th bit is toggled. Expected Result: 0x57BA45AA
	printf("%x\n", _togglebit(test_bits_1,25));	

	
	//Starting from bit 5, set next 10 bits to a value 0
	//Expected Result: 0x55AA000A
	printf("%x\n", _setvalue(test_bits_2,5,10,0));

	//Expected Result: 0x55ABFFFE
	printf("%x\n", _setvalue(test_bits_2,2,15,1));
	
	//Expected Result: 1 i.e true
	printf("%x\n", _ispower2((1 << 12)));
	
	//Expected Result: 0 i.e false
	printf("%x\n", _ispower2(50));

	//Expected Result: 0 i.e false
	printf("%x\n", _isequal(50,36));

	//Expected Result: 1 i.e true
	printf("%x\n", _isequal(36,36));

	return 0;
}
