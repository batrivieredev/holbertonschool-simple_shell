#include "shell.h"


/**
 *Déclaration de la variable externe
 *environ qui contient les variables d'environnement
 *
 */

extern char **environ;

/**
 * handle_env - Affiche les variables d'environnement
 */
void handle_env(void)
{
	/*Déclaration d'un pointeur vers un tableau de chaînes de caractères*/
	char **env;

	/*Boucle à travers chaque variable d'environnement et l'affiche*/
	{
		/*Affiche la variable d'environnement actuelle*/
		printf("%s\n", *env);
	}
}
