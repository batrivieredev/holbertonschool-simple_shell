#include "shell.h"
/**
 * string_token - Gère la tokenisation d'une chaîne de caractères
 * @str: La chaîne de caractères à diviser
 * @delimiter: Le séparateur utilisé pour diviser la chaîne
 * @argv: Le vecteur d'arguments où les tokens sont stockés
 * Return: Rien (void)
 */
void string_token(char *str, char *delimiter, char *argv[])
{
	char *first_ptr = NULL;
	char *second_ptr = NULL;
	int argc = 0;
	int len;

	if (str != NULL)
	{
		len = _strlen(str);
		while (len > 0 && str[len - 1] == ' ')
			str[--len] = '\0';
	}

	first_ptr = str;

	while (*first_ptr && *first_ptr == ' ')
		first_ptr++;

	second_ptr = first_ptr;

	while (*first_ptr != '\0')
	{

		if (_strcmp(first_ptr, delimiter) == 0)
		{
			*first_ptr = '\0';
			while (*(first_ptr + 1) == ' ')
				first_ptr++;
			argv[argc++] = second_ptr;
			second_ptr = first_ptr + 1;
			if (argc >= MAXARGS)
				break;
		}
		first_ptr++;
	}
	argv[argc++] = second_ptr;
	argv[argc] = NULL;
}
