/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/13 18:12:00 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	send_to_bucket(t_array *data, t_array *data_b, int *bkt, t_ops *c);
static int	sort_and_push_reverse(t_array *src, t_array *dest, t_ops *c);

int	strategy_medium(t_array *data, t_array *data_b, t_ops *c)
{
	int	*sorted;
	int	bucket_start;
	int	bucket_end;
	int	counter;
	int	bkt[2];

	counter = 0;
	bucket_start = 0;
	bucket_end = ft_sqrt(data->capacity) - 1;
	sorted = sort_copy(copy_values(data->values, data->size), data->size);
	while (bucket_start < data->capacity)
	{
		bkt[0] = sorted[bucket_start];
		bkt[1] = sorted[bucket_end];
		counter += send_to_bucket(data, data_b, bkt, c);
		bucket_start = bucket_end + 1;
		bucket_end = bucket_start + ft_sqrt(data->capacity) - 1;
		if (bucket_end > data->capacity - 1)
			bucket_end = data->capacity - 1;
	}
	counter += sort_and_push_reverse(data_b, data, c);
	return (free(sorted), counter);
}
// 29. Calculate initial bucket size using the square root of the total size;
// 30. Create a sorted copy of the stack to establish our value thresholds;
// 32. Loop until all logical buckets have been processed;
// 33. Push all elements within current bucket range [min, max] to Stack B;
// 35. Shift the bucket start index forward for the next iteration;
// 36. Shift the bucket end index forward by the chunk size amount;
// 37. Prevent the bucket end index from exceeding the actual array limits;
// 40. Sort the semi-organized Stack B and push highest values back to Stack A;
// 43. Free the allocated sorted array to prevent leaks and return total moves;

int	is_in_bucket(int value, int min, int max)
{
	return (value >= min && value <= max);
}
// 55. Function to check if a value falls within the target bucket range;

static int	send_to_bucket(t_array *data, t_array *data_b, int *bkt, t_ops *c)
{
	int	i;
	int	j;
	int	counter;
	int	moves;

	j = 0;
	counter = 0;
	while (j++ < data->capacity)
	{
		i = 0;
		moves = movements_next_bucket_val(data, bkt[0], bkt[1]);
		if (moves == -1)
			break ;
		if (moves <= data->size / 2)
			while (i++ < moves)
				counter += ra(data, c);
		else
			while (i++ < data->size - moves)
				counter += rra(data, c);
		counter += pb(data, data_b, c);
	}
	return (counter);
}
// 72. Loop a maximum amount of times equal to the current stack size;
// 75. Find the shortest path (amount of moves) to the closest target element;
// 76. If no target elements are left in Stack A, abort the current wave;
// 78. If target is in the first half, rotate forward;
// 81. If target is in the second half, rotate backward for efficiency;
// 84. Push the found target element to Stack B;

