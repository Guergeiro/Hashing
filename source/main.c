/*
 * main.c
 * Author: Breno
 */

#include "main.h"
#include "../libraries/macros/macros.h"
#include "../libraries/file/file.h"
#include "../libraries/dictionary/dictionary.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc % 2) {
		CLEARSCR;
		printf("\n%s <file>", argv[0]);
		exit(1);
	}

	struct dictionary *dictionary = new_dictionary();
	unsigned int op;
	do {
		op = menu();
		CLEARSCR;
		switch (op) {
		case 1:
			insert_node_dictionary(dictionary, new_node(new_word()));
			break;
		case 2:
			search_dictionary_node(dictionary, new_node(new_word()));
			break;
		case 3:
			print_dictionary_ascending_order(dictionary);
			PAUSE;
			break;
		case 4:
			print_dictionary_descending_order(dictionary);
			PAUSE;
			break;
		case 5:
			printf("\nNumber of words: %u", number_of_words(dictionary));
			PAUSE;
			break;
		case 6:
			import_file(dictionary, argv[1]);
			break;
		case 7:
			export_file(dictionary);
			break;
		}
	} while (op != 0);

	destruct_dictionary(dictionary);
}

int menu() {
	CLEARSCR;
	printf("\n(1) Insert new node");
	printf("\n(2) Search a node");
	printf("\n(3) Print all nodes (ascending order)");
	printf("\n(4) Print all nodes (descending order)");
	printf("\n(5) Number of nodes");
	printf("\n(6) Invert tree");
	printf("\n(7) Tree height");
	printf("\n(8) Import file");
	printf("\n(9) Export .txt file");
	printf("\n(0) Exit");
	printf("\n\nOption: ");
	unsigned int op;
	scanf("%u", &op);
	return op;
}
