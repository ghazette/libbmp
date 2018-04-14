#include "includes/bitmap.h"
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
  //map = img(SIZE, SIZE);
  //export_as_bmp("test.bmp", map, SIZE, SIZE);
  map = import_bmp("test.bmp", &size);
  free(map);
}
