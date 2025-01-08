#include "shell.h"

/**
 * execute_command - Exécute une commande entrée par l'utilisateur
 * @command: La commande à exécuter
 */
void execute_command(char *command)
{
	pid_t pid = fork();
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* L'enfant exécute la commande */
		if (execve(command, argv, environ) == -1)
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
