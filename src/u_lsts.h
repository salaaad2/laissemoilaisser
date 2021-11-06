#ifndef U_LSTS_H_
#define U_LSTS_H_

#include "l_main.h"

void					ft_lstadd_front(t_elem **alst, t_elem *new);
void					ft_lstadd_back(t_elem **alst, t_elem *new);
void					ft_lstdelone(t_elem *lst, void (*del)(void *));
void					ft_lstclear(t_elem **lst, void (*del)(void *));
void					ft_lstiter(t_elem *lst, void (*f)(void *));

int						ft_lstsize(t_elem *lst);

t_elem					*ft_lstnew(void *content);
t_elem					*ft_lstlast(t_elem *lst);
t_elem					*ft_lstmap(t_elem *lst, void *(*f)(void *),
								void (*del)(void *));

#endif // U_LSTS_H_
