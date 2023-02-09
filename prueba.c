#include <stdlib.h>
#include <mlx.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int x;
	int y;

	x = 1;

	y = 1;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "hola");
	while (x < 500)
		mlx_pixel_put(mlx_ptr, win_ptr, x++, y++, 0xFF00);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
//	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
