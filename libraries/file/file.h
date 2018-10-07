/*
 * file.h
 *
 * Author: Breno
 */

#ifndef LIBRARIES_FILE_FILE_H_
#define LIBRARIES_FILE_FILE_H_

#include <stdio.h>
#include "../dictionary/dictionary.h"

void import_file(struct dictionary *dictionary, char *location);

void export_file(struct dictionary *dictionary);

void export_nodes_ascending_order(struct word_node *node, FILE *file);

#endif /* LIBRARIES_FILE_FILE_H_ */
