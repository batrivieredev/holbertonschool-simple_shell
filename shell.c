#include "shell.h"

/**
 * main - Point d'entrée du programme.
 *
 * Cette fonction détermine si l'entrée est en mode interactif ou non.
 * En mode interactif, elle appelle `interactive_mode`.
 * Sinon, elle appelle `non_interactive_mode`.
 *
 * Return: 0 en cas de succès, 1 en cas d'erreur.
 */
int main(void)
{
	pid_t id = 0;						 /* Identifiant du processus enfant */
	ssize_t bytes = 0;					 /* Nombre d'octets lus depuis l'entrée */
	char input_buffer[MAX_INPUT_LENGTH]; /* Tampon pour l'entrée utilisateur */
	char new_arg[NEW_ARG_SIZE];			 /* Tampon pour le nouvel argument */
	char *argv_buffer[MAXARGS];			 /* Tableau pour les arguments de la commande */

	/* Vérifie si l'entrée standard est un terminal */
	if (isatty(STDIN_FILENO) == -1)
	{
		perror("Error checking input type");
		return (1);
	}

	/* Mode interactif ou non interactif */
	if (isatty(STDIN_FILENO) == 1)
	{
		/* Mode interactif */
		printf("Welcome to the shell! Type your commands below:\n");
		interactive_mode(bytes, id, input_buffer, argv_buffer, new_arg);
	}
	else
	{
		/* Mode non interactif */
		non_interactive_mode(input_buffer, argv_buffer, new_arg);
	}

	return (0); /* Indique la réussite de l'exécution */
}
