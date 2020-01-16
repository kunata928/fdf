#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../includes/mlx.h"
# include "../libft/includes/libft.h"

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define WINE 0xAB271D
# define WINSIZE 1000
# define WINZERO WINSIZE/4
# define BUFF 1000000

typedef struct	s_pnt
{
	int x;
	int y;
	int z;
	int color;
}				t_pnt;



typedef struct	s_val
{
	int n;
	int nums;
}				t_val;

typedef struct	s_curr
{
	int		x;
	int		y;
}				t_curr;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*image;
	int		bpp;
	int		s_line;
	int		endian;
	t_pnt	**pnt;
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
	int x;
	int y;
	int dx;
	int dy;
	int error;
	int dif;
	int ystep;
}				t_br;

void		fdf_error();
void		fdf_smthwrong();
void		fdf_notvalid();

void		fdf_swap(int *a, int *b, int *d, int *e);
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

void		fdf_print_net(t_fdf *fdf);
void		print_0(t_fdf *fdf);

void		fdf_plot(t_fdf *fdf);

# endif
