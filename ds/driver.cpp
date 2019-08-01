
#include <cstdio>
#include <iostream>
#include "driver.h"
#include "slist.h"
#include "bitops.h"

void drv_single_linked_list(void)
{
	link root = 0;
	push_front(&root,-10);
	push_front(&root,-20);
	push_front(&root,-30);
	push_front(&root,-40);
	push_back(&root, 0);
	push_back(&root, 10);
	push_back(&root, 20);
	push_back(&root, 30);
	recursive_push_back(&root, 40);

	printList(root);

	root = recursive_delete(root);

	printList(root);

	push_front(&root, -10);
	push_front(&root, -20);
	push_front(&root, -30);
	push_front(&root, -40);

	push_back(&root, 0);
	push_back(&root, 20);
	push_back(&root,40);
	push_back(&root, 30);

	root = rev(root);
	printList(root);

	std::cout << prev_node(&root, root->next->next)->data << std::endl;

	root = do_ascending2(root);

	printList(root);

	//find and remove loop
	link root1 = 0;
	root1 = add(root1, 1);
	root1->next = add(root1, 2);
	root1->next->next = add(root1, 3);
	root1->next->next->next = add(root1, 4);
	root1->next->next->next->next = add(root1, 5);
	root1->next->next->next->next->next = add(root1, 6);
	root1->next->next->next->next->next->next = root1->next->next->next;
	//printList(root1);

	findAndRemoveLoop(root1);
	printList(root1);

	traverse(root, visitor);
	traverseR(root, visitor);	
	std::cout <<  std::endl;
}

void drv_bitops(void)
{

	int x = 5;
	std::cout << last1bit(x) << std::endl;

	printbinary(0x5555FC05);

	std::cout << std::hex << bitreverse(0x55555555) << std::endl;

	std::cout << std::dec << "parity count:" << paritycount(0x5555FE50) << std::endl;

	std::cout << "ones count:" << onecount(0x5555FE50) << std::endl;

	std::cout << "zero count:" << zerocount(0x5555FE50) << std::endl;

	std::cout << std::dec << abs(-5) << std::endl;
	unsigned int u = 0xFFFFFFFF;
	std::cout << std::dec << u + 1 << std::endl;
	std::cout << std::hex << (u >> 31) << std::endl;


	int b = 1;

	std::cout << ((b << 31) >> 31) << std::endl;
	std::cout << "nibble swap:" << _swapn(0x73) << std::endl;
	std::cout << "byte swap:" << _swapb(0x3487) << std::endl;
	
	std::cout << "word swap:" << _swapw(0x34879231) << std::endl;
	 
	std::cout << std::hex << toupper('z') << ' ' << tolower('A') << std::endl;

	std::cout << std::dec << bin2gray(10) << std::endl;
}


int main()
{
	drv_single_linked_list();
	drv_bitops();
	char ch = getchar();

	return 0;
}