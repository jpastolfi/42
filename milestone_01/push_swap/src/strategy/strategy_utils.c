/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:52:22 by jastolfi          #+#    #+#             */
/*   Updated: 2026/06/12 12:04:11 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*copy_values(int *numbers, int size)
{
	int	*copied_stack;
	int	i;

	copied_stack = malloc(sizeof(int) * size);
	if (!copied_stack)
		end(ERR_MALLOC);
	i = 0;
	while (i < size)
	{
		copied_stack[i] = numbers[i];
		i++;
	}
	return (copied_stack);
}

int	*sort_copy(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
				ft_swap(&numbers[i], &numbers[j]);
			j++;
		}
		i++;
	}
	return (numbers);
}

int	movements_to_greatest(t_array *data_b)
{
	int	i;
	int	count_moves;
	int	greatest_val;
	int	capacity_idx;

	greatest_val = data_b->values[data_b->head];
	count_moves = 0;
	i = 1;
	while (i < data_b->size)
	{
		capacity_idx = (data_b->head + i) % data_b->capacity;
		if (data_b->values[capacity_idx] > greatest_val)
		{
			greatest_val = data_b->values[capacity_idx];
			count_moves = i;
		}
		i++;
	}
	return (count_moves);
}

int	movements_next_bucket_val(t_array *src, int min, int max)
{
	int	i;
	int	current_val;
	int	capacity_idx;

	current_val = src->values[src->head];
	i = 0;
	if (is_in_bucket(current_val, min, max))
		return (i);
	while (++i < src->size)
	{
		capacity_idx = (src->head + i) % src->capacity;
		current_val = src->values[capacity_idx];
		if (is_in_bucket(current_val, min, max))
			return (i);
	}
	return (-1);
}

/* 
static void print_stack(char *name, t_array *s)
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
	int	number[] = {2, 1, 3};
	data.values = number;
	data.size = 3;
	data.capacity = 3;
	data.head = 0;   

    sort_three(&data);
    print_stack("Stack A: ", &data);
} */
