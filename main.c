#include "includes/bitmap.h"
#define SIZE 8000

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

  map = img(SIZE, SIZE);
  export_as_bmp("test.bmp", map, SIZE, SIZE);
  free(map);
  while (1)
  {
    sleep(1);
  }
}
