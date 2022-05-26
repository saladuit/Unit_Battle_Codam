/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   redirect_stdout_to_stderr.c                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:46:31 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/05/12 20:38:01 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout_to_stderr(void)
{
        cr_redirect_stderr();
}
