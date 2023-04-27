#include "shell.h"

/**
 * _strlen - counts the length of a string
 * @string: string to nbe counted
 * Return: returns the length of the string
*/
int _strlen(const char *string)
{
	int length;

	length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strdup - duplicates a string and allocated a new memmory address
 * @str: string to be duplicated
 * Return: returns string at new address
*/
char *_strdup(char *str)
{
	int i = 0;
	int length = 0;
	char *str_c;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		while (*(str + length) != '\0')
		{
			length++;
		}
		str_c = malloc(length * sizeof(char) + 1);
		while (*(str + i) != '\0')
		{
			*(str_c + i) = *(str + i);
			i++;
		}
		return (str_c);
	}
}


/**
 * same_len_cmp - compares two string if they are of the same length
 * @a: first string
 * @b: second string
 * @cnt: length
 * Return: returns negative if  a > b, positive if b > a
 * and 0 if they are equal
*/
int same_len_cmp(char *a, char *b, int cnt)
{
	int cmp1, cmp2, cmp3, num;

	cmp1 = 0;
	cmp2 = 0;
	cmp3 = 0;
	for (num = 0; num < cnt; num++)
	{
		if (a[num] < b[num])
			cmp1++;
		else if (a[num] > b[num])
			cmp2++;
		else
			cmp3++;
	}
	if (cmp1 > cmp2)
		return (-15);
	else if (cmp2 > cmp1)
		return (15);
	else if ((cmp3 == cmp1) & (cmp3 == cmp2))
		return (0);
	else
		return (0);
}


/**
 * _strcmp - comapres two strings if they are the same
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: 0 if the same, negative if s1 < s2, positive if s1 > s2
*/
int _strcmp(char *s1, char *s2)
{
	int s1_count, s_count, num;

	s1_count = 0;
	s_count = 0;
	for (num = 0; s1[num] != '\0'; num++)
	{
		s1_count++;
	}
	for (num = 0; s2[num] != '\0'; num++)
	{
		s_count++;
	}
	if (s1_count == s_count)
	{
		same_len_cmp(s1, s2, s1_count);
	}
	else if (s1_count < s_count)
	{
		return (-15);
	}
	else if (s1_count > s_count)
	{
		return (15);
	}
	return (0);
}
/**
 * _strncmp - compares at most n bytes of q string with another
 * @s1: the reference string
 * @s2: the string to be compared
 * @n: the number of bytes of string to compare
 * Return: returns 0 if the same for the first n character, -1 if not the same
*/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t num, s_count;

	s_count = 0;

	for (num = 0; num < n; num++)
	{
		if (s1[num] == s2[num])
		{
			s_count++;
		}
	}
	if (s_count == num)
		return (0);
	else
		return (-1);
}
