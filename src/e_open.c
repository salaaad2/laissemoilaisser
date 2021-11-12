/*****************************************************************************/
/*            FT_LS BY salad, execute stuff after parsing arguments          */
/*****************************************************************************/

#include "e_open.h"
#include "u_lstact.h"
#include "l_perms.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int
l_handle_file(t_elem * node, t_opts * opts, DIR *d, struct dirent *de)
{
    (void)node;
    (void)opts;
    (void)d;
    (void)de;
    return (0);
}

int
l_handle_dir(t_elem * node, t_opts *opts, DIR *d, struct dirent *de) {
    char full[4096 + 4096];
    struct stat buf;
    int exists = 0;
    char * perms;

    d = opendir((char *)node->content);
    if (d == NULL) {
        ft_dprintf(2, "ls: %s: no such file or directory\n", (char *)node->content);
        node = node->next;
        return (-1);
    }

    while ((de = readdir(d)) != NULL) {
        if (de->d_name[0] == '.' &&
            opts->hidden == FALSE)
            continue;
        ft_sprintf(node->path, "%s", (char *)node->content);
        ft_sprintf(node->name, "%s", (char *)de->d_name);
        ft_sprintf(full, "%s/%s", node->path, node->name);
        exists = stat(full, &buf);
        if (exists > 0) {
            if (opts->longout == FALSE) {
                ft_sprintf(node->outbuf, "%s %s", node->outbuf, node->name);
            } else {
                perms = l_get_mode(node, node->file);
                ft_sprintf(node->outbuf, "%s %s %s", node->outbuf, perms, node->name);
            }
        }
        ft_dprintf(1, "readdir %s", full);
    }
    return (0);
}

/*
** linked list elem contains each non-option parameter
** we go through it and use opendir/ readdir to get elements and
** then stat each element to get their mode.
** display differs between different file modes
**
** we fill each node's PATH and NAME while doing though it.
** this allows us to stat elements if we with to, for example, if we have the long output
** parameter set.
*/

int
e_open(t_elem *elem, t_opts *opts) {
    t_elem *node = elem;
    struct dirent *de = NULL;
    struct stat buf;
    int exists;
    DIR *d = NULL;
    t_file * file;

    if ((file = ft_calloc(1, sizeof(t_file))) == NULL)
        return (-1); /* fataL ERROR */
    while (node != NULL) {
        ft_bzero(node->path, sizeof(node->path));
        ft_bzero(node->name, sizeof(node->name));
        exists = stat((char*)node->content, &buf);
        if (exists > 0)
        {
            node->file->buf = buf;
        }
        if (S_ISDIR(buf.st_mode))
        {
            l_handle_dir(node, opts, d, de);
        }/*  else { */
        /*     l_handle_file(); */
        /* } */
        if (opts->rsort) {
            e_sort(node, 1);
        } else {
            e_sort(node, 0);
        }
        if (l_lstsize(elem) > 1) {
            ft_sprintf(node->outbuf, "%s:\n%s\n", (char*)node->content, node->outbuf);
        }
        ft_dprintf(1, "%s\n", node->outbuf);
        closedir(d);
        node = node->next;
    }
    free(file);
    free(opts);
    return (0);
}

/*
** sort nodes. 3 modes :
** 0: default: sort alphabetically
** 1: time: sort by time
** 2: reverse: reverse sort
*/

int
e_sort(t_elem * node, unsigned char mode)
{
    char ** sortme = ft_split(node->outbuf, ' ');
    char tmp[4096];
    int i = 0;

    while (sortme[i])
    {
        /* ft_printf("full : %s\n", sortme[i]); */
        if (mode == 0)
        {
            if (sortme[i + 1])
            {
                if (ft_tolower(sortme[i][0]) > ft_tolower(sortme[i + 1][0]))
                {
                    ft_sprintf(tmp, "%s", sortme[i]);
                    ft_sprintf(sortme[i], "%s", sortme[i + 1]);
                    ft_sprintf(sortme[i + 1], "%s", tmp);
                    i = 0;
                }
            }
        } else if (mode == 1) {
            if (sortme[i + 1])
            {
                if (ft_tolower(sortme[i][0]) < ft_tolower(sortme[i + 1][0]))
                {
                    ft_sprintf(tmp, "%s", sortme[i]);
                    ft_sprintf(sortme[i], "%s", sortme[i + 1]);
                    ft_sprintf(sortme[i + 1], "%s", tmp);
                    i = 0;
                }
            }
        }
        i++;
    }
    i = 0;
    ft_sprintf(node->outbuf, "%s", sortme[i]);
    while (sortme[++i])
    {
        free(sortme[i - 1]);
        ft_sprintf(node->outbuf, "%s %s", node->outbuf, sortme[i]);
    }
    free(sortme[i]);
    free(sortme);
    return (0);
}
