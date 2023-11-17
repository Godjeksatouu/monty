/**
 * check_num - Determines if a string is a valid number.
 *
 * @num: Pointer to the string being examined.
 *
 * Return: 0 if the string contains a non-numeric character, else 1.
 */

char check_num(char *num)
{
	unsigned int i;

	if (num[0] == '-')
		i = 1;
	else
		i = 0;
	for (; num[i] != '\0'; i++)
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
	}
	return (1);
}
