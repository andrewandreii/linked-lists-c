#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

llist *
ll_make (int elem_size) {
	llist *ll = malloc(sizeof(llist));
	ll->elem_size = elem_size;
	ll->size = 0;
	ll->root = ll->end = NULL;
	return ll;
}

void
ll_free_data (llist *ll) {
	if (ll->size == 0) return;

	if (ll->root == ll->end) {
		free(ll->root->d);
		free(ll->root);
		return;
	}

	ll_node *node = ll->end->prev;
	for (; node; node = node->prev) {
		free(node->next->d);
		free(node->next);
	}
	free(ll->root->d);
	free(ll->root);
	ll->size = 0;
}

void
ll_free (llist *ll) {
	ll_free_data(ll);
	free(ll);
}

// see macro in linked_list.h
/* void */
/* ll_set (llist *ll, int idx, void *data) { */
/* 	ll_node *node = ll_get(ll, idx); */

/* 	memcpy(node->d, data, ll->elem_size); */
/* } */

void
ll_append (llist *ll, void *data) {
	if (ll->root == NULL) {
		ll->root = ll->end = malloc(sizeof(ll_node));
		ll->root->next = ll->root->prev = NULL;
	} else {
		ll->end->next = malloc(sizeof(ll_node));
		ll->end->next->prev = ll->end;
		ll->end->next->next = NULL;
		ll->end = ll->end->next;
	}

	ll->end->d = malloc(ll->elem_size);
	memcpy(ll->end->d, data, ll->elem_size);
	++ ll->size;
}

void
ll_insert (llist *ll, int idx, void *data) {
	ll_node *node = ll_get(ll, idx);

	if (!node) return;

	ll_node *nnode = malloc(sizeof(ll_node));
	nnode->d = malloc(ll->elem_size);
	memcpy(nnode->d, data, ll->elem_size);
	nnode->next = node;
	nnode->prev = node->prev;
	node->prev->next = nnode;
	node->prev = nnode;

	// TODO: make it so you can insert stuff at the end#-1
	/* if (node == ll->root) { */
	/* 	ll->root = nnode; */
	/* } */
	/* if (node == ll->end) { */
	/* 	ll->end = nnode; */
	/* } */

	++ ll->size;
}

void
ll_remove (llist *ll, int idx) {
	ll_node *node = ll_get(ll, idx);

	if (!node) return;

	if (node == ll->root) {
		if (node == ll->end) {
			ll->root = ll->end = NULL;
		} else {
			ll->root = ll->root->next;
			ll->root->prev = NULL;
		}
	} else if (node == ll->end) {
		ll->end = ll->end->prev;
	} else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	free(node->d);
	free(node);
	-- ll->size;
}

void
ll_pop (llist *ll, int idx, void *ret) {
	ll_node *node = ll_get(ll, idx);

	memcpy(ret, node->d, ll->elem_size);
	ll_remove(ll, idx);
}

int
ll_index (llist *ll, void *data) {
	ll_node *node = ll->root;
	int i = 0;
	for (; node && memcmp(data, node->d, ll->elem_size) != 0; node = node->next, ++ i);

	if (!node) return -1;

	return i;
}

ll_node *
ll_find (llist *ll, void *data) {
	ll_node *node = ll->root;
	for (; node && memcmp(data, node->d, ll->elem_size) != 0; node = node->next);

	if (!node) return NULL;

	return node;
}

ll_node *
ll_get (llist *ll, int idx) {
	if (idx < 0 || idx >= ll->size) return NULL;

	ll_node *node = ll->root;
	int i = 0;
	for (; i < idx; node = node->next, ++ i);

	return node;
}

// see macro in linked_list.h
/* void */
/* ll_at (llist *ll, int idx, void *data) { */
/* 	ll_node *node = ll_get(ll, idx); */

/* 	memcpy(data, node->d, ll->elem_size); */
/* } */
