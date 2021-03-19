/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:36:19 by ncolin            #+#    #+#             */
/*   Updated: 2021/03/19 10:41:48 by ncolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "shared.h"

int	find_chunks(t_stack *stack, int chunk_total, int chunk_num, int flag)
{
	int *array;
	int ret;
	size_t i;
	
	i = 0;
	if (!(array = (int*)malloc(sizeof(int)*stack->len)))
		printf("malloc error");
	while (i < stack->len)
	{
		array[i] = stack->numbers[i];
		i++;
	}
	sort_array(array, stack->len);
	ret = array[((stack->len)/chunk_total) * (chunk_num - flag) - 1 ];
	free(array);
	return (ret);
}

void push_quarters(t_stack *a, t_stack *b, int chunk_total, int chunk_num)
{
	size_t count = 0;
	int chunk_upper_limit;
	int chunk_lower_limit; 
	
	chunk_lower_limit = find_chunks(a, chunk_total, chunk_num, 1);
	chunk_upper_limit = find_chunks(a, chunk_total, chunk_num, 0);
	printf("----------------------------------------------------\n");
	printf("lower : %d\n", chunk_lower_limit);
	printf("upper : %d\n", chunk_upper_limit);
	printf("----------------------------------------------------\n");
	print_stacks(a,b);
	while (count <= a->size - 1)
	{
		if (a->numbers[a->len - 1] < chunk_upper_limit && a->numbers[a->len - 1] >= chunk_lower_limit) 
			inst_exec("pb", a, b);
		else
			inst_exec("ra", a, b);
		count ++;
	}
	printf("pushing to b \n");
	print_stacks(a,b);
}

void solve_500(t_stack *a, t_stack *b)
{
	int chunk_num;
	int chunk_total;

	chunk_total =  a->size / 75 + 1;
	chunk_num = 1;
	while(a->len)
	{
		push_quarters(a,b, chunk_total, chunk_num);
		while (b->len)
		{
			find_big_small(b);
			find_move();
			push_back(a, b);
			reset_data();
			sleep(1);
		}
		while (get_data()->rotate_left != 0)
		{
			inst_exec("ra", a, b);
			get_data()->rotate_left--;
		}
		if(chunk_num == chunk_total)
		{
			printf("lol\n");
			while (!is_sorted(a))
				inst_exec("ra", a, b);
			break ;
		}
		chunk_num++;
		
	}
	printf("%d\n", chunk_total);
}