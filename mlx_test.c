
// -------------------------------------DOCUMENTATION------------------------------------------------ //

// To compile the minilibx use < gcc -lmlx -framework OpenGL -framework Appkit  >

// Returns a (void *) to the beginning of the window, so whe should create a variable to store the return vaule and use it as the *mlx_ptr
void *mlx_init();

// Here we open our first window;
void *mlx_new_window(void *mlx_ptr, int WINDOW_WIDTH, int WINDOW_HEIGHT, char *title);

// Avoids to just open anc close the window instantly, the loop keeps the window open.
int mlx_loop(void *mlx_ptr);

// Returns a void * to use it as reference to modify the image later ;) 
void *mlx_new_image(void *mlx_ptr, int width, int height);

// Writes pixels in the window.
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

// 
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

//
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

//
unsigned int mlx_get_color_value(void *mlx_ptr, int color);

//
void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

//
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

// As the name says, it destroys the window.
void *mlx_destroy_window(void *mlx_ptr, void *win_ptr);

// This function terminates to free all the program, as the display opened before is the last element using memory.
int mlx_destroy_display(void *mlx_ptr);
// ------------------------------------------------------------------------------------------------- //
