/*****************************************************************************/
/*                      FT_LS by fmoenne. file: l_main.c                     */
/*****************************************************************************/

#include <stdlib.h>

#include "../libft/include/libft.h"

#include "l_main.h"
#include "u_lstcont.h"
#include "u_opts.h"
#include "e_open.h"

/*
** check for flags;
** initialize linked list containing t_elem elements with all non option arguments.
**
*/

int main(int ac, char *av[])
{
    t_elem * elem;
    t_elem * new;
    t_opts * opts;
    int i;

    i = 1;
    elem = l_lstnew(".");
    opts = u_initopts();
    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            u_getopts(av, opts);
        }
        else
        {
            new = malloc(sizeof(t_elem));
            new->content = av[i];
            l_lstadd_back(&elem, new);
        }
        i++;
    }
    ft_printf("recurse : %d\n", opts->recursive);
    ft_printf("hidden : %d\n", opts->hidden);
    ft_printf("longout : %d\n", opts->longout);
    ft_printf("rsort : %d\n", opts->rsort);
    ft_printf("tsort : %d\n", opts->tsort);
    e_open(elem, opts);
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
