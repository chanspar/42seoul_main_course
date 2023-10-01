/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:22:07 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/22 22:39:17 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_info
{
	char	*tag;
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	**path;
	char	*cmd_path1;
	char	*cmd_path2;
	char	*infile;
	char	*outfile;
	char	*temp;
	int		temp_fd;
	int		infile_fd;
	int		outfile_fd;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_info;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
char	*strchr_ft(const char *s, int c);

int		check_slash_b(char **cmd);
char	*merge_utils_b(char **env_path, char *cmd_tmp, t_info *info);
char	*merge_cmd_b(char **env_path, char **cmd, t_info *info);

void	errno_print_b(char *str, t_info *info);
void	err_print_b(char *str, t_info *info);
void	err_print_s_b(char *str1, char *str2, t_info *info);
void	dup2_check_b(int fd1, int fd2);

char	*ft_free(char **str);
char	*make_line(long long idx, char *tmp);
char	*make_line_rest(char **rest);
char	*read_file(char *buff, char **rest, int fd);
char	*get_next_line(int fd);

void	here_doc_info(t_info *info, char *av[], char *envp[]);

char	*find_path_b(char *envp[], t_info *info);
char	**path_list_b(t_info *info);
void	input_info_b(t_info *info, char *av[], char *envp[]);

#endif