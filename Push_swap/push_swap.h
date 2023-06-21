#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include   <unistd.h>
# include   <stdlib.h>
# include   "./libft/libft.h"

void	incoming_arg(t_data *data);
void	index_a(t_data *data);
int		find_min_number(int *arr, size_t size, long start);
int		same_number_cont(t_data *x);
void	ft_swap_a(t_data *data);
void	ft_swap_b(t_data *data);
void	ft_ra(t_data *data);
void	ft_rb(t_data *data);
void	ft_rra(t_data *data);
void	ft_rrb(t_data *data);
void	ft_pb(t_data *data);
void	ft_pa(t_data *data);
void	check_the_first_two(t_data *data);
void	three_arg_operations(t_data *data);
void	five_sorted(t_data *data);
void	radix_sort(t_data *data);
void	ft_free(char **str);
int		ft_error(void);

#endif
