#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

extern char **environ; /* Déclaration de la variable d'environnement */

/* Fonction pour afficher les variables d'environnement */
void handle_env(void);

/* Fonction pour gérer la commande "exit" */
int parse_exit_status(char *cmd);

/* Fonction pour afficher l'invite du shell */
void display_prompt(void);

/* Fonction pour tokeniser une chaîne en arguments */
void process_input(char *input, char **cmd_argv);

/* Fonction pour exécuter la boucle principale du shell */
void execute_loop(int is_interactive, char **argv);

/* Fonction pour exécuter une commande */
void execute_command(char **cmd_argv, char *argv);

/* Fonction pour trouver le chemin complet d'une commande */
char *find_command_path(char *command);

#endif
