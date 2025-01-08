#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;

/* Function Prototypes */
void prompt(void);
void execute_command(char *command);
char *read_input(void);
void handle_error(char *command);

#endif
