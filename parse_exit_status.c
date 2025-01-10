#include <ctype.h>
#include "shell.h"

/**
 * parse_exit_status - Parses the exit status from the command
 * @cmd: The command string
 *
 * Return: The exit status (default is 0)
 */
int parse_exit_status(char *cmd)
{
	char *arg = cmd + 4; /* Move pointer past "exit" */
	int status = 0;
	int i;

	while (*arg == ' ') /* Skip any spaces after "exit" */
		arg++;

	if (*arg != '\0') /* If there is something after "exit" */
	{
		for (i = 0; arg[i]; i++)
		{
			if (!isdigit(arg[i])) /* Check if the argument is not a digit */
			{
				return (0); /* Return 0 to keep the shell running */
			}
		}
		status = atoi(arg); /* Convert the argument to an integer */
	}

	return (status);
}
