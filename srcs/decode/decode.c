/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   decode.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 19:10:27 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:27:51 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

/*
** Une fois l'image decode les pixels sont stocker un a un dans une liste
** chainee dans bmp->data
*/

t_bmp	*decode(const char *path)
{
	t_bmp *bmp;

	if (!(bmp = init_bmp()))
		return (NULL);
	if ((bmp->fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	decode_bmp_file_header(bmp);
	decode_bitmap_info_header(bmp);
	if (check_header(bmp))
		get_imagedata(bmp);
	else
		return (NULL);
	close(bmp->fd);
	return (bmp);
}
