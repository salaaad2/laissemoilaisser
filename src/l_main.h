#ifndef L_MAIN_H_
#define L_MAIN_H_

#include <sys/param.h>

#include "../libft/include/libft.h"

typedef unsigned char bool_t;

typedef struct s_opts {
    bool_t	longout;
    bool_t	hidden;
    bool_t	recursive;
    bool_t	rsort;
    bool_t	tsort;
    bool_t	noopt;
} t_opts;

typedef struct s_elem {
    void * content;
    struct s_elem * next;
} t_elem;

#endif
