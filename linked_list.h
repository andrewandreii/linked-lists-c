#ifndef LLIST_C
#define LLIST_C

typedef struct _ll_node {
	struct _ll_node *next, *prev;
	void *d;
} ll_node;

typedef struct {
	ll_node *root;
	ll_node *end;
	int elem_size;
	int size;
} llist;

llist *ll_make(int elem_size);
void ll_free(llist *ll);

#define ll_set(ll, idx, data) memcpy(ll_get(ll, idx)->d, data, ll->elem_size)
/* void ll_set(llist *ll, int idx, void *data); */
void ll_append(llist *ll, void *data);
void ll_insert(llist *ll, int idx, void *data);
void ll_remove(llist *ll, int idx);

ll_node *ll_find(llist *ll, void *data);
int ll_index(llist *ll, void *data);
ll_node *ll_get(llist *ll, int idx);
#define ll_at(ll, idx, ret) memcpy(ret, ll_get(ll, idx)->d, ll->elem_size)
/* void ll_at(llist *ll, int idx, void *ret); */

#endif
