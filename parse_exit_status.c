#include <ctype.h>
#include "shell.h"

/**
 * parse_exit_status - Analyse le statut de sortie de la commande
 * @cmd: La chaîne de commande
 *
 * Return: Le statut de sortie (par défaut est 0)
 */
int parse_exit_status(char *cmd)
{
	char *arg = cmd + 4; /* Déplace le pointeur après "exit" */
	int status = 0;
	int i;

	while (*arg == ' ') /* Ignore les espaces après "exit" */
		arg++;

	if (*arg != '\0') /* S'il y a quelque chose après "exit" */
	{
		for (i = 0; arg[i]; i++)
		{
			if (!isdigit(arg[i])) /* Vérifie si l'argument n'est pas un chiffre */
			{
				return (0); /* Retourne 0 pour continuer à faire tourner le shell */
			}
		}
		status = atoi(arg); /* Convertit l'argument en entier */
	}

	return (status);
}
