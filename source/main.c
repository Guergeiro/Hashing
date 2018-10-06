/*
 * main.c
 * Author: Breno
 */

#include "main.h"
#include "../libraries/macros/macros.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc % 2) {
		CLEARSCR;
		printf("\n%s <file>", argv[0]);
		exit(1);
	}

	//struct tree *tree = new_tree();
	unsigned int op;
	do {
		op = menu();
		CLEARSCR;
		switch (op) {
		case 1:
			//insert_node_tree(tree, new_node(new_person()));
			break;
		case 2:
			//search_tree_node(tree, new_node(new_person()));
			break;
		case 3:
			//print_tree_ascending_order(tree);
			PAUSE;
			break;
		case 4:
			//print_tree_descending_order(tree);
			PAUSE;
			break;
		case 5:
			//printf("\nNumber of nodes: %u", number_of_nodes(tree));
			PAUSE;
			break;
		case 6:
			//invert_tree(tree);
			break;
		case 7:
			//printf("\nTree height: %u", tree_height(tree));
			PAUSE;
			break;
		case 8:
			//import_file(tree, argv[1]);
			break;
		case 9:
			//export_file(tree);
			break;
		}
	} while (op != 0);

	//destruct_tree(tree);
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
