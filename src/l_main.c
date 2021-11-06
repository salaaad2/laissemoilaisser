/*****************************************************************************/
/*                      FT_LS by fmoenne. file: l_main.c                     */
/*****************************************************************************/

#include "l_main.h"
#include "../libft/include/libft.h"

/*
** check for flags fill arguments
*/

int main(int ac, char *av[]) {
    t_opts opts;
    t_laisse ls;
    int i;
    int j;
    int n;

    i = 1;
    j = -1;
    n = 0;
    opts.noopt = 1;
    ft_strlcpy(ls.path[n], ".", 1);
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
            ft_strlcpy(ls.path[n], av[i], ft_strlen(av[i]));
        }
        i++;
    }
    return (0);
}
