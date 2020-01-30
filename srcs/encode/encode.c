/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   encode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 03:39:56 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 14:26:13 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libbmp.h"

static t_bmp	*encode(t_uchar *img, int width, int height)
{
	t_bmp	*bmp;

	if (!(bmp = init_bmp(height)))
		return (NULL);
	fill_headers(bmp, width, height);
	if (!(fill_imagedata(bmp, img, width, height)))
		return (NULL);
	return (bmp);
}

int				export_as_bmp(char *path, t_uchar *img,
				int width, int height)
{
	t_bmp	*bmp;

	if (width >= 8001 || height >= 8001)
		return (0);
	if (!(bmp = encode(img, width, height)))
		return (0);
	bmp->fd = open(path, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (bmp->fd == -1)
		return (-1);
	write_headers(bmp);
	if (!(write_rgb(bmp)))
		return (0);
	close(bmp->fd);
	destroy_bmp(bmp);
	return (1);
}
