/*
 * file.c
 *
 * Author: Breno
 */

#include "file.h"

#include "../word/word.h"
#include "../macros/macros.h"

#include <string.h>

#define BUFFER 256
#define DELIMETER ",;.\n\r\t "

void import_file(struct dictionary *dictionary, char *location) {
	FILE *file = fopen(location, "r");
	if (!file) {
		printf("\nImpossible to open file");
		PAUSE
		;
		return;
	}

	char buffer[BUFFER];
		char *aux;
		while (!feof(file)) {
			fgets(buffer, BUFFER, file);
			aux = strtok(buffer, DELIMETER);
			while (aux) {
				struct word *data = malloc(sizeof(struct word));
				data->word = malloc((strlen(aux) + 1) * sizeof(char));
				strcpy(data->word, aux);
				insert_node_dictionary(dictionary, new_node(data));
				aux = strtok(NULL, DELIMETER);
			}
		}
		fclose(file);
}

void export_file(struct dictionary *dictionary) {
	if (dictionary) {
		FILE *file = fopen("file.csv", "w");
		for (unsigned int i = 0; i < 27; i++) {
			export_nodes_ascending_order(dictionary->array_list[i]->first, file);
		}
		fclose(file);
	}
}

void export_nodes_ascending_order(struct word_node *node, FILE *file) {
	if (node) {
		fprintf(file, "%s,%u", node->data->word, node->data->repetitions);
	}
	if (node->next) {
		export_nodes_ascending_order(node->next, file);
	}
}
