#include "shell.h"

/**
 * handle_env - Affiche les variables d'environnement
 */
void handle_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
		printf("%s\n", *env);
}

/**
 * handle_exit - Gère la commande "exit"
 */
void handle_exit(void)
{
	exit(0); /* Quitter avec un code de statut de 0 */
}
