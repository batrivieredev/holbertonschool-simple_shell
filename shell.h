#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <limits.h>

#define BUFFER_SIZE 1024     /* Taille du tampon pour la lecture */
#define MAX_INPUT_LENGTH 1024/* Longueur maximale d'une commande utilisateur */
#define MAXARGS 128          /* Nombre maximal d'arguments pour une commande */
#define NEW_ARG_SIZE 20      /* Taille maximale pour un nouvel argument */

extern char **environ;       /* Variables d'environnement */

/* Prototypes des fonctions */
void execute_command(char *command);
void handle_error(char *command);
void string_token(char *str, char *delimiter, char *argv[]);
void add_bin_prefix(char *argv[], char *new_arg);
void interactive_mode(ssize_t bytes, pid_t id, char *input_buffer,
						char *argv_buffer[], char *new_arg);
void non_interactive_mode(char *input_buffer, char *argv_buffer[],
						char *new_arg);
int built_in_command(char **argv);

/* Fonctions utilitaires */
int _strlen(char *s);
void _strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

#endif /* SHELL_H */
