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
# define WINSIZE			1000
# define WINZERO			WINSIZE/4
# define BUFF				1000000

# define KEYBOARD			1
# define MOUSE				2
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_BUTTON_MID	3
# define KEY_ESC			53
# define KEY_CTRL_LEFT		256
# define KEY_SHIFT_LEFT		257
# define KEY_F				3
# define KEY_H				4
# define KEY_S				1
# define KEY_Z				6
# define KEY_X				7
# define KEY_I				34
# define KEY_T				17
# define KEY_E				14
# define KEY_R				15
# define KEY_G				5
# define KEY_B				11
# define KEY_Q				12
# define KEY_W				13
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
	double x;
	double y;
	double z;
	double ang_x;
	double ang_y;
	double ang_z;
	int color;
}				t_pnt;

typedef struct	s_val
{
	int n;
	int nums;
}				t_val;

typedef struct	s_curr
{
	double		x;
	double		y;
}				t_curr;

typedef struct	s_fdf
{
	double	ang_x;
	double	ang_y;
	double	ang_z;
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*image;
	int		bpp;
	int		s_line;
	int		endian;
	t_pnt	**pnt;
	t_pnt	**cur;
	t_pnt	curr;
	float	k;
	float	kx;
	float	ky;
	int		hght;
	int		wdth;
	int		i;
	int		j;
	int		w;
	int		h;
}				t_fdf;

typedef struct	s_br
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	int		error;
	int		dif;
	int		ystep;
}				t_br;

void		fdf_error();
void		fdf_smthwrong();
void		fdf_notvalid();

void		fdf_swap(double *a, double *b, double *d, double *e);
void		fdf_br_init(t_br *br, t_pnt xy0, t_pnt xy1);
void		plot_line_br(t_fdf *fdf, int i0, int i1);

int			fdf_read_file(char *txt, t_fdf *fdf);
void		validate(char *buff, t_fdf *fdf, int nums);
int			count_enters(char *buff);
int			read_first_line(char *buff);
void		fdf_malloc_fdf(char *buff, t_fdf *fdf);
void		fdf_count_numbers(char *str, int *len);
int			norm_sign(char c);

int			fdf_atoi(const char *str, int *len);
int			fdf_atoi_hex(const char *str);
int			fdf_blank(char ch);
double		fdf_doublebltoint(double nbr);

void		fdf_print_net(t_fdf *fdf);
void		print_0(t_fdf *fdf);

void		fdf_plot(t_fdf *fdf);

void		fdf_key_press(int keycode, t_fdf *fdf);
int			fdf_check_key(int key);

# endif
