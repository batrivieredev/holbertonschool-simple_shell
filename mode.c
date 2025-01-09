#include "shell.h"

/**
 * interactive_mode - Gère le mode interactif du shell.
 * @bytes: Nombre d'octets lus.
 * @id: Identifiant du processus.
 * @input_buffer: Tampon pour l'entrée utilisateur.
 * @argv_buffer: Tableau pour les arguments de la commande.
 * @new_arg: Tampon pour un nouvel argument.
 */
void interactive_mode(ssize_t bytes, pid_t id, char *input_buffer,
					char *argv_buffer[], char *new_arg)
{
	while (1) /* Boucle infinie pour le mode interactif */
	{
		printf("$ "); /* Prompt utilisateur */
		bytes = read(STDIN_FILENO, input_buffer, MAX_INPUT_LENGTH - 1);

		if (bytes == -1) /* Gestion des erreurs de lecture */
		{
			perror("Error reading input");
			exit(1);
		}

		if (bytes == 0) /* Fin de fichier (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		input_buffer[bytes - 1] = '\0'; /* Supprime caractère nouvelle ligne */

		/* Si l'utilisateur entre une commande vide, continuer */
		if (_strlen(input_buffer) == 0)
			continue;

		/* Tokeniser l'entrée et exécuter la commande */
		string_token(input_buffer, " ", argv_buffer);
		if (built_in_command(argv_buffer) == 0)
		{
			id = fork();
			if (id == 0)
			{
				add_bin_prefix(argv_buffer, new_arg);
				execute_command(argv_buffer[0]);
			}
			else
			{
				wait(NULL);
			}
		}
	}
}

/**
 * non_interactive_mode - Gère le mode non interactif du shell.
 * @input_buffer: Tampon pour stocker l'entrée utilisateur.
 * @argv_buffer: Tableau pour les arguments de la commande.
 * @new_arg: Tampon pour un nouvel argument.
 */
void non_interactive_mode(char *input_buffer, char *argv_buffer[],
							char *new_arg)
{
	ssize_t bytes = read(STDIN_FILENO, input_buffer, MAX_INPUT_LENGTH - 1);

	if (bytes == -1) /* Gestion des erreurs de lecture */
	{
		perror("Error reading input");
		exit(1);
	}

	input_buffer[bytes] = '\0'; /* Termine la chaîne d'entrée */

	string_token(input_buffer, " ", argv_buffer);
	if (built_in_command(argv_buffer) == 0)
	{
		add_bin_prefix(argv_buffer, new_arg);
		execute_command(argv_buffer[0]);
	}
}
