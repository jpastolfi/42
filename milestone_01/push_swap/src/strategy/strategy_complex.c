/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:41:06 by jastolfi          #+#    #+#             */
/*   Updated: 2026/06/13 17:54:33 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	indexation(t_array *src, int *sorted_copy);
static int	get_max_bits(t_array *src);

int	strategy_complex(t_array *data, t_array *data_b, t_ops *count_op)
{
	int	*sorted;
	int	iterations;
	int	counter;
	int	i;
	int	j;

	i = -1;
	counter = 0;
	sorted = sort_copy(copy_values(data->values, data->size), data->size);
	indexation(data, sorted);
	iterations = get_max_bits(data);
	while (iterations > i++)
	{
		j = 0;
		while (j++ < data->capacity)
		{
			if (((data->values[data->head] >> i) & 1) == 0)
				counter += pb(data, data_b, count_op);
			else
				counter += ra(data, count_op);
		}
		while (data_b->size > 0)
			counter += pa(data_b, data, count_op);
	}
	return (free (sorted), counter);
}
// 28. Create a sorted copy to use as reference for index mapping;
// 29. Replace each value in Stack A with its sorted position index;
// 30. Calculate how many bit passes are needed based on the largest index;
// 31. Iterate once per bit, from least significant to most significant;
// 34. Process every element currently in Stack A;
// 36. If the current bit of the top element is 0, push it to Stack B;
// 38. If the current bit is 1, rotate it to the back of Stack A;
// 41. After each bit pass, pull all elements from Stack B back to Stack A;
// 44. Free the sorted copy and return the total move count;

static void	indexation(t_array *src, int *sorted_copy)
{
	int	i;
	int	j;
	int	capacity_idx;

	i = 0;
	while (i < src->size)
	{
		j = 0;
		capacity_idx = (src->head + i) % src->capacity;
		while (j < src->size)
		{
			if (src->values[capacity_idx] == sorted_copy[j])
			{
				src->values[capacity_idx] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
// 63. Iterate over each element in the stack using circular index arithmetic;
// 69. Search for the element's position in the sorted reference array;
// 71. Replace the element's value with its rank index in sorted order;

static int	get_max_bits(t_array *src)
{
	int	greatest_idx;
	int	max_bits;

	max_bits = 0;
	greatest_idx = src->size - 1;
	while (greatest_idx > 0)
	{
		greatest_idx >>= 1;
		max_bits++;
	}
	return (max_bits);
}
// 89. Start from the highest possible index, which is size minus one;
// 92. Shift right until the value reaches zero, counting each shift;
// 95. Return the number of bits needed to represent the largest index;
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
}

int main(void)
{
	// SMALL STACK 2 NUMBERS
	// t_array data;
	// int	number[] = {8, 2};
	// data.values = number;
	// data.size = 2;
	// data.capacity = 2;
	// data.head = 0;

	// SMALL STACK 3 NUMBERS
	// t_array data;
	// int	number[] = {8, 2, 9};
	// data.values = number;
	// data.size = 3;
	// data.capacity = 3;
	// data.head = 0;

	// SMALL STACK 4 NUMBERS
	// t_array data;
	// int	number[] = {2, 4, 6, 1};
	// data.values = number;
	// data.size = 4;
	// data.capacity = 4;
	// data.head = 0;

	// SMALL STACK 5 NUMBERS
	// t_array data;
	// int	number[] = {2, 8, 1, 4, 9};
	// data.values = number;
	// data.size = 5;
	// data.capacity = 6;
	// data.head = 0;

	// REGULAR STACK
	// t_array data;
	// int	number[] = {2, 8, 1, 4, 9, 332,   -2, 0, 58, 22, 32,  +69,  21497};
	// data.values = number;
	// data.size = 13;
	// data.capacity = 13;
	// data.head = 0;

	// PERFORMANCE STACK - 100 NUMBERS
	t_array data;
	int	number[100] = {71, -89, 23, 405, -12, 9, 88, -334, 56, 102,
		-4, 77, 19, -58, 201, -99, 6, 45, -70, 312, 1, -8, 90,
		44, -20, 67, -150, 33, 11, -5, 800, -444, 25, 99, -11,
		4, 60, -75, 108, -3, 2, -10, 85, 50, -60, 15, -90, 300,
		22, -101, 7, -33, 110, 48, -25, 14, -80, 250, 30, -120,
		13, -40, 115, 55, -35, 16, -95, 210, 35, -130, 17, -50,
		125, 65, -45, 18, -105, 220, 38, -140, 21, -65, 135, 75,
		-55, 24, -115, 230, 42, -160, 27, -85, 145, 82, -62, 28,
		-125, 240, 47, -170};
	data.values = number;
	data.size = 100;
	data.capacity = 100;
	data.head = 0;

	// PERFORMANCE STACK - 500 NUMBERS
	// t_array data;
	// int	number[500] = {
	// 	-1, 101, -201, 301, -401, 2, -102, 202, -302, 402,
	// 	-3, 103, -203, 303, -403, 4, -104, 204, -304, 404,
	// 	-5, 105, -205, 305, -405, 6, -106, 206, -306, 406,
	// 	-7, 107, -207, 307, -407, 8, -108, 208, -308, 408,
	// 	-9, 109, -209, 309, -409, 10, -110, 210, -310, 410,
	// 	-11, 111, -211, 311, -411, 12, -112, 212, -312, 412,
	// 	-13, 113, -213, 313, -413, 14, -114, 214, -314, 414,
	// 	-15, 115, -215, 315, -415, 16, -116, 216, -316, 416,
	// 	-17, 117, -217, 317, -417, 18, -118, 218, -318, 418,
	// 	-19, 119, -219, 319, -419, 20, -120, 220, -320, 420,
	// 	-21, 121, -221, 321, -421, 22, -122, 222, -322, 422,
	// 	-23, 123, -223, 323, -423, 24, -124, 224, -324, 424,
	// 	-25, 125, -225, 325, -425, 26, -126, 226, -326, 426,
	// 	-27, 127, -227, 327, -427, 28, -128, 228, -328, 428,
	// 	-29, 129, -229, 329, -429, 30, -130, 230, -330, 430,
	// 	-31, 131, -231, 331, -431, 32, -132, 232, -332, 432,
	// 	-33, 133, -233, 333, -433, 34, -134, 234, -334, 434,
	// 	-35, 135, -235, 335, -435, 36, -136, 236, -336, 436,
	// 	-37, 137, -237, 337, -437, 38, -138, 238, -338, 438,
	// 	-39, 139, -239, 339, -439, 40, -140, 240, -340, 440,
	// 	-41, 141, -241, 341, -441, 42, -142, 242, -342, 442,
	// 	-43, 143, -243, 343, -443, 44, -144, 244, -344, 444,
	// 	-45, 145, -245, 345, -445, 46, -146, 246, -346, 446,
	// 	-47, 147, -247, 347, -447, 48, -148, 248, -348, 448,
	// 	-49, 149, -249, 349, -449, 50, -150, 250, -350, 450,
	// 	-51, 151, -251, 351, -451, 52, -152, 252, -352, 452,
	// 	-53, 153, -253, 353, -453, 54, -154, 254, -354, 454,
	// 	-55, 155, -255, 355, -455, 56, -156, 256, -356, 456,
	// 	-57, 157, -257, 357, -457, 58, -158, 258, -358, 458,
	// 	-59, 159, -259, 359, -459, 60, -160, 260, -360, 460,
	// 	-61, 161, -261, 361, -461, 62, -162, 262, -362, 462,
	// 	-63, 163, -263, 363, -463, 64, -164, 264, -364, 464,
	// 	-65, 165, -265, 365, -465, 66, -166, 266, -366, 466,
	// 	-67, 167, -267, 367, -467, 68, -168, 268, -368, 468,
	// 	-69, 169, -269, 369, -469, 70, -170, 270, -370, 470,
	// 	-71, 171, -271, 371, -471, 72, -172, 272, -372, 472,
	// 	-73, 173, -273, 373, -473, 74, -174, 274, -374, 474,
	// 	-75, 175, -275, 375, -475, 76, -176, 276, -376, 476,
	// 	-77, 177, -277, 377, -477, 78, -178, 278, -378, 478,
	// 	-79, 179, -279, 379, -479, 80, -180, 280, -380, 480,
	// 	-81, 181, -281, 381, -481, 82, -182, 282, -382, 482,
	// 	-83, 183, -283, 383, -483, 84, -184, 284, -384, 484,
	// 	-85, 185, -285, 385, -485, 86, -186, 286, -386, 486,
	// 	-87, 187, -287, 387, -487, 88, -188, 288, -388, 488,
	// 	-89, 189, -289, 389, -489, 90, -190, 290, -390, 490,
	// 	-91, 191, -291, 391, -491, 92, -192, 292, -392, 492,
	// 	-93, 193, -293, 393, -493, 94, -194, 294, -394, 494,
	// 	-95, 195, -295, 395, -495, 96, -196, 296, -396, 496,
	// 	-97, 197, -297, 397, -497, 98, -198, 298, -398, 498,
	// 	-99, 199, -299, 399, -499, 100, -200, 300, -400, 500
	// };
	// data.values = number;
	// data.size = 500;
	// data.capacity = 500;
	// data.head = 0;

	t_array data_b;
	int number_b[500] = {0};
	data_b.values = number_b;
	data_b.size = 0;
	data_b.capacity = 500;
	data_b.head = 0;

	int	counter;

	// Complex Strategy - Radix Binary (LSD) Sorting Adapted
	print_stack("Stack A", &data);
	ft_printf("\n");
	print_stack("Stack B", &data_b);
	counter = strategy_complex(&data, &data_b);
	ft_printf("\n-----------------------------------\n");
	print_stack("Stack A", &data);
	ft_printf("\n");
	print_stack("Stack B", &data_b);
	ft_printf("Total real de movimentos: %d\n", counter);
	return (0);
 }*/
