#include "shell.h"

/**
 * exit_shell - Fonction pour quitter le shell
 * @args: Tableau d'arguments
 * @last_status: Statut de la dernière commande exécutée
 *
 * Description: Cette fonction permet de quitter le shell avec un statut
 * spécifié par l'utilisateur ou par défaut avec le statut de la dernière
 * commande exécutée. Si le statut fourni est invalide (négatif), un message
 * d'erreur est affiché et le shell quitte avec le statut de la dernière
 * commande.
 */
void exit_shell(char **args, int last_status)
{
	int status = last_status; /*utiliser le statut de la dernière commande */

	if (args[1]) /* Vérifier s'il y a un statut de sortie optionnel */
	{
		status = atoi(args[1]);
		if (status < 0) /* Statut de sortie invalide */
		{
			write(STDERR_FILENO, "exit: Invalid status\n", 21);
			status = last_status;
		}
	}

	exit(status);
}
