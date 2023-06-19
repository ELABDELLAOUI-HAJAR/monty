#include "monty.h"

/**
 * monty_interpreter - read monty instructions line by line
 */
void monty_interpreter(void)
{
	size_t n = 0;
	ssize_t nmbr_char;

	while (1)
	{
		nmbr_char = getline(&g_info.line, &n, g_info.file);
		if (nmbr_char == -1)
		{
			if (feof(g_info.file))
				exit(EXIT_SUCCESS);
			exit(EXIT_FAILURE);
		}

		printf("line : %s\n", g_info.line);
	}
}
