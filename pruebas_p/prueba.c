#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../MLX42/include/MLX42/MLX42.h"

#include <string.h>

void	handle(void *param)
{
	if (mlx_is_key_down((mlx_t *)param, MLX_KEY_ESCAPE))
		mlx_close_window((mlx_t *)param);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	mlx_image_t		*img, *recorte;
	mlx_texture_t	*tex;

	if (argc != 2)
		return (1);
	if ((mlx = mlx_init(320, 320, "Poronga", 0)) == NULL)
		return (perror("poronga"), 1);
/* 	if ((img = mlx_new_image(mlx, 320, 320)) == NULL)
		return (perror("poronga_img"), 1); */
	if ((tex = mlx_load_png(argv[1])) == NULL)
		return (perror("poronga_textura"), 1);
	img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	mlx_image_to_window(mlx, img, 0, 0);



	if ((recorte = mlx_new_image(mlx, 212, 20)) == NULL)
		return (perror("poronga_img"), 1);

	memcpy(recorte->pixels, img->pixels, sizeof(uint32_t) * recorte->width * recorte->height);
	mlx_image_to_window(mlx, recorte, 0, 250);

	mlx_loop_hook(mlx, &handle, mlx);
	mlx_loop(mlx);
	return (0);
}