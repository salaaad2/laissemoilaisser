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
    char full[4096 + 4096];

    while (node != NULL)
    {
        ft_bzero(node->outbuf, sizeof(node->outbuf));
        d = opendir((char*)node->content);
        if (d == NULL) {
            ft_dprintf(2, "ls: %s: unable to open%s\n", (char*)node->content, strerror(errno));
            continue;
        }

        while ((de = readdir(d)) != NULL)
        {
          if (ft_strcmp(elem->content, ".") != 0) {
              ft_sprintf(elem->path, "%s/", (char *)elem->content);
              ft_sprintf(elem->name, "%s", (char *)de->d_name);
              ft_sprintf(full, "%s/%s", elem->path, elem->name);
          } else {
              ft_sprintf(elem->name, "%s", (char *)de->d_name);
              ft_sprintf(full, "%s", elem->name);
          }
          exists = stat(full, &buf);
          if (exists  < 0) {
            ft_dprintf(2, "ls: %s: File not found %s\n", de->d_name,
                       strerror(errno));
          } else if (elem->name[0] == '.' &&
                     opts->hidden == FALSE) { /* skip entry if file is hidden */
            continue;
          } else if (S_ISDIR(buf.st_mode)) {
            if (opts->recursive == FALSE)
              ft_sprintf(node->outbuf, "%s %s ", node->outbuf, elem->name);
          } else if (S_ISLNK(buf.st_mode)) {
            ft_sprintf(node->outbuf, "%s %s ", node->outbuf, elem->name);
          } else if (buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            ft_sprintf(node->outbuf, "%s %s ", node->outbuf, elem->name);
          } else {
            ft_sprintf(node->outbuf, "%s %s ", node->outbuf, elem->name);
          }
        }
        ft_dprintf(1, "%s\n", node->outbuf);
        closedir(d);
        node = node->next;
    }
    return (0);
}
