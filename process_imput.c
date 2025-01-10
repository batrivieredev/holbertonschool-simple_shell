#include "shell.h"

/**
 * process_input - Tokenise une chaîne en arguments
 * @input: Chaîne d'entrée utilisateur
 * @cmd_argv: Tableau pour stocker les arguments
 *
 * Description:
 * Cette fonction prend une chaîne de caractères en entrée,
 * la divise en tokens à l'aide de l'espace comme délimiteur,
 * et remplit le tableau `cmd_argv` avec ces tokens.
 * Le tableau est terminé par NULL pour indiquer la fin.
 */
void process_input(char *input, char **cmd_argv)
{
	char *token; /* Pointeur pour stocker chaque token extrait */
	int i = 0;	 /* Index pour remplir le tableau cmd_argv */

	/* Récupérer le premier token */
	token = strtok(input, " ");
	while (token != NULL) /* Continuer jusqu'à ce qu'il n'y ait plus de tokens */
	{
		cmd_argv[i++] = token;	   /* Ajouter le token au tableau */
		token = strtok(NULL, " "); /* Récupérer le token suivant */
	}
	cmd_argv[i] = NULL; /* Terminer le tableau avec NULL */
}
