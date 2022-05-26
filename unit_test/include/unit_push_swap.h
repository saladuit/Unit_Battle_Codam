/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_push_swap.h                                |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:34:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/05/12 20:39:59 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_PUSH_SWAP
# define UNIT_PUSH_SWAP
# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <criterion/logging.h>
# include <criterion/internal/redirect.h>
# include <criterion/internal/test.h>
# include <criterion/new/assert.h>
# include "push_swap.h"
# include "libft.h"

void redirect_stdout_to_stderr(void);
void assert_empty_stdout();
void assert_error_stdout();

#endif
