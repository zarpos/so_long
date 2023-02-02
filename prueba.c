#include <stdlib.h>
#include <mlx.h>

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "hola");
	mlx_destroy_window(mlx_ptr, win_ptr);
//	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
