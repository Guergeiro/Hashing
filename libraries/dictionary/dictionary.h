/*
 * dictionary.h
 *
 * Author: Breno
 */

#ifndef LIBRARIES_DICTIONARY_DICTIONARY_H_
#define LIBRARIES_DICTIONARY_DICTIONARY_H_

#include "../list/list.h"

struct dictionary {
	struct list **array_list;
};

struct dictionary *new_dictionary();

void destruct_dictionary(struct dictionary *dictionary);

void print_dictionary_ascending_order(struct dictionary *dictionary);

void print_dictionary_descending_order(struct dictionary *dictionary);

void insert_node_dictionary(struct dictionary *dictionary, struct word_node *node);

void search_dictionary_node(struct dictionary *dictionary, struct word_node *node);

unsigned int number_of_words(struct dictionary *dictionary);

#endif /* LIBRARIES_DICTIONARY_DICTIONARY_H_ */
