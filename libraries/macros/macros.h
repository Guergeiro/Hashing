/*
 * macros.h
 * Author: Breno
 */

#ifndef MACROS_MACROS_H_
#define MACROS_MACROS_H_

#include <stdlib.h>

#if defined POSIX
#define CLEARSCR system ( "clear" )
#define PAUSE printf("\n");system ( "read -rsp $'Press any key to continue...\n' -n 1 key" )
#elif defined MSDOS || defined WIN32
#define CLEARSCR system ( "cls" )
#define PAUSE printf("\n");system ( "pause" )
#endif

#endif /* MACROS_MACROS_H_ */
