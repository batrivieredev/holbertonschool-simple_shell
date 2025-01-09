#include "shell.h"

void exit_shell(char **args, int last_status)
{
	int status = last_status; /* Default to the last command's status */

	if (args[1]) /* Check for an optional exit status */
	{
		status = atoi(args[1]);
		if (status < 0) /* Invalid exit status */
		{
			write(STDERR_FILENO, "exit: Invalid status\n", 21);
			status = last_status;
		}
	}

	exit(status);
}
