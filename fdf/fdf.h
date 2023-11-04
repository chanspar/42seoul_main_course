/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:29:47 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/04 10:03:34 by chanspar         ###   ########.fr       */
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

# include <stdio.h>

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080
# define MARGIN 200

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_info
{
	int		width;
	int		height;
	int		win_x;
	int		win_y;
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;
	double	**x;
	double	**y;
	int		**z;
	int		**color;
	int		gap;
	void	*p_mlx;
	void	*p_win;
	void	*p_img;
	char	*addr;
	int		bpp;
	int		l_l;
	int		ed;
}	t_info;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		sx_sy[2];
}	t_coord;

void	check_right_file(t_info *info, char *av[]);
void	map_parse(t_info *info, char *av[]);
int		**make_two_dim(t_info *info);
double	**make_two_dim_d(t_info *info);
void	get_color(t_info *info, char *str, int i, int j);
void	decide_color(t_coord *cur, t_coord *final, int *cur_color, int step);
void	get_gap(t_info *info);
void	get_max_min(t_info *info, t_coord *coord);
void	get_xy(t_info *info);
void	mlx_utils(t_info *info);
void	get_window_size(t_info *info);

int		abs_int(int x);
void	xaxis_rotate(t_coord *coord, double theta);
void	yaxis_rotate(t_coord *coord, double theta);

void	my_pixel_put(t_info *info, int x, int y, int color);

void	bresenham(t_info *info, t_coord *start, t_coord *final);
void	draw_horizen(t_info *info);
void	draw_vertical(t_info *info);

void	err_print(char *str);
void	errno_print(char *str);
int		close_win(t_info *info);
int		close_key(int keycode, t_info *info);
void	event_exe(t_info *info);

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