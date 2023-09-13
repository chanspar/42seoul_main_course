/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:39:20 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/13 21:53:48 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_info
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	**path;
	char	*cmd_path1;
	char	*cmd_path2;
	int		infile_fd;
	int		outfile_fd;
	int		fd[2];
	pid_t	pid;
}	t_info;

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);

char		*find_path(char *envp[]);
char		**path_list(t_info *info);
char		*merge_cmd(char **env_path, char **cmd);
void		input_info(t_info *info, char *av[], char *envp[]);
void		connect_pipe(t_info *info);
void		errno_print(char *str);
void		err_print(char *str);
void		err_print_s(char *str1, char *str2);
void		close_fd(int fildes);
void		dup2_check(int fd1, int fd2);

#endif