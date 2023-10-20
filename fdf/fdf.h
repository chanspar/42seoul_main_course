/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:29:47 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/20 11:27:29 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_mms_20210621/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_info
{
	int		x;
	int		y;
	int		**z;
	int		**c_x;
	int		**c_y;
	int		**x_prime;
	int		**y_prime;
	int		**color;
	int		gap;
	void	*mlx_pointer;
	void	*win_pointer;
}	t_info;

typedef struct s_img
{
	void	*img_pointer;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	check_right_file(t_info *info, char *av[]);
void	map_parse(t_info *info, char *av[]);
int		**make_two_dim(t_info *info);
void	get_coordinate(t_info *info);

void	projection(t_info *info);

void	err_print(char *str);
void	errno_print(char *str);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		word_cnt1(char *str, char c);
int		mal_str1(char **p, char *str, char c);
int		fail_free(char **p, int i);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

#endif