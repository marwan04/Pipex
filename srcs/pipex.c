/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:47:25 by malrifai          #+#    #+#             */
/*   Updated: 2024/11/12 12:15:40 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free_tab(s_cmd);
		exit(0);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[1], 0);
	if (dup2(fd, 0) == -1)
		exit_handler(-1, p_fd[0], p_fd[1], fd, -1);
	if (dup2(p_fd[1], 1) == -1)
		exit_handler(-1, p_fd[0], p_fd[1], fd, -1);
	close(p_fd[0]);
	close(fd);
	exec(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int		fd;
	pid_t	pid;

	fd = open_file(av[4], 1);
	if (dup2(fd, 1) == -1)
		exit_handler(-1, p_fd[0], p_fd[1], fd, -1);
	if (dup2(p_fd[0], 0) == -1)
		exit_handler(-1, p_fd[0], p_fd[1], fd, -1);
	close(p_fd[1]);
	close(fd);
	pid = fork();
	if(pid == -1)
		exit_handler(-1, p_fd[0], p_fd[1], -1);
	if (pid == 0)
		exec(av[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_handler(1);
	if (pipe(p_fd) == -1)
		exit_handler(-1);
	pid = fork();
	if (pid == -1)
		exit_handler(-1, p_fd[0], p_fd[1], -1);
	if (!pid)
		child(argv, p_fd, env);
	parent(argv, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	return 0;
}
