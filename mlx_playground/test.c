#include "playground.h"

#define BG_COL 0X00C5FF

int	draw_bg_over_alpha(void *mlx, void *img, int colour)
{
	for every pixel in the image
	if pixel is not alpha
		- 0XFFF000000000 is alpha
	change the pixel to the colour we specify
}