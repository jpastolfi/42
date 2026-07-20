/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/13 16:59:22 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_array	*data;
	t_ops	*count_op;
	int		start;
	float	disorder;

	is_valid_argc(argc);
	count_op = malloc(sizeof(t_ops));
	if (!count_op)
		end(ERR_MALLOC);
	count_op_to_zero(count_op);
	start = parse_all_flags(argc, argv, &flags, count_op);
	data = validate_number(argc, argv, start, count_op);
	has_duplicates(data, count_op);
	disorder = compute_disorder(data);
	if (disorder == 0)
	{
		if (count_op->bench)
			display_bench(flags, count_op, disorder);
		return (free(count_op), free(data->values), free(data), 0);
	}
	count_op->total_count = dispatcher(flags, data, count_op);
	if (count_op->bench)
		display_bench(flags, count_op, disorder);
	return (free(count_op), free(data->values), free(data), 0);
}
// 00. Validar se há argumentos suficientes
// 00. Testar o parser de flags e capturar o índice do primeiro número
// 00. Imprimir os resultados para verificação no terminal

int	dispatcher(t_flags flags, t_array *data, t_ops *count_op)
{
	t_array		*data_b;
	int			*number_b;
	int			result;
	t_sort_fn	fns[4];

	data_b = malloc(sizeof(t_array));
	if (!data_b)
		return (free(count_op), free(data->values),
			free(data), end(ERR_MALLOC), -1);
	number_b = malloc(sizeof(int) * data->capacity);
	if (!number_b)
		return (free(data_b), free(count_op), free(data->values),
			free(data), end(ERR_MALLOC), -1);
	data_b->values = number_b;
	data_b->size = 0;
	data_b->capacity = data->capacity;
	data_b->head = 0;
	fns[0] = strategy_simple;
	fns[1] = strategy_medium;
	fns[2] = strategy_complex;
	fns[3] = strategy_adaptive;
	result = fns[flags.strategy](data, data_b, count_op);
	free(data_b->values);
	free(data_b);
	return (result);
}

void	display_bench(t_flags flags, t_ops *count, float dis)
{
	char	*flags_titles[4];

	flags_titles[0] = "Simple";
	flags_titles[1] = "Medium";
	flags_titles[2] = "Complex";
	flags_titles[3] = "Adaptive";
	ft_printf_fd("[bench] dis: %f%%\n", 2, (dis * 100));
	ft_printf_fd("[bench] strategy: %s", 2, flags_titles[flags.strategy]);
	if (dis < 0.2 && flags.strategy == 3)
		ft_printf_fd(" / O(n\xc2\xb2)", 2);
	else if (dis >= 0.2 && dis < 0.5 && flags.strategy == 3)
		ft_printf_fd(" / O(n\xe2\x88\x9an)", 2);
	else if (dis >= 0.5 && flags.strategy == 3)
		ft_printf_fd(" / O(n log n)", 2);
	ft_printf_fd("\n[bench] total_ops: %d\n", 2, count->total_count);
	ft_printf_fd("[bench]	sa: %d	sb: %d", 2, count->sa, count->sb);
	ft_printf_fd("	ss: %d	pa: %d", 2, count->ss, count->pa);
	ft_printf_fd("	pb: %d\n", 2, count->pb);
	ft_printf_fd("[bench]	ra: %d	rb: %d", 2, count->ra, count->rb);
	ft_printf_fd("	rr: %d	rra: %d", 2, count->rr, count->rra);
	ft_printf_fd("	rrb: %d	rrr: %d\n", 2, count->rrb, count->rrr);
}

void	count_op_to_zero(t_ops *count_op)
{
	count_op->sa = 0;
	count_op->sb = 0;
	count_op->ss = 0;
	count_op->pa = 0;
	count_op->pb = 0;
	count_op->ra = 0;
	count_op->rb = 0;
	count_op->rr = 0;
	count_op->rra = 0;
	count_op->rrb = 0;
	count_op->rrr = 0;
	count_op->total_count = 0;
}
/* 
void	print_stack(char *name, t_array *s)
{
	ft_printf("%s: ", name);
	for (int i = 0; i < s->size; i++)
	{
		int idx = (s->head + i) % s->capacity;
		ft_printf("%d ", s->values[idx]);
	}
	ft_printf("\n");
} */
// print_stack("STACK A: ", data); // Insert on main
// ./programa --bench 1 2 3 5 4
