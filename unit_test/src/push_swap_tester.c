/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   push_swap_tester.c                              |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/09 20:05:09 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/05/12 22:03:30 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "unit_push_swap.h"
#include "libft.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <string.h>

/* ************************************************************************** */
TestSuite(check_argc, .init=redirect_stdout_to_stderr);
/* ************************************************************************** */
Test(check_argc, one_arg)
{
	cr_assert(count_check(1) == false);
	cr_assert_stderr_eq_str("");
}

Test(check_argc, two_arg)
{
	cr_assert(count_check(2) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argc, more_than_two_arg)
{
	cr_assert(count_check(3) == true);
	cr_assert_stderr_eq_str("");
}

/* ************************************************************************** */
TestSuite(check_argv, .init=redirect_stdout_to_stderr);
/* ************************************************************************** */

Test(check_argv, NULL_pointer)
{
	cr_assert(var_check(0, NULL) == false);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, one_number)
{
	char *string[] = {"1", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, one_char)
{
	char *string[] = {"a", NULL};
	cr_assert(var_check(1, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, two_numbers_sorted)
{
	char *string[] = {"1", "2", NULL};
	cr_assert(var_check(2, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, two_numbers_unsorted)
{
	char *string[] = {"2", "1", NULL};
	cr_assert(var_check(2, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, invalid_char)
{
	char *string[] = {"a", "1", NULL};
	cr_assert(var_check(2, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, invalid_char_second_arg)
{
	char *string[] = {"1", "a", NULL};
	cr_assert(var_check(2, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, invalid_char_second_position)
{
	char *string[] = {"1a", "1", NULL};
	cr_assert(var_check(2, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}
Test(check_argv, invalid_char_random_position)
{
	char *string[] = {"a1", "1234a", NULL};
	cr_assert(var_check(2, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, invalid_char_nl)
{
	char *string[] = {"\n", "2", NULL};
	cr_assert(var_check(2, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, invalid_char_specialchar)
{
	char *string[] = {"1", "-", NULL};
	cr_assert(var_check(2, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, invalid_char_tab)
{
	char *string[] = {"1", "\t", NULL};
	cr_assert(var_check(2, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, invalid_nullterminator)
{
	char *string[] = {"4", "\0", "3", NULL};
	cr_assert(var_check(3, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, invalid_nullterminator_check)
{
	char *string[] = {"4", "0", "3", NULL};
	cr_assert(var_check(3, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, invalid_3x_nullterminator)
{
	char *string[] = {"\\0", "2", "\0", NULL};
	cr_assert(var_check(3, string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(check_argv, invalid_nullterminator_afternum)
{
	char *string[] = {"4", "1\0", "0", NULL};
	cr_assert(var_check(3, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v1)
{
	char *string[] = {"004", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v2)
{
	char *string[] = {"+4", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v3)
{
	char *string[] = {"-4", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v4)
{
	char *string[] = {"-4", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v5)
{
	char *string[] = {"4-", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v6)
{
	char *string[] = {"4+", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

Test(check_argv, atoi_v7)
{
	char *string[] = {"000-4+", NULL};
	cr_assert(var_check(1, string) == true);
	cr_assert_stderr_eq_str("");
}

/* ************************************************************************** */
TestSuite(argvtoarray, .init=redirect_stdout_to_stderr);
/* ************************************************************************** */

bool	setup_argvtoarray(char **argv)
{
	int	len;
	int i;
	int	*integer = NULL;
	long	*expected = NULL;

	len = 0;
	i = 0;
	if (argv)
		while (argv[len])
			len++;
	expected = calloc(len + 1, sizeof(long));
	integer = argvtoarray(len, argv);
	if((!integer || !expected) && argv)
	{
		free(expected);
		free(integer);
		return (false);
	}
	if(integer && !argv)
	{
		free(expected);
		free(integer);
		/*cr_log_warn("Integer should be freed\n");*/
		return (false);
	}
	while (i < len)
	{

		expected[i] = atol(argv[i]);
		if (expected[i] != integer[i])
			return (false);
		i++;
	}
	free(expected);
	free(integer);
	return (true);
}

Test(argvtoarray, NULL_value)
{

	cr_assert(setup_argvtoarray(NULL) == true);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, zero_v1)
{
	char	*string[] = {"0", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, zero_v2)
{
	char	*string[] = {"-00000", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, zero_v3)
{
	char	*string[] = {"+00000", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, zero_v4)
{
	char	*string[] = {"+000010", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, extra_padding_only_one)
{
	char	*string[] = {"0001", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, extra_padding_only_one_min)
{
	char	*string[] = {"0001", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, MAX)
{
	char	*string[] = {"2147483647", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, MAX_plusone)
{
	char	*string[] = {"2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MAX_plusone_pluspad)
{
	char	*string[] = {"+2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}
Test(argvtoarray, MIN)
{
	char	*string[] = {"-2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, MIN_minpluspadding_v1)
{
	char	*string[] = {"-+-2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MIN_minpluspadding_v2)
{
	char	*string[] = {"-+2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MIN_minpluspadding_v3)
{
	char	*string[] = {"+-2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MIN_minpluspadding_v4)
{
	char	*string[] = {"--2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MIN_minpluspadding_v5)
{
	char	*string[] = {"++2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MIN_minpluspadding_v6)
{
	char	*string[] = {"0+2147483648", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, MIN_minone)
{
	char	*string[] = {"-2147483649", NULL};

	cr_assert(setup_argvtoarray(string) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(argvtoarray, extra_padding_MIN)
{
	char	*string[] = {"-002147483648", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, extra_padding_MAX)
{
	char	*string[] = {"002147483647", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, multiple_arguments_v1)
{
	char	*string[] = {"0001", "298347", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, multiple_arguments_v2)
{
	char	*string[] = {"0001", "298347", "-12304987", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}

Test(argvtoarray, multiple_arguments_v3)
{
	char	*string[] = {"0001", "298347", "-12304987", "0", NULL};

	cr_assert(setup_argvtoarray(string) == true);
	cr_assert_stderr_eq_str("");
}
/*Is the list already sorted and does it contain double numbers*/
/* ************************************************************************** */
TestSuite(array_check, .init=redirect_stdout_to_stderr);
/* ************************************************************************** */

bool	test_array_check(int *expected)
{
	int len;

	len = 0;
	if (expected)
		while (expected[len])
			len++;
	if (array_check(len, expected) == false)
		return (false);
	return (true);
}

Test(array_check, NULL_values)
{
	cr_assert(test_array_check(NULL) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(array_check, one_nemb_sorted)
{
	int	expected[] = {1, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(array_check, two_nemb_unsorted)
{
	int	expected[] = {2, 1, '\0'};
	cr_assert(test_array_check(expected) == true);
}

Test(array_check, two_nemb_double)
{
	int	expected[] = {2, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(array_check, three_nemb_double_middle)
{
	int	expected[] = {2, 3, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(array_check, three_nemb_double_back)
{
	int	expected[] = {3, 2, 2, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(array_check, three_nemb_double_front)
{
	int	expected[] = {2, 2, 3, '\0'};
	cr_assert(test_array_check(expected) == false);
	cr_assert_stderr_eq_str("Error\n");
}


/* ************************************************************************** */
TestSuite(init_stack, .init=redirect_stdout_to_stderr);
/* ************************************************************************** */
bool	test_init_stack(int *expected)
{
	t_list	*stack_a = NULL;
	int number;
	int len = 0;
	size_t i = 0;

	if (expected)
		while (expected[len])
			len++;
	stack_a = init_stack(len, expected, stack_a);
	if (stack_a == NULL)
	{
		if (expected)
			cr_log_error("Stack_init_setup failed\n");
		return (false);
	}
	while(i < (size_t)len)
	{
		number = *(int *)stack_a->content;
		if(number != expected[i])
			return (false);
		stack_a = stack_a->next;
		i++;
	}
	ft_lstclear(&stack_a, NULL);
	return (true);
}

Test(init_stack, null_pointer)
{
	int *expected = NULL;
	
	cr_assert(test_init_stack(expected) == false);
	cr_assert_stderr_eq_str("Error\n");
}

Test(init_stack, one_valid_int)
{
	int	expected[] = {1, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, MAX_int)
{
	int	expected[] = {2147483647, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, double_MAXMAX_int)
{
	int	expected[] = {2147483647, -2147483648, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, double_MAX_int)
{
	int	expected[] = {2147483647, 2147483647, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, MIN_int)
{
	int	expected[] = {-2147483648, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, two_valid_int)
{
	int	expected[] = {1, 2, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, three_valid_int)
{
	int	expected[] = {1, 2, 3, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, three_valid_negint)
{
	int	expected[] = {-1, -2, -3, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, rev_three_valid_negint)
{
	int	expected[] = {-3, -2, -1, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}

Test(init_stack, 0_three_valid_negint)
{
	int	expected[] = {-3, 0, -1, '\0'};
	cr_assert(test_init_stack(expected) == true);
	cr_assert_stderr_eq_str("");
}
/* ************************************************************************** */
TestSuite(sa, .init=redirect_stdout_to_stderr);
/* ************************************************************************** */

t_list*	setup_stack_a(const int* initial, size_t initial_len)
{
	t_list *stack_a = NULL;
	cr_assert(initial != NULL);
	stack_a = init_stack(initial_len, initial, stack_a);
	cr_assert(stack_a != NULL);
	return stack_a;
}

void	destroy_stack_a(t_list* stack_a)
{
	ft_lstclear(&stack_a, NULL);
}

bool	compare_stack_against_array(t_list* stack_a, const int *expected, size_t expected_len)
{
	size_t i = 0;
	int number;
	while(i < expected_len)
	{
		number = *(int *)stack_a->content;
		if(number != expected[i])
			return false;
		stack_a = stack_a->next;
		i++;
	}
	return true;
}

Test(sa, basic_input)
{
	const int initial[] = {1, 2};
	const int	expected[] = {2, 1};

	const size_t initial_len = sizeof(initial) / sizeof(*initial);
	const size_t expected_len = sizeof(expected) / sizeof(*expected);

	t_list* stack_a = setup_stack_a(initial, initial_len);
	sa(stack_a);

	bool result = compare_stack_against_array(stack_a, expected, expected_len);
	destroy_stack_a(stack_a);

	cr_expect(result == true);
	cr_expect_stdout_eq_str("sa\n");
}
