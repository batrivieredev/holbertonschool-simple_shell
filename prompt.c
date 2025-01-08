#include "shell.h"


/**
 * prompt - Affiche l'invite de commande
 */
void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
