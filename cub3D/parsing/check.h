/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylazrek <ylazrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:11:37 by ylazrek           #+#    #+#             */
/*   Updated: 2020/11/15 16:32:04 by ylazrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "parse.h"

int		count_table(char **tab);
void	free_table(char **tab);
char	**new_table(void);
char	**ft_join_table(char **tab, char *str);
void	check_firsterror(char **t);
void	check_2error(t_para *f, char **tab);
int		ft_isin(char c, char *s);
void	parse_resolution(char *s, t_para *f);
void	init_para(t_para *f);
void	init_map(void);
void	parse_resolution(char *s, t_para *f);
void	parse_nord(char *s, t_para *f);
void	parse_south(char *s, t_para *f);
void	parse_west(char *s, t_para *f);
void	parse_east(char *s, t_para *f);
void	parse_spirite(char *s, t_para *f);
void	parse_sol(char *s, t_para *f);
void	parse_sol1(int len1, t_para *f, char **tab, char **str);
void	parse_plafont(char *s, t_para *f);
void	parse_plafont1(int len1, t_para *f, char **tab, char **str);
char	*parse_map(char *s, int *inc);
void	error_msg(char **s);
char	*sup_espace(char *s);
void	last_check(char **tab);
void	check_top(char **t);
void	check_bottom(char **t);
void	check_corps(char **t);
void	check_edge(size_t i, size_t j, char **t);
char	**parse_f(char *p, t_para *f);
void	alloc_tab(void);
void	get_map(char **tab, int *i, int *inc);
void	get_info(char **tab, t_para *f, int *i);
char	**get_f(char *p);
void	free_grid(void);
int		is_num(char *s);
void	check_up(size_t i, size_t j, char **t);
void	check_down(size_t i, size_t j, char **t);

#endif
