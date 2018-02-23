/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:24:18 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/19 09:47:38 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		line_edition(t_line *line_struct, char *buf, int flags)
{
	static t_is_key		array_is_key[] = {is_left_key, is_right_key,
	is_delete_key, is_up_key, is_down_key, is_shift_left, is_shift_right,
	is_shift_down, is_shift_up, is_ctrl_a, is_ctrl_w, is_ctrl_b, is_home,
	is_end, is_tab, is_ctrl_d, is_control_code, is_return_one};
	static t_do_edition	array_do_edition[] = {move_left, move_right,
	ft_delete_character, up_historic, down_historic, move_left_word,
	move_right_word, down_line, up_line, select_mode, copy_selected,
	paste_selected, move_home, move_end, ft_autocomplete,
	ft_delete_current_character, return_one, return_zero};
	int					i;

	i = 0;
	while ((array_is_key[i])(buf) == 0)
		i++;
	return ((array_do_edition[i])(line_struct, flags));
}
