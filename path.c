#include "shell.h"

/**
 * find_command_path - Trouve le chemin complet d'une commande
 * @command: Nom de la commande à rechercher
 *
 * Return: Chemin complet de la commande si trouvé, NULL sinon
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	size_t command_len;

	/* Vérifier si la commande est un chemin absolu ou relatif */
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}

	path_env = getenv("PATH"); /* Récupérer la variable d'environnement PATH */
	if (!path_env)
		return (NULL);
	path_copy = strdup(path_env); /* Copier PATH pour préserver l'original */
	if (!path_copy)
		return (NULL);
	command_len = strlen(command); /* Longueur de la commande */
	/* Diviser PATH en répertoires séparés par ':' */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		/* Allouer de la mémoire pour le chemin complet */
		full_path = malloc(strlen(dir) + command_len + 2); /* +2 pour '/' et '\0' */
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		/* Construire le chemin complet */
		sprintf(full_path, "%s/%s", dir, command);

		/* Vérifier l'existence et l'exécutabilité */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		/* Libérer la mémoire et passer au répertoire suivant */
		free(full_path);
		dir = strtok(NULL, ":");
	}

	/* Libérer la copie de PATH si la commande n'est pas trouvée */
	free(path_copy);
	return (NULL);
}
