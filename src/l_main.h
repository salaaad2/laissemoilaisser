#ifndef L_MAIN_H_
#define L_MAIN_H_

#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include "../libft/include/libft.h"

typedef unsigned char bool_t;

typedef struct s_opts {
    bool_t	longout;
    bool_t	hidden;
    bool_t	recursive;
    bool_t	rsort;
    bool_t	tsort;
    bool_t	noopt;
} t_opts ;

typedef struct s_file {
    char perms[4096];
    char name[4096];
    struct stat buf;
    struct s_file * next;
} t_file ;

typedef struct s_elem {
    void * content;
    bool_t exists;
    bool_t isdir;
    bool_t islink;

    char path[4096];
    char name[4096];
    char outbuf[42 * 4096];

    t_file * file;

    struct s_elem * next;
} t_elem ;

#endif
