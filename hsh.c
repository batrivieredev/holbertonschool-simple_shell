#include "shell.h"

/**
 * main - Point d'entrée du shell
 * @argc: Nombre d'arguments (non utilisé)
 * @argv: Vecteur d'arguments
 * Return: 0 en cas de succès
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int is_interactive = isatty(STDIN_FILENO); /* Détecter le mode interactif */

	execute_loop(is_interactive, argv);
	return (0);
}
