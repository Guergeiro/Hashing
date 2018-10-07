/*
 * word.h
 *
 * Author: Breno
 */

#ifndef LIBRARIES_WORD_WORD_H_
#define LIBRARIES_WORD_WORD_H_

struct word {
	char *word;
	unsigned int repetitions;
};

struct word_node {
	struct word *data;
	struct word_node *next;
};

struct word *new_word();

struct word_node *new_node(struct word *data);

void destruct_word_node(struct word_node *node);

void destruct_all_nodes(struct word_node *node);

void print_word(struct word *data);

void print_nodes_ascending_order(struct word_node *node);

void print_nodes_descending_order(struct word_node *node);

void insert_node(struct word_node *current, struct word_node *node);

struct word_node *search_node(struct word_node *current, struct word_node *node);

int compare_nodes(struct word_node *node1, struct word_node *node2);

#endif /* LIBRARIES_WORD_WORD_H_ */
