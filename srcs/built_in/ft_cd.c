/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:11:18 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:30:37 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#ifndef __APPLE__
# include <linux/limits.h>
#else
# include <sys/syslimits.h>
#endif

char	*create_env(char *str1, char *str2)
{
	char	*str;
	int		len;

	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	if ((str = (char *)ft_memalloc(sizeof(char) * len + 2)) == NULL)
		exit_routine();
	ft_strcat(str, str1);
	ft_strcat(str, "=");
	ft_strcat(str, str2);
	return (str);
}

void	ft_cd_change_env(char *pwd, char *oldpwd, t_shell *shell)
{
	char	*old_pwd_env;
	char	*current_pwd_env;

	old_pwd_env = create_env("OLDPWD", oldpwd);
	current_pwd_env = create_env("PWD", pwd);
	ft_putenv(old_pwd_env, shell);
	ft_putenv(current_pwd_env, shell);
	if (old_pwd_env)
		free(old_pwd_env);
	if (current_pwd_env)
		free(current_pwd_env);
	return ;
}

int		ft_cd_chdir(char *path, t_shell *shell)
{
	char	pwd[PATH_MAX];
	char	oldpwd[PATH_MAX];

	getcwd(oldpwd, PATH_MAX);
	if (chdir(path) == -1)
	{
		ft_putendl_fd("42sh: cd: no such file or directory", 2);
		return (-1);
	}
	else
	{
		getcwd(pwd, PATH_MAX);
		ft_cd_change_env((char *)pwd, (char *)oldpwd, shell);
	}
	return (0);
}

void	ft_cd_end(char *path, t_shell *shell)
{
	if (ft_cd_chdir(path, shell) == -1)
		shell->executor->exit_code = -1;
	else
		shell->executor->exit_code = 0;
}

void	ft_cd(char **command, t_shell *shell)
{
	char	*path;

	command++;
	if (*command == NULL)
	{
		if ((path = get_env("HOME", shell)) == NULL)
		{
			ft_putendl_fd("42sh: cd: HOME environment variable not set", 2);
			shell->executor->exit_code = -1;
			return ;
		}
	}
	else if ((ft_strcmp(*command, "-") == 0) && ft_strlen(*command) == 1)
	{
		if ((path = get_env("OLDPWD", shell)) == NULL)
		{
			ft_putendl_fd("42sh: cd: OLDPWD environment variable not set", 2);
			shell->executor->exit_code = -1;
		}
	}
	else
		path = *command;
	ft_cd_end(path, shell);
	return ;
}
