/*
(lldb) b function
Breakpoint 2: where = stophook`function + 10 at main.c:14, address = 0x0000000100000eca
(lldb) target stop-hook add --one-liner "frame variable"
Stop hook #1 added.
*/
#include <stdio.h>

typedef struct node {
	int val;
	struct node* next;
} node;

/* FIXME: this function is buggy. */
int ll_equal(const node* a, const node* b) { //receives pointers to 2 nodes
	while (a != NULL && b != NULL) { //--looks like this is right... forgot to recompile!!!!
		if (a->val != b->val) //if the values of the two pointers' nodes aren't equal
			return 0; //return 0
		a = a->next; //otherwise, a = the value of its next
		b = b->next;
	}
	/* lists are equal if a and b are both null */
	return a == b;
}

int main(int argc, char** argv) {
	int i; //declare an integer
	node nodes[10]; //create an array of 10 nodes

	for (i=0; i<10; i++) {
		nodes[i].val = 0; //set the value of each node to 0
		nodes[i].next = NULL; //set its next node to NULL
	}

	nodes[0].next = &nodes[1]; //set the next of the first node to the second node's pointer
	nodes[1].next = &nodes[2];
	nodes[2].next = &nodes[3];

	printf("equal test 1 result = %d\n", ll_equal(&nodes[0], &nodes[0])); //passes the address for 2 nodes
	printf("equal test 2 result = %d\n", ll_equal(&nodes[0], &nodes[2]));

	return 0;
}
