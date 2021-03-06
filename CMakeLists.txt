cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 99)
link_directories(minilibx)

include_directories(fdf/includes)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCES srcs/main.c srcs/fdf_read.c srcs/fdf_error.c
		srcs/fdf_atoi.c
		srcs/fdf_plot.c srcs/fdf_plot_line.c srcs/matrix_operations.c
		srcs/fdf_keyboard.c srcs/fdf_rotate.c srcs/fdf_init.c
		srcs/fdf_center.c srcs/fdf_color.c srcs/fdf_shift_zoom.c
		srcs/fdf_color_gradient.c srcs/fdf_menu.c srcs/fdf_open_close.c
		srcs/fdf_isometry.c srcs/help_func.c)

set(HEADERS includes/fdf.h includes/mlx.h)

set(LIBMLX minilibx/libmlx.a)

add_executable(fdf ${SOURCES} ${HEADERS} ${LIBMLX})

add_subdirectory(libft minilibx)

target_link_libraries(fdf mlx ${OPEN_GL} ${APP_KIT} libft)