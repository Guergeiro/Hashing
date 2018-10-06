/*
 * list.c
 *
 * Author: Breno
 */

#include "list.h"

#include <stdlib.h>

struct list *new_list() {
	return calloc(1, sizeof(struct list));
}

void destruct_list(struct list *list) {
	if (list) {
		if (list->first) {
			destruct_all_nodes(list->first);
		}
		free(list);
	}
}
