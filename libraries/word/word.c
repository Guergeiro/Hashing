/*
 * word.c
 *
 * Author: Breno
 */

#include "word.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256

struct word *new_word() {
	struct word *new_word = malloc(sizeof(struct word));
	printf("\nWord: ");
	char aux[BUFFER];
	while (getchar() != '\n')
		;
	scanf("%s", aux);
	new_word->word = malloc((strlen(aux) + 1) * sizeof(char));
	strcpy(new_word->word, aux);
	new_word->repetitions = 1;
	return new_word;
}

struct word_node *new_node(struct word *data) {
	struct word_node *new_node = calloc(1, sizeof(struct word_node));
	new_node->data = data;
	return new_node;
}

void destruct_word_node(struct word_node *node){
	free(node->data->word);
	free(node->data);
	free(node);
}

void destruct_all_nodes(struct word_node *node) {
	if (node->next) {
		destruct_all_nodes(node->next);
	}
	destruct_word_node(node);
}

void print_word(struct word *data) {
	printf("\nWord: %s\nRepetitions: %u", data->word, data->repetitions);
}

int compare_nodes(struct word_node *node1, struct word_node *node2) {
	return stricmp(node1->data->word, node2->data->word);
}
