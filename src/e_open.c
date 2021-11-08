/*****************************************************************************/
/*           FT_LS BY salad, execute stuff after parsing arguments           */
/*****************************************************************************/

#include "e_open.h"
#include "u_lstact.h"

#include <errno.h>
#include <string.h>
#include <sys/stat.h>

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

int e_open(t_elem *elem, t_opts *opts) {
  t_elem *node = elem;
  struct dirent *de;
  struct stat buf;
  int exists;
  DIR *d;
  char full[4096 + 4096];

  while (node != NULL) {
    ft_bzero(node->outbuf, sizeof(node->outbuf));
    ft_bzero(node->path, sizeof(node->path));
    ft_bzero(node->name, sizeof(node->name));
    d = opendir((char *)node->content);
    if (d == NULL) {
      ft_dprintf(2, "ls: %s: unable to open%s\n", (char *)node->content,
                 strerror(errno));
      continue;
    }

    while ((de = readdir(d)) != NULL) {
      if (ft_strcmp(node->content, ".") != 0) {
        ft_sprintf(node->path, "%s", (char *)node->content);
        ft_sprintf(node->name, "%s", (char *)de->d_name);
        ft_sprintf(full, "%s/%s", node->path, node->name);
      } else {
        ft_sprintf(node->name, "%s", (char *)de->d_name);
        ft_sprintf(full, "%s", node->name);
      }
      exists = stat(full, &buf);
      if (exists < 0) {
        ft_dprintf(2, "ls: %s: File not found %s\n", full, strerror(errno));
      } else if (node->name[0] == '.' &&
                 opts->hidden == FALSE) { /* skip entry if file is hidden */
        continue;
      } else if (S_ISDIR(buf.st_mode)) {
        if (opts->recursive == FALSE)
          ft_sprintf(node->outbuf, "%s %s", node->outbuf, node->name);
      } else if (S_ISLNK(buf.st_mode)) {
        ft_sprintf(node->outbuf, "%s %s", node->outbuf, node->name);
      } else if (buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
        ft_sprintf(node->outbuf, "%s %s", node->outbuf, node->name);
      } else {
        ft_sprintf(node->outbuf, "%s %s", node->outbuf, node->name);
      }
    }
    if (l_lstsize(elem) > 1) {
        ft_sprintf(node->outbuf, "%s:\n%s\n", (char*)node->content, node->outbuf);
    }
    ft_dprintf(1, "%s\n", node->outbuf);
    closedir(d);
    node = node->next;
  }
  return (0);
}
