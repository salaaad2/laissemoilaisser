#ifndef L_MAIN_H_
#define L_MAIN_H_

#include <sys/param.h>

typedef unsigned char bool_t;

typedef struct s_opts {
    bool_t	longout;
    bool_t	hidden;
    bool_t	recursive;
    bool_t	rsort;
    bool_t	tsort;
} t_opts;

#endif // L_MAIN_H_
