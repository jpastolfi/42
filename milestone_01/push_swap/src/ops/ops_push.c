/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/12 16:24:58 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	op_push(t_array *src, t_array *dest);

int	pa(t_array *data_b, t_array *data, t_ops *count_op)
{
	if (data_b->size == 0 || data->size == data->capacity)
		return (0);
	op_push(data_b, data);
	ft_printf("pa\n");
	count_op->pa++;
	return (1);
}

int	pb(t_array *data, t_array *data_b, t_ops *count_op)
{
	if (data->size == 0 || data_b->size == data_b->capacity)
		return (0);
	op_push(data, data_b);
	ft_printf("pb\n");
	count_op->pb++;
	return (1);
}

static void	op_push(t_array *src, t_array *dest)
{
	dest->size++;
	dest->head = (dest->head - 1 + dest->capacity) % dest->capacity;
	dest->values[dest->head] = src->values[src->head];
	src->size--;
	src->head = (src->head + 1) % src->capacity;
}
// 38. To open a new first position in dest by moving dest->head backwards
// 41. And remove the pushed value from src by moving src->head forwards
/*
void print_stack(char *name, t_array *s)
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
    t_array data_b;

    data.capacity = 5;
    data.values = malloc(sizeof(int) * data.capacity);
    data.values[0] = 1; data.values[1] = 2;
	data.values[2] = 3; data.values[3] = 4;
    data.head = 0;
    data.size = 4;

    data_b.capacity = 5;
    data_b.values = malloc(sizeof(int) * data_b.capacity);
    data_b.values[0] = 5; data_b.values[1] = 6;
	data_b.values[2] = 7; data_b.values[3] = 8;
    data_b.head = 0;
    data_b.size = 4;

    printf("--- ANTES ---\n");
    print_stack("STACK A", &data);
    print_stack("STACK B", &data_b);

    printf("--- APLICANDO pa ---\n");

    pa(&data_b, &data);
    print_stack("\nSTACK A", &data);
    print_stack("STACK B", &data_b);

	pb(&data, &data_b);
	print_stack("\nSTACK A", &data);
    print_stack("STACK B", &data_b);

    free(data.values);
    free(data_b.values);
    return (0);
} */
