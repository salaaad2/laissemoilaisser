#include <stdlib.h>
#include "u_opts.h"

t_opts *
u_initopts( void ) {
    t_opts * ret = malloc(sizeof(t_opts));
    if (ret != NULL) {
        ret->longout = 0;
        ret->hidden = 0;
        ret->recursive = 0;
        ret->rsort = 0;
        ret->tsort = 0;
        ret->noopt = 1;
    }
    return (ret);
}

int
u_getopts(char *av[], t_opts *opts) {
    int i, j;
    char c;

    i = 1;
    j = -1;
    while (av[i][++j])
    {
        c = av[i][j];
        if (c == 'R' ||
            c == 'l' ||
            c == 'a' ||
            c == 's' ||
            c == 't') {
            opts->noopt = FALSE;
        }
        if (c == 'R')
            opts->recursive = 1;
        else if (c == 'l')
            opts->longout = 1;
        else if (c == 'a')
            opts->hidden = 1;
        else if (c == 's')
            opts->rsort = 1;
        else if (c == 't')
            opts->tsort = 1;
    }
    return (opts->noopt);
}
