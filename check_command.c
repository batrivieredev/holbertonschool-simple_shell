#include "shell.h"
/**
 * add_bin_prefix - Cette fonction ajoute le chemin "/bin/" à une commande.
 * @argv: Le vecteur d'arguments
 * @new_arg: La commande complète (avec le chemin ajouté)
 * Return: Rien (void)
 */
void add_bin_prefix(char *argv[], char *new_arg)
{
	char *prefix_path = "/bin/";
	size_t prefix_len;
	size_t arg_len;

	if (argv[0] == NULL)
		return;

	prefix_len = _strlen(prefix_path);
	arg_len = _strlen(argv[0]);

	if (_strcmp(argv[0], prefix_path) == 0 || _strcmp(argv[0], "./") == 0
			|| _strcmp(argv[0], "../") == 0)
		return;

	_strncpy(new_arg, prefix_path, prefix_len);
	_strncpy(new_arg + prefix_len, argv[0], arg_len);
	new_arg[prefix_len + arg_len] = '\0';

	argv[0] = new_arg;
}
