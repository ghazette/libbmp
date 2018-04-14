/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:52:25 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:30:31 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libbmp.h"

void	fill_headers(t_bmp *bmp, int width, int height)
{
	int len;
	int mod;

	len = height * width * 3;
	mod = width % 4;
	if (mod > 0)
		len += width * mod;
	bmp->padding = mod;
	bmp->file_header->signature[0] = 'B';
	bmp->file_header->signature[1] = 'M';
	bmp->file_header->totalsize = len + 54;
	bmp->file_header->offset = 54;
	bmp->info_header->bm_headersize = 40;
	bmp->info_header->imagesize = len;
	bmp->info_header->hres = 3780;
	bmp->info_header->vres = 3780;
	bmp->info_header->width = width;
	bmp->info_header->height = height;
	bmp->info_header->planes_number = 1;
	bmp->info_header->ncolors = 0;
	bmp->info_header->nimpcolors = 0;
	bmp->info_header->bpp = 24;
	bmp->info_header->compression_type = 0;
}

void	write_headers(t_bmp *bmp)
{
	unsigned char buffer[54];

	buffer[0] = bmp->file_header->signature[0];
	buffer[1] = bmp->file_header->signature[1];
	number_to_bytes(bmp->file_header->totalsize, buffer + 2, 4);
	number_to_bytes(0, buffer + 6, 4);
	number_to_bytes(bmp->file_header->offset, buffer + 10, 4);
	number_to_bytes(bmp->info_header->bm_headersize, buffer + 14, 4);
	number_to_bytes(bmp->info_header->width, buffer + 18, 4);
	number_to_bytes(bmp->info_header->height, buffer + 22, 4);
	number_to_bytes(bmp->info_header->planes_number, buffer + 26, 2);
	number_to_bytes(bmp->info_header->bpp, buffer + 28, 2);
	number_to_bytes(bmp->info_header->compression_type, buffer + 30, 4);
	number_to_bytes(bmp->info_header->imagesize, buffer + 34, 4);
	number_to_bytes(bmp->info_header->hres, buffer + 38, 4);
	number_to_bytes(bmp->info_header->vres, buffer + 42, 4);
	number_to_bytes(bmp->info_header->ncolors, buffer + 46, 4);
	number_to_bytes(bmp->info_header->nimpcolors, buffer + 50, 4);
	write(bmp->fd, buffer, 54);
}
