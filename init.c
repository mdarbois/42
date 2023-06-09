#include "minishell.h"

static int init_env(NOM_STRUCT *STRUCT_VARIABLE, char **env)
{
    int i;

    i = 0;
    STRUCT_VARIABLE->env = ft_calloc(count_env(env) + 1, sizeof * STRUCT_VARIABLE->env);
    if (!STRUCT_VARIABLE->env)
        return (1);
    while (env[i] != NULL)
    {
        STRUCT_VARIABLE->env[i] = ft_strdup(env[i]);
        if (!STRUCT_VARIABLE->env[i])
            return (1);
        i++;
    }
    return (0);
}

static int init_dir(NOM_STRUCT *STRUCT_VARIABLE)
{  
    int	i;

	i = 0;
	while (STRUCT_VARIABLE->env[i])
	{
		if (!ft_strncmp(STRUCT_VARIABLE->env[i], "PWD=", 4))
			STRUCT_VARIABLE->pwd = ft_substr(STRUCT_VARIABLE->env[i],
					4, ft_strlen(STRUCT_VARIABLE->env[i]) - 4);
		if (!ft_strncmp(STRUCT_VARIABLE->envp[i], "OLDPWD=", 7))
			STRUCT_VARIABLE->old_pwd = ft_substr(STRUCT_VARIABLE->env[i],
					7, ft_strlen(STRUCT_VARIABLE->env[i]) - 7);
		i++;
	}
	return (0);
}

char	*find_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (ft_substr(env[i], 5, ft_strlen(env[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

int init_path(NOM_STRUCT *STRUCT_VARIABLE)
{
    char	*path_from_env;
	int		i;
	char	*tmp;

	path_from_env = find_path(STRUCT_VARIABLE->env);
	STRUCT_VARIABLE->path = ft_split(path_from_env, ':');
	free(path_from_env);
	i = 0;
	while (STRUCT_VARIABLE->path[i])
	{
		if (ft_strncmp(&STRUCT_VARIABLE->path[i][ft_strlen(STRUCT_VARIABLE->path[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(STRUCT_VARIABLE->path[i], "/");
			free(STRUCT_VARIABLE->path[i]);
			STRUCT_VARIABLE->path[i] = tmp;
		}
		i++;
	}
	return (0);
}

int init(NOM_STRUCT *STRUCT_VARIABLE, char **env)
{
    if (init_env(STRUCT_VARIABLE, env))
    {
        printf("Could not initialize environment\n");
        return (1);
    }
    if (init_dir(STRUCT_VARIABLE))
    {
        printf("Could not initialize directories\n");
        return (1);
    }
    if (init_path(STRUCT_VARIABLE))
    {
        printf("Could not initialize environment\n");
        return (1);
    }
    // might need to put NULL to some other values in the struct
    return (0);
}