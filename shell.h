#ifndef SHELL_H
#define SHELL_H

/* Inclusion des bibliothèques standard nécessaires */
#include <stdio.h>	   /* pour les opérations d'entrée/sortie */
#include <stdlib.h>	   /* pour les fonctions de gestion mémoire et exit */
#include <string.h>	   /* pour les fonctions de manipulation de chaînes */
#include <unistd.h>	   /* pour les appels système (fork, exec, etc.) */
#include <sys/types.h> /* pour les types de données système */
#include <sys/wait.h>  /* pour la gestion des processus */
#include <sys/stat.h>  /* pour les informations sur les fichiers */
#include <fcntl.h>	   /* pour les opérations sur les fichiers */
#include <dirent.h>	   /* pour la manipulation des répertoires */
#include <signal.h>	   /* pour la gestion des signaux */
#include <limits.h>	   /* pour les limites des types */

#define BUFFER_SIZE 1024
/* Taille du tampon pour la lecture */
#define MAX_INPUT_LENGTH 1024
/* Longueur maximale d'une commande utilisateur */
#define MAXARGS 128
/* Nombre maximal d'arguments pour une commande */
extern char **environ;
/* Variable globale contenant les variables d'environnement */

/* Prototypes des fonctions */

/**
 * execute_command - Exécute une commande donnée.
 * @command: Pointeur vers la chaîne représentant la commande à exécuter.
 */
void execute_command(char *command);

/**
 * handle_error - Gère les erreurs d'exécution.
 * @command: Pointeur vers la commande ayant provoqué l'erreur.
 */
void handle_error(char *command);

/**
 * string_token - Tokenise une chaîne en fonction d'un délimiteur.
 * @str: Pointeur vers la chaîne à tokeniser.
 * @delimiter: Délimiteur utilisé pour la séparation.
 * @argv: Tableau de pointeurs pour stocker les tokens résultants.
 */
void string_token(char *str, char *delimiter, char *argv[]);

/**
 * add_bin_prefix - Ajoute le préfixe "/bin/" à un argument de commande.
 * @argv: Tableau contenant les arguments de la commande.
 * @new_arg: Nouvelle chaîne contenant l'argument avec le préfixe.
 */
void add_bin_prefix(char *argv[], char *new_arg);

/**
 * interactive_mode - Gère le mode interactif du shell.
 * @bytes: Nombre d'octets lus.
 * @id: Identifiant du processus.
 * @input_buffer: Tampon pour stocker l'entrée utilisateur.
 * @argv_buffer: Tableau pour stocker les arguments de la commande.
 * @new_arg: Tampon pour un nouvel argument.
 */
void interactive_mode(int bytes, int id,
					  char *input_buffer, char *argv_buffer[], char *new_arg);

/**
 * non_interactive_mode - Gère le mode non interactif du shell.
 * @input_buffer: Tampon pour stocker l'entrée utilisateur.
 * @argv_buffer: Tableau pour stocker les arguments de la commande.
 * @new_arg: Tampon pour un nouvel argument.
 */
void non_interactive_mode(char *input_buffer,
						  char *argv_buffer[], char *new_arg);

/**
 * built_in_command - Vérifie et exécute les commandes internes.
 * @argv: Tableau d'arguments de la commande.
 *
 * Return: 1 si la commande est interne, 0 sinon.
 */
int built_in_command(char **argv);

/* Fonctions utilitaires */

/**
 * _strlen - Calcule la longueur d'une chaîne.
 * @s: Pointeur vers la chaîne.
 *
 * Return: Longueur de la chaîne.
 */
int _strlen(char *s);

/**
 * _strncpy - Copie une chaîne dans une autre avec une limite.
 * @dest: Destination de la copie.
 * @src: Source à copier.
 * @n: Nombre maximum de caractères à copier.
 */
void _strncpy(char *dest, char *src, int n);

/**
 * _strcmp - Compare deux chaînes.
 * @s1: Première chaîne.
 * @s2: Deuxième chaîne.
 *
 * Return: Différence entre les deux chaînes.
 */
int _strcmp(char *s1, char *s2);

/**
 * _atoi - Convertit une chaîne en entier.
 * @s: Pointeur vers la chaîne.
 *
 * Return: Valeur entière de la chaîne.
 */
int _atoi(char *s);

#endif /* SHELL_H */
