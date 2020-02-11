#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../includes/mlx.h"
# include "../libft/includes/libft.h"

# define P_START			fdf.cur[start - 1]
# define P_END				fdf.cur[end - 1]

# define WHITE				0xFFFFFF
# define BLACK				0x000000
# define WINE				0xAB271D
# define ROSE				0x9D788F
# define DEF_COL			0xC488AC
# define TEXT_COL0			0x9D828F
# define TEXT_COL1			0xAF6C93
# define TEXT_COL2			0xD54E94

# define WINSIZEX			2000
# define WINSIZEY			1500
# define H_Y				WINSIZEX - 200
# define BUFF				1000000
# define ANG_STEP			0.05
# define SHIFT_STEP			5
# define ZOOM_STEP			0.001
# define Z_KOEFF			5
# define DZ					0.5

# define KEYBOARD			1
# define MOUSE				2
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_BUTTON_MID	3
# define KEY_ESC			53
# define KEY_H				4
# define KEY_T				17
# define KEY_Z				6
# define KEY_X				7
# define KEY_I				34
# define KEY_R				15
# define KEY_G				5
# define KEY_B				11
# define KEY_SPACE			49
# define KEY_PLUS			69
# define KEY_MINUS			78
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

typedef struct	s_pnt
{
	double	x;
	double	y;
	double	z;
	double	ang_x;
	double	ang_y;
	double	ang_z;
	int		color;
}				t_pnt;

typedef struct	s_val
{
	int		n;
	int		nums;
}				t_val;

typedef struct	s_curr
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	int		color;
}				t_curr;

typedef struct	s_cond
{
	int		help;
}				t_cond;

typedef struct	s_fdf
{
	double	ang_x;
	double	ang_y;
	double	ang_z;
	int		shift_x;
	int		shift_y;

	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*image;
	int		bpp;
	int		s_line;
	int		endian;
	char	*map_name;

	t_pnt	**pnt;
	t_pnt	**cur;
	t_cond	condition;

	t_curr	*curr;
	double	k;
	double	h_peek;
	int		kx;
	int		ky;
	int		dx;
	int		dy;
	int		hght;
	int		wdth;

	int		i;
	int		h;
}				t_fdf;

int			fdf_open(int argc, char **argv, int *fd);
int			fdf_close(void *param);

int			fdf_read_file(int fd, t_fdf *fdf, char *map_name);
int			count_enters(char *buff);
int			read_first_line(char *buff);
void		fdf_count_numbers(char *str, int *len);
int			norm_sign(char c);

void		fdf_malloc_fdf(char *buff, t_fdf *fdf, char *map_name);
void		validate(char *buff, t_fdf *fdf, int nums);
void		fdf_init_subj(t_fdf *fdf, char *txt, char *buff);
void		fdf_copy_in_cur(t_fdf *fdf);
void		fdf_set_coefficient(t_fdf *fdf);

int			fdf_color_peeks_deflt(int tmp);
int			color_pnt_deflt(t_fdf fdf, int i, int i0, int i1);

int			fdf_color(t_fdf fdf, int start, int end);
int			color_pnt(t_fdf fdf, int start, int end);

void		fdf_error();
void		fdf_smthwrong();
void		fdf_notvalid();

void		fdf_swap(double *a, double *b, double *d, double *e);
void		fdf_br_init(t_fdf *fdf, int start, int end);
void		plot_line_br(t_fdf fdf, int i0, int i1);
void		set_line(t_fdf fdf, int start, int end);

int			fdf_atoi(const char *str, int *len);
int			fdf_atoi_hex(const char *str);
int			fdf_blank(char ch);
double		fdf_doublebltoint(double nbr);

void		fdf_center(t_fdf *fdf);
void		fdf_move_to_center(t_fdf *fdf);

void		fdf_plot(t_fdf *fdf);

int			fdf_key_press(int keycode, t_fdf *fdf);
int			fdf_check_key(int key);

void		fdf_rotate(int keycode, t_fdf *fdf);

void		fdf_eval_cur(t_fdf *fdf);
void		fdf_rotate_x(double *y, double *z, double ang);
void		fdf_rotate_y(double *x, double *z, double ang);
void		fdf_rotate_z(double *x, double *y, double ang);

void		fdf_shift(int key, t_fdf *fdf);
void		fdf_add_shift(t_fdf *fdf, int flag, int dx, int dy);

void		fdf_info_static0(t_fdf fdf);
void		fdf_info_static1(t_fdf fdf);
void		fdf_info_help(t_fdf fdf);

void		fdf_plot_isometry(t_fdf *fdf);
void		fdf_plot_top_view(t_fdf *fdf);
void		fdf_plot_front_view(t_fdf *fdf);
void		fdf_change_height(t_fdf *fdf, int key);

# endif
