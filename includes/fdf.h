/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../includes/mlx.h"
# include "../libft/includes/libft.h"

# define WHITE				0xFFFFFF
# define BLACK				0x000000
# define WINE				0xAB271D
# define ROSE				0x6D3445
# define STRONG_ROSE		0x9D788F
# define DEF_COL			0xC488AC
# define TEXT_COL0			0x9D828F
# define TEXT_COL1			0xAF6C93
# define TEXT_COL2			0xD54E94
# define R_1				0xD873A0
# define R_2				0xA16785
# define R_3				0xAD6A91
# define R_4				0xDCAEB0
# define R_5				0xC5D2BF
# define DARK_R				0xCC2950

# define WINSIZEX			1500
# define WINSIZEY			1000
# define H_Y				775
# define BUFF				1000000
# define ANG_STEP			0.05
# define SHIFT_STEP			5
# define ZOOM_STEP			0.001
# define Z_KOEFF			5
# define DZ					0.1
# define W_XS				100
# define W_YS				794

# define KEY_ESC			53
# define KEY_H				4
# define KEY_T				17
# define KEY_I				34
# define KEY_SPACE			49
# define KEY_NUM_1			83
# define KEY_NUM_2			84
# define KEY_NUM_3			85
# define KEY_NUM_4			86
# define KEY_NUM_6			88
# define KEY_NUM_7			89
# define KEY_NUM_8			91
# define KEY_NUM_9			92
# define KEY_NUM_UP			126
# define KEY_NUM_DOWN		125
# define KEY_NUM_LEFT		123
# define KEY_NUM_RIGHT		124

typedef struct		s_pnt
{
	double			x;
	double			y;
	double			z;
	double			ang_x;
	double			ang_y;
	double			ang_z;
	int				color;
}					t_pnt;

typedef struct		s_val
{
	int				n;
	int				nums;
}					t_val;

typedef struct		s_curr
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	int				color;
}					t_curr;

typedef struct		s_cond
{
	int				help;
	int				special;
}					t_cond;

typedef struct		s_fdf
{
	double			ang_x;
	double			ang_y;
	double			ang_z;
	int				shift_x;
	int				shift_y;

	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*image;
	int				bpp;
	int				s_line;
	int				endian;
	char			*map_name;

	t_pnt			**pnt;
	t_pnt			**cur;
	t_cond			condition;

	t_curr			*curr;
	double			k;
	double			h_peek;
	int				kx;
	int				ky;
	int				dx;
	int				dy;
	int				hght;
	int				wdth;

	int				i;
	int				h;
	int				tmp;
	int				len;
	char			*lstr;
}					t_fdf;

int					fdf_open(int argc, char **argv, int *fd);
int					fdf_close(void *param);

int					fdf_read_file(int fd, t_fdf *fdf, char *map_name);
int					count_enters(char *buff, t_fdf *fdf);
int					read_first_line(char *buff, t_fdf *fdf);
void				fdf_count_numbers(char *str, int *len, t_fdf *fdf);

void				fdf_malloc_fdf(char *buff, t_fdf *fdf,
		char *map_name, int llen);
void				validate(char *buff, t_fdf *fdf);
void				fdf_init_subj(t_fdf *fdf, char *txt, char *buff, int llen);
void				fdf_pnt_init(t_fdf *fdf, int *i, int *len, char *buff);
void				fdf_set_coefficient(t_fdf *fdf);

int					fdf_color_peeks_deflt(int tmp);
int					color_pnt_deflt(t_fdf fdf, int i, int i0, int i1);
int					fdf_set_color(char *buff, int *len, int z, t_fdf *fdf);

int					fdf_color(t_fdf fdf, int start, int end);
int					color_pnt(t_fdf fdf, int start, int end);

void				fdf_error(void);
void				fdf_smthwrong(int n, t_fdf *fdf);
void				fdf_notvalid(t_fdf *fdf);
void				fdf_not_valid_col(t_fdf *fdf);

void				set_line(t_fdf fdf, int start, int end);
void				init_curr(t_fdf fdf, int start, int end);
double				ft_diff_double(double x0, double x1);
void				change_points(t_fdf fdf, int *s, int *e);

int					fdf_atoi(const char *str, int *len);
int					fdf_atoi_hex(const char *str, int *len, t_fdf *fdf);
int					fdf_blank(char ch);
double				fdf_doublebltoint(double nbr);

void				fdf_center(t_fdf *fdf);
void				fdf_move_to_center(t_fdf *fdf);

void				fdf_plot(t_fdf *fdf);
void				fdf_plot1pxl(t_fdf *fdf);
void				fdf_copy_in_cur(t_fdf *fdf);

int					fdf_key_press(int keycode, t_fdf *fdf);
int					fdf_check_key(int key);

void				fdf_rotate(int keycode, t_fdf *fdf);

void				fdf_eval_cur(t_fdf *fdf);
void				fdf_rotate_x(double *y, double *z, double ang);
void				fdf_rotate_y(double *x, double *z, double ang);
void				fdf_rotate_z(double *x, double *y, double ang);

void				fdf_shift(int key, t_fdf *fdf);
void				fdf_add_shift(t_fdf *fdf, int flag, int dx, int dy);

void				fdf_info_static0(t_fdf fdf);
void				fdf_info_static1(t_fdf fdf);
void				fdf_info_help(t_fdf fdf);

void				fdf_plot_isometry(t_fdf *fdf);
void				fdf_plot_top_view(t_fdf *fdf);
void				fdf_plot_front_view(t_fdf *fdf);
void				fdf_change_height(t_fdf *fdf, int key);

void				skip_char(char *str, int *len, char ch);
int					norm_sign(char c);
double				distance(double x0, double y0, double x1, double y1);
void				swap(int *a, int *b);

#endif
