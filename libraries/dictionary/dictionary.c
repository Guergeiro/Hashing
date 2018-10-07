/*
 * dictionary.c
 *
 * Author: Breno
 */

#include "dictionary.h"

#include <stdlib.h>
#include <ctype.h>

// Alphabet from A to Z with +1 for unsorted words
#define NLISTS 27

struct dictionary *new_dictionary() {
	struct dictionary *new_dictionary = malloc(sizeof(struct dictionary));
	new_dictionary->array_list[0] = malloc(NLISTS * sizeof(struct list));
	char c = 'A';
	for (unsigned int i = 0; i < NLISTS - 1; i++) {
		new_dictionary->array_list[i] = new_list();
		new_dictionary->array_list[i]->character = c + i;
	}
	new_dictionary->array_list[NLISTS - 1]->character = '|'; // Last list must have a char that is higher than every letter in ASCII table
	return new_dictionary;
}

void destruct_dictionary(struct dictionary *dictionary) {
	if (dictionary) {
		for (unsigned int i = 0; i < NLISTS; i++) {
			destruct_list(dictionary->array_list[i]);
		}
		free(dictionary->array_list);
		free(dictionary);
	}
}

void print_dictionary_ascending_order(struct dictionary *dictionary) {
	if (dictionary) {
		for (unsigned int i = 0; i < NLISTS; i++) {
			print_list_ascending_order(dictionary->array_list[i]);
		}
	}
}

void print_dictionary_descending_order(struct dictionary *dictionary) {
	if (dictionary) {
		for (unsigned int i = NLISTS - 1; i >= 0; i--) {
			print_list_ascending_order(dictionary->array_list[i]);
		}
	}
}

void insert_node_dictionary(struct dictionary *dictionary, struct word_node *node) {
	if (dictionary && node) {
		for (unsigned int i = 0; i < NLISTS - 1; i++) {
			if (dictionary->array_list[i]->character == toupper(node->data->word[0])) {
				insert_node_list(dictionary->array_list[i], node);
				return;
			}
		}
		insert_node_list(dictionary->array_list[NLISTS - 1], node);
	}
}

void search_dictionary_node(struct dictionary *dictionary, struct word_node *node) {
	if (dictionary && node) {
		for (unsigned int i = 0; i < NLISTS - 1; i++) {
			if (dictionary->array_list[i]->character == toupper(node->data->word[0])) {
				search_node_list(dictionary->array_list[i], node);
				destruct_word_node(node);
				return;
			}
		}
		search_node_list(dictionary->array_list[NLISTS - 1], node);
	}
	destruct_word_node(node);
}

unsigned int number_of_words(struct dictionary *dictionary) {
	unsigned int soma = 0;
	if (dictionary) {
		for (unsigned int i = 0; i < NLISTS; i++) {
			soma += dictionary->array_list[i]->n_words;
		}
	}
	return soma;
}