static int	sort_and_push_reverse(t_array *src, t_array *dest, t_ops *c)
{
	int	moves;
	int	i;
	int	counter;

	counter = 0;
	while (src->size > 0)
	{
		moves = movements_to_greatest(src);
		i = 0;
		if (moves <= src->size / 2)
			while (i++ < moves)
				counter += rb(src, c);
		else
			while (i++ < src->size - moves)
				counter += rrb(src, c);
		counter += pa(src, dest, c);
	}
	return (counter);
}
// 102. Loop until Stack B is completely empty;
// 104. Find the exact position of the absolute highest value in Stack B;
// 106. If the highest value is in the first half, rotate forward;
// 109. If the highest value is in the second half, rotate backward;
// 112. Push the highest value back to Stack A, guaranteeing descending order;
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
	// t_array data;
	// int	number[100] = {71, -89, 23, 405, -12, 9, 88, -334, 56, 102,
	// 	-4, 77, 19, -58, 201, -99, 6, 45, -70, 312, 1, -8, 90,
	// 	44, -20, 67, -150, 33, 11, -5, 800, -444, 25, 99, -11,
	// 	4, 60, -75, 108, -3, 2, -10, 85, 50, -60, 15, -90, 300,
	// 	22, -101, 7, -33, 110, 48, -25, 14, -80, 250, 30, -120,
	// 	13, -40, 115, 55, -35, 16, -95, 210, 35, -130, 17, -50,
	// 	125, 65, -45, 18, -105, 220, 38, -140, 21, -65, 135, 75,
	// 	-55, 24, -115, 230, 42, -160, 27, -85, 145, 82, -62, 28,
	// 	-125, 240, 47, -170};
	// data.values = number;
	// data.size = 100;
	// data.capacity = 100;
	// data.head = 0;

	// PERFORMANCE STACK - 500 NUMBERS
	t_array data;
	int	number[500] = {
		-1, 101, -201, 301, -401, 2, -102, 202, -302, 402,
		-3, 103, -203, 303, -403, 4, -104, 204, -304, 404,
		-5, 105, -205, 305, -405, 6, -106, 206, -306, 406,
		-7, 107, -207, 307, -407, 8, -108, 208, -308, 408,
		-9, 109, -209, 309, -409, 10, -110, 210, -310, 410,
		-11, 111, -211, 311, -411, 12, -112, 212, -312, 412,
		-13, 113, -213, 313, -413, 14, -114, 214, -314, 414,
		-15, 115, -215, 315, -415, 16, -116, 216, -316, 416,
		-17, 117, -217, 317, -417, 18, -118, 218, -318, 418,
		-19, 119, -219, 319, -419, 20, -120, 220, -320, 420,
		-21, 121, -221, 321, -421, 22, -122, 222, -322, 422,
		-23, 123, -223, 323, -423, 24, -124, 224, -324, 424,
		-25, 125, -225, 325, -425, 26, -126, 226, -326, 426,
		-27, 127, -227, 327, -427, 28, -128, 228, -328, 428,
		-29, 129, -229, 329, -429, 30, -130, 230, -330, 430,
		-31, 131, -231, 331, -431, 32, -132, 232, -332, 432,
		-33, 133, -233, 333, -433, 34, -134, 234, -334, 434,
		-35, 135, -235, 335, -435, 36, -136, 236, -336, 436,
		-37, 137, -237, 337, -437, 38, -138, 238, -338, 438,
		-39, 139, -239, 339, -439, 40, -140, 240, -340, 440,
		-41, 141, -241, 341, -441, 42, -142, 242, -342, 442,
		-43, 143, -243, 343, -443, 44, -144, 244, -344, 444,
		-45, 145, -245, 345, -445, 46, -146, 246, -346, 446,
		-47, 147, -247, 347, -447, 48, -148, 248, -348, 448,
		-49, 149, -249, 349, -449, 50, -150, 250, -350, 450,
		-51, 151, -251, 351, -451, 52, -152, 252, -352, 452,
		-53, 153, -253, 353, -453, 54, -154, 254, -354, 454,
		-55, 155, -255, 355, -455, 56, -156, 256, -356, 456,
		-57, 157, -257, 357, -457, 58, -158, 258, -358, 458,
		-59, 159, -259, 359, -459, 60, -160, 260, -360, 460,
		-61, 161, -261, 361, -461, 62, -162, 262, -362, 462,
		-63, 163, -263, 363, -463, 64, -164, 264, -364, 464,
		-65, 165, -265, 365, -465, 66, -166, 266, -366, 466,
		-67, 167, -267, 367, -467, 68, -168, 268, -368, 468,
		-69, 169, -269, 369, -469, 70, -170, 270, -370, 470,
		-71, 171, -271, 371, -471, 72, -172, 272, -372, 472,
		-73, 173, -273, 373, -473, 74, -174, 274, -374, 474,
		-75, 175, -275, 375, -475, 76, -176, 276, -376, 476,
		-77, 177, -277, 377, -477, 78, -178, 278, -378, 478,
		-79, 179, -279, 379, -479, 80, -180, 280, -380, 480,
		-81, 181, -281, 381, -481, 82, -182, 282, -382, 482,
		-83, 183, -283, 383, -483, 84, -184, 284, -384, 484,
		-85, 185, -285, 385, -485, 86, -186, 286, -386, 486,
		-87, 187, -287, 387, -487, 88, -188, 288, -388, 488,
		-89, 189, -289, 389, -489, 90, -190, 290, -390, 490,
		-91, 191, -291, 391, -491, 92, -192, 292, -392, 492,
		-93, 193, -293, 393, -493, 94, -194, 294, -394, 494,
		-95, 195, -295, 395, -495, 96, -196, 296, -396, 496,
		-97, 197, -297, 397, -497, 98, -198, 298, -398, 498,
		-99, 199, -299, 399, -499, 100, -200, 300, -400, 500
	};
	data.values = number;
	data.size = 500;
	data.capacity = 500;
	data.head = 0;

	t_array data_b;
	int number_b[500] = {0};
	data_b.values = number_b;
	data_b.size = 0;
	data_b.capacity = 500;
	data_b.head = 0;

	int	counter;

	// Medium Strategy - Bucket Sorting Adapted
	print_stack("Stack A", &data);
	ft_printf("\n");
	print_stack("Stack B", &data_b);
	counter = strategy_medium(&data, &data_b);
	ft_printf("\n-----------------------------------\n");
	print_stack("Stack A", &data);
	ft_printf("\n");
	print_stack("Stack B", &data_b);
	ft_printf("Total real de movimentos: %d\n", counter);
	return (0);
 } */
