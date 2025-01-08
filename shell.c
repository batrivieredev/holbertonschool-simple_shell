#include "shell.h"

/**
 * main - Fonction principale du shell
 * Return: Retourne 0 si tout s'est bien passé, sinon une valeur d'erreur
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt();				/* Afficher l'invite */
		command = read_input(); /* Lire la commande */

		if (strlen(command) > 0)
		{
			execute_command(command); /* Exécuter la commande */
		}

		free(command); /* Libérer la mémoire allouée pour la commande */
	}

	return (0);
}
