/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:59:25 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/13 17:51:56 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	strategy_adaptive(t_array *data, t_array *data_b, t_ops *count_op)
{
	float	disorder;

	if (data->size <= 5)
		return (swap_small_stack(data, data_b, count_op));
	disorder = compute_disorder(data);
	if (disorder < 0.2)
		return (strategy_simple(data, data_b, count_op));
	else if (disorder < 0.5)
		return (strategy_medium(data, data_b, count_op));
	else
		return (strategy_complex(data, data_b, count_op));
	return (0);
}
// 21. For small stacks of 5 or fewer, use a dedicated small-stack handler;
// 23. Measure how disordered the stack currently is;
// 24. Nearly sorted stacks use the simple selection-based strategy;
// 26. Moderately disordered stacks use the medium bucket-based strategy;
// 28. Highly disordered stacks use the complex radix-based strategy;

float	compute_disorder(t_array *data)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	if (data->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			total_pairs++;
			if (data->values[(data->head + i) % data->capacity]
				> data->values[(data->head + j) % data->capacity])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
// 51. Count every pair of elements in the stack as a candidate comparison;
// 52/53. Use circular buffer arithmetic to compare physical memory correctly;
// 54. Increment mistakes if an element is logically greater than a later one;
// 59. Return the ratio of inverted pairs over total pairs as a disorder score;
