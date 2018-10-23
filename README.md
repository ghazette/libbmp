# libBMP 1.1

**Description**

> Cette librairie a été conçue dans le but d'utiliser l'**importation** et
> l'**exportation** d'image simple, uniquement en **.bmp** et en **24 bits** uniquement,
>  chaque pixel est codé sur 4 octets
> **Cette librairie est 100% compatible avec la minilibx d'Epitech/42.**


**Installation**

>  1. Cloner le repo (branche **master**).
>  2. **make** pour compiler la librairie.
>  3. inclure le header **libbmp.h (dossier includes)**  dans votre projet.
>  4. compiler votre projet en n'oubliant pas d'inclure la librairie **libbmp.a**

**Documentations**

> char						***import_bmp**(char ***path**, size_t ***width**, size_t ***height**);
>
>
>  1. **path** est le chemin du fichier a ouvrir.
>  2. ***width**, retourne la largeur de l'image.
>  3. ***height**, retourne la hauteur de l'image.
>  4. **return**, renvoie la chaîne formatée, aucune manipulation supplémentaire a réalisé (voir exemple plus bas) ou NULL en cas d’échec.

> int **export_as_bmp**(char ***path**, char ***img**, int **width**, int **height**);

>  1. **path** est le chemin de sauvegarde du fichier.
>  2. ***img**, votre image mlx.
>  3. **width**, la largeur de votre image.
>  4. **height**, la hauteur de votre image.
>  5. **return**, 0 en cas d’échec, 1 en cas de réussite.

**Futurs Améliorations**
 - > Calcule automatique de la taille de l'image lors de l'exportation de l'image.
 - > *N’hésitez pas à soumettre vos idées !*

**Améliorations intégrées**
 - > Retourner la largeur et hauteur lors de l'importation de l'image
   > (permet la création a la volée d'image mlx)

**Galerie**

    exemple d'importation et d'utilisation basique de l'image

> ![Importation image BMP24Bits](https://pasteboard.co/images/HJaCDK0.png/load)

    resultat
> ![resultat](https://pasteboard.co/images/HJaFh38.png/load)
    exemple d'exportation d'une image mlx

> ![Exportation en BMP24Bits](https://image.noelshack.com/fichiers/2018/15/7/1523751140-tuto.png)

**Contact**

> ghazette@student.le-101.fr
