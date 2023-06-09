#include "minishell.h"

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_arr(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

void free_tab(char **str)
{
    int i;

    i = 0;
    if (str)
    {
		while (str[i])
		{
			if (str[i])
			{
				free_ptr(str[i]);
				str[i] = NULL;
			}
			i++;
		}
		free(str);
		str = NULL;
	}
}

void	exit_shell(NOM_STRUCT *STRUCT_VARIABLE, int number)
{
	if (STRUCT_VARIABLE)
	{
		// CLOSE FDS
	
		// FREE(STRUCT_VARIABLE)
        if (STRUCT_VARIABLE && STRUCT_VARIABLE->env)
            free_tab(STRUCT_VARIABLE->env)
            
	}
	exit(number);
}