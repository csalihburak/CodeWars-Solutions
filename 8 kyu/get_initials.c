/*
Write a function to convert a name into initials. This kata strictly takes two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

Sam Harris => S.H

patrick feeney => P.F

*/



char *get_initials(const char *full_name, char initials[6])
{
	int i = 0;
	int j = 2;
	if (full_name[0] >= 96 && full_name[0] <= 122)
		initials[0] = full_name[0] - 32;
	else
		initials[0] = full_name[0];
	initials[1] = '.';
	while (full_name[i])
	{
		while (full_name[i] != ' ' && full_name[i])
			i++;
		if (!full_name[i])
		{
			initials[j] = '\0';
			return initials;
		}
		if (full_name[++i] >= 96 && full_name[i] <= 122)
			initials[j++] = full_name[i] - 32;
		else
			initials[j++] = full_name[i];
		i++;
	}
	initials[j] = '\0';
	return initials;
}