/*****************************************************************************/
/*                      FT_LS by fmoenne. file: l_main.c                     */
/*****************************************************************************/

#include <stdlib.h>

#include "l_main.h"
#include "u_lstcont.h"
#include "../libft/include/libft.h"

/*
** check for flags fill arguments
*/

int main(int ac, char *av[])
{
    t_elem * elem;
    t_elem * ptr;
    t_elem * new;
    t_opts opts;
    int i;
    int j;
    int n;

    i = 1;
    j = -1;
    n = 0;
    elem = l_lstnew(".");
    opts.noopt = 1;
    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            while (av[i][++j])
            {
                if (av[i][j] == 'R')
                    opts.recursive = 1;
                else if (av[i][j] == 'l')
                    opts.longout = 1;
                else if (av[i][j] == 'a')
                    opts.hidden = 1;
                else if (av[i][j] == 's')
                    opts.rsort = 1;
                else if (av[i][j] == 't')
                    opts.tsort = 1;
            }
            j = -1;
        }
        else
        {
            n++;
            new = malloc(sizeof(t_elem));
            new->content = av[i];
            l_lstadd_back(&elem, new);
        }
        i++;
    }
    for (ptr = elem; ptr; ptr = ptr->next)
    {
        ft_printf("%s\n", (char*)ptr->content);
    }
    return (0);
}
