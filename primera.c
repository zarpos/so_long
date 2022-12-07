#include <mlx.h>
#include <math.h>

// To compile after gcc put: -Lmlx -lmlx -framework OpenGL -framework AppKit


typedef struct s_data  {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*
int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx =  mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Mi ventana");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
*/

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX -beginX;
    double deltaY = endY -beginY;
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    double pixelX = beginX;
    double pixelY = beginY;

    deltaX /= pixels;
    deltaY /= pixels;
    while (pixels)
    {
        mlx_pixel_put(mlx, win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return 0;
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Line");

    draw_line(mlx, win, 640, 360, 0, 0, 0xFFFFFF);

    mlx_loop(mlx);
}
