/*
 * list.c
 *
 * Author: Breno
 */

#include "list.h"

#include <stdio.h>
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

void print_list_ascending_order(struct list *list) {
	if (list) {
		if (list->first) {
			print_nodes_ascending_order(list->first);
		}
	}
}

void print_list_descending_order(struct list *list) {
	if (list) {
		if (list->first) {
			print_nodes_descending_order(list->first);
		}
	}
}

void insert_node_list(struct list *list, struct word_node *node) {
	if (list && node) {
		if (list->first) {
			if (compare_nodes(list->first, node) > 0) {
				node->next = list->first;
				list->first = node;
			} else {
				insert_node(list->first, node);
			}
		} else {
			list->first = node;
		}
		list->n_words++;
	}
}

void search_node_list(struct list *list, struct word_node *node) {
	if (list && node) {
		if (list->first) {
			struct word_node *result = search_node(list->first, node);
			if (result) {
				print_word(result->data);
			} else {
				printf("\nNode doesn't exist");
			}
		} else {
			printf("\nNode doesn't exist");
		}
	}
}
