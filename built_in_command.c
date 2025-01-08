#include "shell.h"

/**
 * built_in_command - checks that command is a built-in command
 * @argv: arguments vector
 * Return: 0 or 1
 */
int built_in_command(char **argv)
{
	char **envp;
	int exit_status;

	if (_strcmp(argv[0], "exit") == 0)
	{
		exit_status = EXIT_SUCCESS;
		if (argv[1] != NULL)
		{
			exit_status = _atoi(argv[1]);
			if (exit_status < 0)
				exit(EXIT_FAILURE);
			 exit(exit_status);
		}
		exit(exit_status);
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		envp = environ;
		while (*envp != NULL)
		{
			write(STDOUT_FILENO, *envp, _strlen(*envp));
			write(STDOUT_FILENO, "\n", 1);
			envp++;
		}
		return (1);
	}
	return (0);
}
