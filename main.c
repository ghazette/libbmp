#include "includes/libbmp.h"
#include "minilibx/mlx.h"
#define SIZE 200

char  *img(int w, int h)
{
  char *map;
  int len = w*h*4;
  int i = 0;

  map = malloc(len);
  while (i < len)
  {
    map[i] = 0;
    map[i + 1] = 0;   //Green
    map[i + 2] = 255; //Red
    map[i + 3] = 0;   //Alpha (opacity)
    i += 4;
  }
  return map;
}

int main()
{
  char *map;
  size_t size;
  int i= 0;
  int bpp, cc, a;
   void *mlx= mlx_init();
   void *win=mlx_new_window(mlx, 800, 800, "prout");
  //map = img(SIZE, SIZE);
  //export_as_bmp("test.bmp", map, SIZE, SIZE);
  map = import_bmp("test.bmp", &size);
  void *ptr = mlx_new_image(mlx, 600, 316);
  char *img = mlx_get_data_addr(ptr, &bpp, &cc, &a);
  while (i < size)
  {
    img[i] = map[i];
    i++;
  }
  mlx_put_image_to_window(mlx, win, ptr, 0, 0);
  mlx_loop(mlx);
}
