#ifndef L_MAIN_H_
#define L_MAIN_H_

#include <sys/param.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char bool_t;

typedef struct s_opts {
    bool_t	longout;
    bool_t	hidden;
    bool_t	recursive;
    bool_t	rsort;
    bool_t	tsort;
    bool_t	noopt;
} t_opts;

typedef struct s_laisse {
    char path[4096][4096];
} t_laisse;

#endif // L_MAIN_H_
