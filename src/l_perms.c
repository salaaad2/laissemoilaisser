/*****************************************************************************/
/*                         FT_LS permission managment                         */
/*****************************************************************************/

#include "l_perms.h"

/*
** get perms using stat macros
** fill perm array
*/
int
l_get_mode(t_elem * node, t_file * f)
{
    t_file * tmp = node->head;

    (void)tmp;
    if (f == node->head)
    {
        ft_printf("got head\n");
    }

    if (S_ISDIR(f->buf.st_mode))
    {
        ft_sprintf(f->perms, "dir");
    }
    return (0);
}
