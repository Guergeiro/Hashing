/*
 * list.h
 *
 * Author: Breno
 */

#ifndef LIBRARIES_LIST_LIST_H_
#define LIBRARIES_LIST_LIST_H_

#include "../word/word.h"

struct list {
	unsigned int n_nodes;
	char character;	//char that defines all words in the list
	struct word_node *first;
};

struct list *new_list();

void destruct_list(struct list *list);

#endif /* LIBRARIES_LIST_LIST_H_ */
