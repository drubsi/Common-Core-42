/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvon-hee <cvon-hee@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:12:18 by cvon-hee          #+#    #+#             */
/*   Updated: 2026/04/14 20:18:26 by cvon-hee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_window(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window (game->mlx);
	free_game (game);
	exit (0);
}
