/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:35:04 by anthrodr          #+#    #+#             */
/*   Updated: 2023/04/21 13:35:47 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
int		ft_printf(const char *format, ...);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_printstr(char *format);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int num);
int		ft_print_unsigned(unsigned int n);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hex(unsigned int num, const char format);
int		test(int argc, char **argv);
long long str_to_ll(const char *str);
bool has_duplicates(int argc, char **argv);
bool is_integer(const char *str);
#endif
