/*****************************************************************************/
/*           FT_LS BY salad, execute stuff after parsing arguments           */
/*****************************************************************************/


#include "e_open.h"

#include <sys/stat.h>

int e_open(t_elem * elem)
{
    t_elem * node = elem;
    struct stat buf;
    int exists;

    while (node)
    {
        exists = stat((char*)node->content, &buf);
        if (exists < 0)
        {
            ft_printf("ls: %s: File not found\n", (char*)node->content);
        }
        else
        {
            ft_printf("%10ld, %s\n", buf.st_size, (char*)node->content);
        }
        node = node->next;
    }
    return (0);
}
