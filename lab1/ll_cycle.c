#include <stdio.h>
#include <stdbool.h> //allows for use of booleans; or can use 0 as false & non-0 as true

typedef struct node {
	int value;
	struct node *next;
} node;

// int two_step(node *hare) {
// 	if (!hare) return 0;
// 	hare = hare->next;
// 	if (!hare) return 0;
// 	return hare->next;
// }

bool ll_has_cycle(node *head) { //via https://github.com/db0company/UCBerkeley-cs61c/blob/master/Labs/lab02/ll_cycle.c
	node * tortoise = head, * hare = head;
	while (hare && hare->next && hare->next->next) {
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (tortoise == hare) return true;
	}
	return false;
	// hare = head;
	// tortoise = head;
	//
	// while (hare) {
	// 	hare = two_step(hare);
	// 	tortoise = tortoise->next;
	// 	if (hare == tortoise) return 0;
	// }
	//
	// return 0;
}

void test_ll_has_cycle(void) {
	int i;
	node nodes[25]; //enough to run our tests
	for(i=0; i < sizeof(nodes)/sizeof(node); i++) {
		nodes[i].next = 0;
		nodes[i].value = 0;
	}
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = &nodes[3];
	printf("Checking first list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[0])?"a":"no");

	nodes[4].next = &nodes[5];
	nodes[5].next = &nodes[6];
	nodes[6].next = &nodes[7];
	nodes[7].next = &nodes[8];
	nodes[8].next = &nodes[9];
	nodes[9].next = &nodes[10];
	nodes[10].next = &nodes[4];
	printf("Checking second list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[4])?"a":"no");

	nodes[11].next = &nodes[12];
	nodes[12].next = &nodes[13];
	nodes[13].next = &nodes[14];
	nodes[14].next = &nodes[15];
	nodes[15].next = &nodes[16];
	nodes[16].next = &nodes[17];
	nodes[17].next = &nodes[14];
	printf("Checking third list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[11])?"a":"no");

	nodes[18].next = &nodes[18];
	printf("Checking fourth list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[18])?"a":"no");

	nodes[19].next = &nodes[20];
	nodes[20].next = &nodes[21];
	nodes[21].next = &nodes[22];
	nodes[22].next = &nodes[23];
	printf("Checking fifth list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[19])?"a":"no");

	printf("Checking length-zero list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(NULL)?"a":"no");
}

int main(void) {
  test_ll_has_cycle();
  return 0;
}
