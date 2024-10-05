#include "playground.h"

void	print_img(t_img *img)
{
	int	i;

	i = 0;
	printf("Memory Addr: %p\n", img -> img);
	printf("Data addr: ");
	while (i < (img -> size_line * img -> bits))
		printf("%d", img -> addr[i++]);
	printf("\n");
	printf("Bit depth: %d\n", img -> bits);
	printf("Line size: %d\n", img -> size_line);
	printf("Endian: %d\n", img -> endian);
}

void	edit_image(t_img *img, int x, int y, int color)
{
	char	*start;

	start = img -> addr + (y * img -> size_line + x * (img -> bits / 8));
	*(unsigned int *)start = color;
}

// int	argb(int a, int r, int g, int b)
// {
// 	return (a << 24 | r << 16 | g << 8 | b);
// }

// int	red(int argb)
// {
// 	return (argb >> 16 & 0xFF);
// }

void	make_rtriangle(t_img *img, int base, int height)
{
	int	x;
	int	y;

	x = base;
	y = height;
	while (x--)
		edit_image(img, x, height, 0x00FF00FF);
	while (y--)
		edit_image(img, base, y, 0x00FFFF00);
	x = 0;
	y = height;
	while (y--)
		edit_image(img, x++, y, 0x0000FFFF);
}

void	sl_clear_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < (img -> size_line * img -> bits))
	{
		img -> addr[i] = 0; 
		i++;
	}
}

void	make_rect(t_img *img, int x, int y)
{
	int	xi;
	int	yi;

	xi = x;
	yi = y;
	while (yi)
	{
		while (xi)
			edit_image(img, xi--, yi, 0x0000FFFF);
		yi--;
		xi = x;
	}
}

int main(void)
{
	void	*mlx;
	void	*window;
	int		x = 600;
	int		y = 600;
	t_img	*img;

	mlx = mlx_init();
	if (!mlx)
		return (-1);
	img = malloc(sizeof(t_img));

	window = mlx_new_window(mlx, x, y, "I am a square");
	
	img -> img = mlx_new_image(mlx, x, y);
	img -> addr = mlx_get_data_addr(img -> img, &img -> bits, &img -> size_line, &img -> endian);
	// make_rtriangle(img, 50, 50);>
	// make_rtriangle(img, 100, 100);
	// mlx_put_image_to_window(mlx, window, img -> img, x /2 , y / 2);
	int rows = 1;
	int	cols = 1;
	make_rect(img, HEIGHT, WIDTH);
	while (cols <= 5)
	{
		while (rows <= 5)
		{
			mlx_put_image_to_window(mlx, window, img -> img, WIDTH * rows, HEIGHT * cols);
			rows++;
		}
		cols++;
		rows = 1;
	}

	mlx_loop(mlx);
	mlx_destroy_image(mlx, img -> img);
	mlx_destroy_window(mlx, window);
	free(img);

	return (0);
}
