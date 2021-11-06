/*****************************************************************************/
/*                      FT_LS by fmoenne. file: l_main.c                     */
/*****************************************************************************/

#include <stdlib.h>

#include "../libft/include/libft.h"

#include "l_main.h"
#include "u_lstcont.h"
#include "e_open.h"

/*
** check for flags;
** initialize linked list containing t_elem elements with all non option arguments.
**
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
    e_open(elem);
    return (0);
}

/*
** ====== INFO ======
** Files prefixes info
** -------------------
** b_  -> builtins related
** d_  -> defines related
** e_  -> exec related
** f_  -> failure related
** m_  -> core minishell related
** p_  -> parse related
** s_  -> structs related
** u_  -> utils related
** v_  -> general purpose variables related
*/
