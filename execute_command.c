#include "shell.h"

/**
 * execute_command - Crée un processus enfant pour exécuter une commande
 * @cmd_argv: Tableau d'arguments (commande et ses options)
 * @argv: Nom du programme principal (pour l'affichage des erreurs)
 */
void execute_command(char **cmd_argv, char *argv)
{
	pid_t pid;
	char *path;

	path = find_command_path(cmd_argv[0]);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", cmd_argv[0]);
		exit(127);
	}

	/* Créer le processus enfant */
	pid = fork();
	if (pid == -1) /* Gérer les erreurs de fork */
	{
		perror(argv);
		return;
	}

	if (pid == 0) /* Bloc du processus enfant */
	{
		/* Exécuter la commande */
		if (execvp(path, cmd_argv) == -1)
		{
			perror(cmd_argv[0]); /* Afficher une erreur si execvp échoue */
			exit(EXIT_FAILURE);	 /* Quitter avec un code d'échec */
		}
	}
	else /* Bloc du processus parent */
	{
		/* Attendre la fin du processus enfant */
		if (wait(NULL) == -1)
		{
			perror("wait");
		}
	}
	free(path);
}
