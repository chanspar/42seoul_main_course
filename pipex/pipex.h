/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:39:20 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/26 20:51:01 by chanspar         ###   ########.fr       */
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
	char	*infile;
	char	*outfile;
	int		infile_fd;
	int		outfile_fd;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_info;

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char const *s, char c);
int			word_cnt1(char *str, char c);
int			mal_str1(char **p, char *str, char c);
int			fail_free(char **p, int i);

char		*find_path(char *envp[], t_info *info);
char		**path_list(t_info *info);
char		*merge_utils(char **env_path, char *cmd_tmp, t_info *info);
char		*merge_cmd(char **env_path, char **cmd, t_info *info);
int			check_slash(char **cmd);
void		input_info(t_info *info, char *av[], char *envp[]);
void		errno_print(char *str, t_info *info);
void		err_print(char *str, t_info *info);
void		err_print_s(char *str1, char *str2, t_info *info);
void		dup2_check(int fd1, int fd2);
void		close_fd(t_info *info, int fdfd);
void		process1_util(t_info *info);
void		process2_util(t_info *info);
void		process1(t_info *info);
void		process2(t_info *info);
void		process3(t_info *info);
void		free_utils(t_info *info);
void		free_struct(t_info *info);

#endif