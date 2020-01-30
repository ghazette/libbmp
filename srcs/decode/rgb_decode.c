/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rgb_decode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:42:40 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 13:24:11 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libbmp.h"

static unsigned char	*concat_row(t_bmp *bmp, unsigned char **img_arr)
{
	unsigned char	*ret;
	int				len;
	t_uint			i;
	int				j;
	int				k;

	k = 0;
	i = 0;
	len = bmp->info_header->width * 4;
	if (!(ret = malloc(bmp->info_header->width * bmp->info_header->height * 4)))
		return (NULL);
	while (i < bmp->info_header->height)
	{
		j = 0;
		while (j < len)
		{
			ret[k] = img_arr[i][j];
			k++;
			j++;
		}
		i++;
	}
	return (ret);
}

static unsigned char	*get_row(t_bmp *bmp, unsigned char *img)
{
	unsigned char	*ret;
	int				len;
	int				alloc;
	int				i;
	int				j;

	j = 0;
	i = 0;
	len = (bmp->info_header->width * 3);
	alloc = (bmp->info_header->width * 4);
	if (!(ret = malloc(alloc)))
		return (NULL);
	while (j < len)
	{
		ret[i] = img[j];
		ret[i + 1] = img[j + 1];
		ret[i + 2] = img[j + 2];
		ret[i + 3] = 0;
		j += 3;
		i += 4;
	}
	return (ret);
}

int						get_imagedata(t_bmp *bmp)
{
	int				i;
	unsigned char	**readed;
	unsigned char	*buffer;
	unsigned char	pad[4];

	i = bmp->info_header->height - 1;
	if (!(readed = (unsigned char**)malloc(sizeof(unsigned char*) *
	(bmp->info_header->height + 1))))
		return (0);
	if (!(buffer = malloc((bmp->info_header->width * 3))))
		return (0);
	readed[bmp->info_header->height] = 0;
	while (i != -1)
	{
		if (read(bmp->fd, buffer, (bmp->info_header->width * 3)))
			readed[i] = get_row(bmp, buffer);
		if (bmp->padding > 0)
			read(bmp->fd, pad, bmp->padding);
		i--;
	}
	free(buffer);
	if (!(bmp->data_decode = concat_row(bmp, readed)))
		return (0);
	free2d(&readed);
	return (1);
}
