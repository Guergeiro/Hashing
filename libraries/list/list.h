/*
 * list.h
 *
 * Author: Breno
 */

#ifndef LIBRARIES_LIST_LIST_H_
#define LIBRARIES_LIST_LIST_H_

#include "../word/word.h"

struct list {
	unsigned int n_words;
	char character;	//char that defines all words in the list
	struct word_node *first;
};

struct list *new_list();

void destruct_list(struct list *list);

void print_list_ascending_order(struct list *list);

void print_list_descending_order(struct list *list);

void insert_node_list(struct list *list, struct word_node *node);

void search_node_list(struct list *list, struct word_node *node);

#endif /* LIBRARIES_LIST_LIST_H_ */
