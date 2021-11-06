/*****************************************************************************/
/*                      FT_LS by fmoenne. file: l_main.c                     */
/*****************************************************************************/

#include "l_main.h"

int main(int ac, char *av[]) {
    t_opts opts;

    if (c_get_opts(&opts, ac, av) == FALSE) {
        return (EXIT_SUCCESS);
    }
    return 0;
}
