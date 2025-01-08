#include "shell.h"

/**
 * read_input - Lit l'entrée de l'utilisateur
 *
 * Return: Une chaîne de caractères entrée par l'utilisateur.
 */



char *read_input(void)
{
	char *input = malloc(BUFFER_SIZE);

	if (!input)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (fgets(input, BUFFER_SIZE, stdin) == NULL)
	{
		free(input);
		if (feof(stdin))
			exit(EXIT_SUCCESS); /* Fin de fichier (Ctrl+D) */
		else
			perror("fgets");
		exit(EXIT_FAILURE);
	}

	/* Supprimer le saut de ligne à la fin de l'entrée */
	input[strcspn(input, "\n")] = 0;
	return (input);
}
