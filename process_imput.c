#include "shell.h"

/**
 * process_input - Tokenise une chaîne en arguments
 * @input: Chaîne d'entrée utilisateur
 * @cmd_argv: Tableau pour stocker les arguments
 */
void process_input(char *input, char **cmd_argv)
{
	char *token;
	int i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		cmd_argv[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_argv[i] = NULL; /* Terminer le tableau avec NULL */
}
