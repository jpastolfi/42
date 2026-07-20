/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:06:43 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/13 17:19:02 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	op_swap(t_array *data);

int	sa(t_array *data, t_ops *count_op)
{
	if (data->size <= 1)
		return (0);
	op_swap(data);
	ft_printf("sa\n");
	count_op->sa++;
	return (1);
}

int	sb(t_array *data_b, t_ops *count_op)
{
	if (data_b->size <= 1)
		return (0);
	op_swap(data_b);
	ft_printf("sb\n");
	count_op->sb++;
	return (1);
}

int	ss(t_array *data, t_array *data_b, t_ops *count_op)
{
	if (data->size <= 1 || data_b->size <= 1)
		return (0);
	if (data->size > 1)
		op_swap(data);
	if (data_b->size > 1)
		op_swap(data_b);
	ft_printf("ss\n");
	count_op->ss++;
	return (1);
}

static void	op_swap(t_array *data)
{
	int	tmp;

	tmp = data->values[data->head];
	data->values[data->head] = data->values[(data->head + 1) % data->capacity];
	data->values[(data->head + 1) % data->capacity] = tmp;
}
// 55. To save the first value before replacing it with the next value
// 57. And move the saved first value into the second stack position
/*
int main(void)
{
	printf("------------- sa --------------\n");
	t_array data;
	data.values = malloc(sizeof(int) * 4);
	data.values[0] = 1;
	data.values[1] = 2;
	data.values[2] = 3;
	data.values[3] = 4;
	data.head = 3;
	data.tail = 3;
	data.size = 4;
	sa(&data);
	for (int i = 0; i < data.size; i++)
	{
		printf("%d\n", data.values[i]);
	}
	printf("--------------------------------\n");

	printf("------------- sb --------------\n");
	t_array data_b;
	data_b.values = malloc(sizeof(int) * 4);
	data_b.values[0] = 5;
	data_b.values[1] = 6;
	data_b.values[2] = 7;
	data_b.values[3] = 8;
	data_b.head = 3;
	data_b.tail = 3;
	data_b.size = 4;
	sb(&data_b);
	for (int i = 0; i < data_b.size; i++)
	{
		printf("%d\n", data_b.values[i]);
	}
	printf("--------------------------------\n");
	printf("------------- ss --------------\n");
	ss(&data, &data_b);
	for (int i = 0; i < data.size; i++)
	{
		printf("%d\n", data.values[i]);
	}
	for (int i = 0; i < data.size; i++)
	{
		printf("%d\n", data_b.values[i]);
	}
	printf("--------------------------------\n");
	return (0);
} */
