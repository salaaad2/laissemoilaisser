/*****************************************************************************/
/*                         FT_LS permission managment                         */
/*****************************************************************************/

#include "l_perms.h"

/*
** get perms using stat macros
** fill perm array
*/
char *
l_get_mode(t_elem * node, t_file * f)
{
    char * permsbuf = "---------";
    t_file * tmp = node->head;
    char ftype = '?';


  if (S_ISREG(f->buf.st_mode)) ftype = '-';
  if (S_ISLNK(f->buf.st_mode)) ftype = 'l';
  if (S_ISDIR(f->buf.st_mode)) ftype = 'd';
  if (S_ISBLK(f->buf.st_mode)) ftype = 'b';
  if (S_ISCHR(f->buf.st_mode)) ftype = 'c';
  if (S_ISFIFO(f->buf.st_mode)) ftype = '|';

  ft_sprintf(permsbuf, "%c%c%c%c%c%c%c%c%c%c %c%c%c", ftype,
            f->buf.st_mode & S_IRUSR ? 'r' : '-',
            f->buf.st_mode & S_IWUSR ? 'w' : '-',
            f->buf.st_mode & S_IXUSR ? 'x' : '-',
            f->buf.st_mode & S_IRGRP ? 'r' : '-',
            f->buf.st_mode & S_IWGRP ? 'w' : '-',
            f->buf.st_mode & S_IXGRP ? 'x' : '-',
            f->buf.st_mode & S_IROTH ? 'r' : '-',
            f->buf.st_mode & S_IWOTH ? 'w' : '-',
            f->buf.st_mode & S_IXOTH ? 'x' : '-',
            f->buf.st_mode & S_ISUID ? 'U' : '-',
            f->buf.st_mode & S_ISGID ? 'G' : '-',
            f->buf.st_mode & S_ISVTX ? 'S' : '-');

  return (permsbuf);
}
