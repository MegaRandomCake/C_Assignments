#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
void printList(struct Node *n) {
	while (n != NULL) {
		printf(" %d ", n->data);n = n->next;
	}
}
int main(int argc, char** argv) {
	struct Node* item1 = NULL;
	struct Node* item2 = NULL;
	struct Node* item3 = NULL; // allocate 3 nodes on the heap
	item1 = (struct Node*) malloc(sizeof (struct Node));
	item2 = (struct Node*) malloc(sizeof (struct Node));
	item3 = (struct Node*) malloc(sizeof (struct Node));
	item1->data = 3;
	item1->next = item2;
	item2->data = 2; //assign data to second node
	item2->next = item3;
	item3->data = 1; //assign data to third node
	item3->next = NULL;
	printList(item1);
	return (EXIT_SUCCESS);
}

/*
Will print " %d  %d  %d " or " 3  2  1 "
Good time to talk about calloc, malloc, realloc and free.
Malloc: Allocate memory block or bunch of memory. ptr = (int*) malloc(100 * sizeof(int));
Calloc: This is used to allocate cells or partitioned memory block. Sets everything to 0. ptr = (int*) calloc(100, sizeof(int));
Realloc: Allocate memory if we run out. ptr = realloc(ptr, 150);
Free: frees the memory so we can use it for something else. free(ptr);
 */
