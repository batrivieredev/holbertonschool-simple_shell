#include "shell.h"
/**
 * _strlen - Calcule la longueur d'une chaîne de caractères
 * @s: La chaîne de caractères
 * Return: La longueur de la chaîne
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * _strncpy - Copie une chaîne de caractères
 * @dest: La destination de la copie
 * @src: La source de la copie
 * @n: Le nombre maximum de caractères à copier
 * Return: Rien (void)
 */
void _strncpy(char *dest, char *src, int n)
{
	int a;

	a = 0;
	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
}

/**
 * _strcmp - Compare deux chaînes de caractères
 * @s1: Première chaîne
 * @s2: Deuxième chaîne
 *
 * Return: La différence entre les deux caractères qui diffèrent
 *         ou 0 si les chaînes sont identiques
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (0);
}

/**
 * _atoi - Convertit une chaîne de caractères en entier
 * @s: La chaîne de caractères
 * Return: L'entier converti ou 0 en cas d'erreur
 */
int _atoi(char *s)
{
	int i, sign, num;

	if (s == NULL)
		return (0);
	i = 0;
	sign = 1;
	num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{

			if (sign > 0 && num > INT_MAX / 10)
				return (INT_MAX);
			if (sign > 0 && num == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)
				return (INT_MAX);
			if (sign < 0 && num < INT_MIN / 10)
				return (INT_MIN);
			if (sign < 0 && num == INT_MIN / 10 && s[i] - '0' > -(INT_MIN % 10))
				return (INT_MIN);

			num = num * 10 + sign * (s[i] - '0');
		}
		else if (num != 0)
			break;
		i++;
	}
	return (num);
}
