#include "shell.h"

/**
 * execute_loop - Boucle principale du shell
 * @is_interactive: Indique si le shell est en mode interactif
 * @argv: Vecteur d'arguments du programme
 */
void execute_loop(int is_interactive, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *cmd_argv[100];

	while (1)
	{
		if (is_interactive)
			display_prompt(); /* Afficher l'invite seulement en mode interactif */

		nread = getline(&line, &len, stdin); /* Lire l'entrée utilisateur */
		if (nread == -1)					 /* Gérer EOF ou erreur */
		{
			if (is_interactive)
				printf("\n");
			break;
		}

		line[nread - 1] = '\0'; /* Enlever le caractère de nouvelle ligne */

		process_input(line, cmd_argv); /* Tokeniser l'entrée en arguments */

		if (cmd_argv[0] == NULL) /* Ignorer les lignes vides */
			continue;

		if (strcmp(cmd_argv[0], "exit") == 0) /* Commande "exit" */
		{
			handle_exit();
		}

		if (strcmp(cmd_argv[0], "env") == 0) /* Commande "env" */
		{
			handle_env();
			continue;
		}

		execute_command(cmd_argv, argv[0]); /* Exécuter la commande */
	}

	free(line); /* Libérer la mémoire allouée */
}
