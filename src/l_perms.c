/*****************************************************************************/
/*                         FT_LS permission managment                         */
/*****************************************************************************/

#include "l_perms.h"

/*
** get perms using stat macros
** fill perm array
*/
char *
l_get_mode(struct stat * buf)
{
    char permsbuf[9] = "---------";
    char ftype = '?';

    if (S_ISREG(buf->st_mode)) ftype = '-';
    if (S_ISLNK(buf->st_mode)) ftype = 'l';
    if (S_ISDIR(buf->st_mode)) ftype = 'd';
    if (S_ISBLK(buf->st_mode)) ftype = 'b';
    if (S_ISCHR(buf->st_mode)) ftype = 'c';
    if (S_ISFIFO(buf->st_mode)) ftype = '|';

    ft_sprintf(permsbuf, "%c%c%c%c%c%c%c%c%c%c %c%c", ftype,
               buf->st_mode & S_IRUSR ? 'r' : '-',
               buf->st_mode & S_IWUSR ? 'w' : '-',
               buf->st_mode & S_IXUSR ? 'x' : '-',
               buf->st_mode & S_IRGRP ? 'r' : '-',
               buf->st_mode & S_IWGRP ? 'w' : '-',
               buf->st_mode & S_IXGRP ? 'x' : '-',
               buf->st_mode & S_IROTH ? 'r' : '-',
               buf->st_mode & S_IWOTH ? 'w' : '-',
               buf->st_mode & S_IXOTH ? 'x' : '-',
               buf->st_mode & S_ISUID ? 'U' : '-',
               buf->st_mode & S_ISGID ? 'G' : '-');

    return (ft_strdup(permsbuf));
}
