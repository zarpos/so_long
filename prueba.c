#include <stdlib.h>
#include <mlx.h>
#define GREEN 0xFF00 
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

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

int rend_rect(t_data *data, t_rect rect)
{
	int i;
	int j;

	if (data->win_ptr == NULL)
		return 1;
	i = rect.y;
	while (i < rect.height + rect.y)
	{
		j = rect.x;
		while (j < rect.width + rect.x)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		i++;
	}
	return 0;
}

int rend_background(t_data *data, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0xFFFFFF);
		i++;
	}
	return 0;
}

int render(t_data *data)
{
	rend_background(data, 0xFFFFFF);
	rend_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT -100, 100, 100, GREEN});
	rend_rect(data, (t_rect){0, 0, 100, 100, GREEN});
	return 0;
}

int main()
{
	t_data data;
	t_rect rect;
	
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "hola");
	
	rect.x = 5;
	rect.y = 5;
	rect.width = 500;
	rect.height = 300;
	rect.color = GREEN;

//	rend_rect(&data, rect);
	render(&data);
	mlx_loop(data.mlx_ptr);
	return 0;
}

/*
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
}*/
