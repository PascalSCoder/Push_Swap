/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 15:57:09 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/17 13:09:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"

# define STATE_OFFSET 10
# define MIN_DIVIDABLESIZE 6

typedef enum e_stackid
{
	stack_ab = -1,
	stack_a,
	stack_b
}	t_stackid;

typedef struct s_state
{
	int	base;
	int	substate;
}	t_state;

typedef struct s_num
{
	int		value;
	int		mask;
	int		state;
}	t_num;

typedef struct s_node
{
	t_num			num;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_stack	*stack;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bot;
	t_stackid	id;
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	int		divisions;
	int		num_c;
	int		fail_c;
	int		push_c;
	int		swap_c;
	int		rotup_c;
	int		rotdown_c;
	int		d_swap_c;
	int		d_rotup_c;
	int		d_rotdown_c;
}	t_data;


typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_instrkey
{
	push,
	swap,
	rotate,
	rev_rotate
}	t_instrkey;

typedef struct s_dict
{
	char	*key;
	void	(*func);
}	t_dict;

void	parse_stack(int argc, char **args, t_data *data);
char	ft_atoi_strict(char *str, int *out_num);
t_node	*ints_to_nodes(int *ints, int count);

//	Version 2 helper functions

void	print_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);
void	print_counters(t_data *data);

t_stack	*get_stack(t_data *data, t_stackid id);

void	stack_swap(t_data *data, t_stackid id);
void	stack_push(t_data *data, t_stackid id_from);
void	stack_rotate_down(t_data *data, t_stackid id);
void	stack_rotate_up(t_data *data, t_stackid id);

void	node_push_bot(t_stack *stack, t_node *node);
void	node_push_top(t_stack *stack, t_node *node);
t_node	*node_pop_top(t_stack *stack);
t_node	*node_pop_bot(t_stack *stack);

void	exit_error(void);
void	exit_error_debug(char *msg); // REMOVE BEFORE PUBLISH

void	instruct(t_instrkey key, t_stackid id, t_data *data);
void	write_instr(t_instrkey key, t_stackid id);

t_node	*node_highest(t_stack *stack);
t_node	*node_lowest(t_stack *stack);
t_node	*node_highest_state(t_stack *stack, int state);
t_node	*node_lowest_state(t_stack *stack, int state);
int		node_count(t_stack *stack);
int		node_count_state(t_stack *stack, int state);
t_bool	contains_state(t_stack *stack, int state);
t_stack	*get_stack_with_state(t_data *data, int state);

void	sort_back(t_data *data, t_stack *st);

t_bool	num_state_isequal(t_num *num1, t_num *num2);
t_bool	num_ishigher(t_num *num1, t_num *num2);

#endif
