/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malrifai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:01:45 by malrifai          #+#    #+#             */
/*   Updated: 2024/11/10 00:30:36 by malrifai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void	exit_handler(int n_exit);
void	free_tab(char **tab);
void	exec(char *cmd, char **env);
char	*get_env(char *name, char **env);
char	*get_path(char *cmd, char **env);
int		open_file(char *file, int in_or_out);

#endif
