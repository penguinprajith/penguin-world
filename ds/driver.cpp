
#include <cstdio>
#include <iostream>
#include "driver.h"
#include "slist.h"

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
	 
}


int main()
{
	drv_single_linked_list();
	char ch = getchar();

	return 0;
}