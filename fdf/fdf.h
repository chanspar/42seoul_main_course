/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:29:47 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/24 21:37:05 by chanspar         ###   ########.fr       */
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
	int		width;
	int		height;
	int		**z;
	int		**color;
	int		gap;
	void	*mlx_pointer;
	void	*win_pointer;
}	t_info;

typedef struct s_coord
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z1;
	double	z2;
	int		sx;
	int		sy;
	int		k;
	int		k_a;
	int		k_b;
}	t_coord;

typedef struct s_img
{
	void	*img_pointer;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	check_right_file(t_info *info, t_coord *coord, char *av[]);
void	map_parse(t_info *info, char *av[]);
int		**make_two_dim(t_info *info);

void	get_coordinate(t_info *info);

void	horizen(t_info *info, t_coord *coord, int x, int y);
void	vertical(t_info *info, t_coord *coord, int x, int y);

void	draw(t_info *info, t_coord *coord);
// void	bresenham_exe1(t_info *info, t_coord *coord);
// void	bresenham_exe2(t_info *info, t_coord *coord);

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