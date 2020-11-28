#include <stdio.h>
#include "linked_list.c"
#include <mcheck.h>

void
print_ll (llist *ll) {
	int i, elem;
	for (i = 0; i < ll->size; ++ i) {
		ll_at(ll, i, &elem);
		printf("%d\n", elem);
	}
	printf("\n");
}

void
main (void) {
	mtrace();

	llist *ll = ll_make(4);
	int elem = 10;
	for (; elem < 20; ++ elem) {
		ll_append(ll, &elem);
	}

	print_ll(ll);

	int find = 16;
	memcpy(ll_find(ll, &find)->d, &elem, 4);
	ll_insert(ll, 2, &elem);
	ll_pop(ll, 4, &elem);
	printf("poppped = %d\n", elem);

	print_ll(ll);

	elem = 15;
	printf("index of 15 = %d\n", ll_index(ll, &elem));

	ll_remove(ll, 0);

	print_ll(ll);

	ll_free(ll);

	ll = ll_make(4);
	ll_append(ll, &elem);
	ll_append(ll, &elem);
	ll_remove(ll, 1);
	++ elem;
	ll_find(ll, &elem);

	ll_free(ll);

	muntrace();
}
