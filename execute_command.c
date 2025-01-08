#include "shell.h"

/**
 * execute_command - Exécute une commande entrée par l'utilisateur
 * @command: La commande à exécuter
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* L'enfant exécute la commande */
		if (execlp(command, command, NULL) == -1)
		{
			handle_error(command);
		}
	}
	else
	{
		/* Le parent attend que l'enfant termine */
		wait(NULL);
	}
}
