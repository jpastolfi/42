/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:06:10 by jastolfi          #+#    #+#             */
/*   Updated: 2026/06/13 17:29:51 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	op_rrotate(t_array *data);

int	rra(t_array *data, t_ops *count_op)
{
	if (data->size <= 1)
		return (0);
	op_rrotate(data);
	ft_printf("rra\n");
	count_op->rra++;
	return (1);
}

int	rrb(t_array *data_b, t_ops *count_op)
{
	if (data_b->size <= 1)
		return (0);
	op_rrotate(data_b);
	ft_printf("rrb\n");
	count_op->rrb++;
	return (1);
}

int	rrr(t_array *data, t_array *data_b, t_ops *count_op)
{
	if (data->size <= 1 || data_b->size <= 1)
		return (0);
	op_rrotate(data);
	op_rrotate(data_b);
	ft_printf("rrr\n");
	count_op->rrr++;
	return (1);
}

static void	op_rrotate(t_array *data)
{
	int	tmp;

	if (data->size <= 1)
		return ;
	tmp = data->values[(data->head + data->size - 1) % data->capacity];
	if (data->head == 0)
		data->head = data->capacity - 1;
	else
		data->head--;
	data->values[data->head] = tmp;
}
// 45. To find and save the stack last value before moving the head backwards
// 50. And save that previous last value (tmp) as now the first value
/*
void	print_stack(char *name, t_array *s)
{
    printf("%s: ", name);
    for (int i = 0; i < s->size; i++)
    {
        int idx = (s->head + i) % s->capacity;
        printf("%d ", s->values[idx]);
    }
    printf("\n");
}

int main(void)
{
    t_array data;

    data.capacity = 5;
    data.values = malloc(sizeof(int) * data.capacity);
    data.values[0] = 1; data.values[1] = 2;
	data.values[2] = 3; data.values[3] = 4;
    data.head = 0;
    data.size = 4;

    printf("--- ANTES ---\n");
    print_stack("STACK A", &data);

    printf("--- APLICANDO rra ---\n");

    rra(&data);
    print_stack("\nSTACK A", &data);

    free(data.values);
    return (0);
} */
