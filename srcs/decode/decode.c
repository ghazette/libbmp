/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   decode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 19:10:27 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:25:54 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libbmp.h"

static t_bmp	*decode(char *path)
{
	t_bmp *bmp;

	if (!(bmp = init_bmp(0)))
		return (NULL);
	if ((bmp->fd = open(path, O_RDONLY)) == -1)
	{
		destroy_bmp(bmp);
		return (NULL);
	}
	decode_bmp_file_header(bmp);
	decode_bitmap_info_header(bmp);
	if (check_header(bmp))
	{
		if (!(get_imagedata(bmp)))
			return (NULL);
	}
	else
		return (NULL);
	close(bmp->fd);
	return (bmp);
}

t_uchar	*import_bmp(char *path,
				size_t *width, size_t *height)
{
	t_bmp			*bmp;
	t_uchar	*ret;

	if (!(bmp = decode(path)))
		return (NULL);
	*width = bmp->info_header->width;
	*height = bmp->info_header->height;
	ret = bmp->data_decode;
	destroy_bmp(bmp);
	return (ret);
}
