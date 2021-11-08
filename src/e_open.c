/*****************************************************************************/
/*           FT_LS BY salad, execute stuff after parsing arguments           */
/*****************************************************************************/


#include "e_open.h"

#include <sys/stat.h>
#include <errno.h>
#include <string.h>

   /*
    ** linked list elem contains each non-option parameter
    ** we go through it and use opendir/ readdir to get elements and
    ** then stat each element to get their mode.
    ** display differs between different file modes
    */

int
e_open(t_elem * elem, t_opts * opts)
{
    t_elem * node = elem;
    struct dirent *de;
    struct stat buf;
    int exists;
    DIR *d;

    while (node != NULL)
    {
        d = opendir((char*)node->content);
        if (d == NULL) {
            ft_dprintf(2, "ls: %s: unable to open%s\n", (char*)node->content, strerror(errno));
            continue;
        }

        while ((de = readdir(d)) != NULL)
        {
            exists = stat(de->d_name, &buf);
            if (exists < 0) {
                ft_dprintf(2, "ls: %s: File not found %s\n", de->d_name, strerror(errno));
            } else if (de->d_name[0] == '.' &&
                       ft_strlen(de->d_name) != 1 &&
                       opts->hidden == FALSE) { /* skip entry if file is hidden */
                continue;
            } else if (S_ISDIR(buf.st_mode)) {
                if (opts->recursive == FALSE)
                    ft_printf("%10lld %s/\n", buf.st_size, de->d_name);
            } else if (S_ISDIR(buf.st_mode)) {
                ft_printf("%10lld %s/\n", buf.st_size, de->d_name);
            } else if (S_ISLNK(buf.st_mode)) {
                ft_printf("%10lld %s@\n", buf.st_size, de->d_name);
            } else if (buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
                ft_printf("%10lld %s@\n", buf.st_size, de->d_name);
            } else {
                ft_printf("%10lld %s\n", buf.st_size, de->d_name);
            }
        }
        closedir(d);
        node = node->next;
    }
    return (0);
}
