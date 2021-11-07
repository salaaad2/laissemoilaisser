/*****************************************************************************/
/*           FT_LS BY salad, execute stuff after parsing arguments           */
/*****************************************************************************/


#include "e_open.h"

#include <sys/stat.h>

int e_open(t_elem * elem)
{
    t_elem * node = elem;
    struct dirent *de;
    struct stat buf;
    int exists;
    DIR *d;

    while (node)
    {
        d = opendir((char*)node->content);
        if (d == NULL)
        {
            ft_dprintf(2, "ls: %s: unable to open\n", (char*)node->content);
            return (1);
        }
        de = readdir(d);
        while (de != NULL)
        {
            exists = stat(de->d_name, &buf);
            if (exists < 0) {
                ft_dprintf(2, "ls: %s: File not found\n", de->d_name);
            } else if (S_ISDIR(buf.st_mode)) {
                ft_printf("%10ld %s/\n", buf.st_size, de->d_name);
            } else if (S_ISDIR(buf.st_mode)) {
                ft_printf("%10ld %s/\n", buf.st_size, de->d_name);
            } else if (S_ISLNK(buf.st_mode)) {
                ft_printf("%10ld %s@\n", buf.st_size, de->d_name);
            } else if (buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
                ft_printf("%10ld %s@\n", buf.st_size, de->d_name);
            } else {
                ft_printf("%10ld %s\n", buf.st_size, de->d_name);
            }
            de = readdir(d);
        }
        node = node->next;
    }
    return (0);
}
