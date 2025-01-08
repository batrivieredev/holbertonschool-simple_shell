#include "shell.h"

/**
 * handle_error - Gère l'erreur lorsqu'une commande échoue
 * @command: La commande qui a échoué
 */
void handle_error(char *command)
{
	perror(command);
	exit(EXIT_FAILURE);
}
