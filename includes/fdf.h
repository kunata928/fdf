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
# define BUFF 10000

typedef struct	s_pnt
{
	int x;
	int y;
	int z;
	int color;
}				t_pnt;

typedef struct	s_lst
{
	int		z;
	t_list	*next;
}				t_lst;

typedef struct	s_val
{
	int n;
	int nums;
}				t_val;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_pnt	**pnt;
	float	k;
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

void		print_line_br(t_fdf *fdf, t_pnt xy0, t_pnt xy1);

int			fdf_read_file(char *txt, t_fdf *fdf);
void		validate(char *buff, t_fdf *fdf, int nums);
int			count_enters(char *buff);
int			read_first_line(char *buff);
void		fdf_malloc_fdf(char *buff, t_fdf *fdf);
void		fdf_count_numbers(char *str, int *len);
int			norm_sign(char c);

int			fdf_atoi(const char *str, int *len);
int			fdf_blank(char ch);

void		fdf_print_net(t_fdf *fdf);
void		print_0(t_fdf *fdf);

# endif
