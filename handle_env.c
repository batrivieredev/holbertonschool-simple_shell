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
