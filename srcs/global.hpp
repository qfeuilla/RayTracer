/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: QFM <quentin.feuillade33@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:35:02 by QFM               #+#    #+#             */
/*   Updated: 2019/12/11 13:49:21 by QFM              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <iostream>
#include <list>
#include <map>
#include "Vector/Vector.hpp"
#include "Material/Material.hpp"
#include <fstream>
#include <string.h>

#define IMAGE_W 500
#define IMAGE_H 500

extern std::map<int, Vector>				g_normal;				// must start at index 1 !!
extern std::map<int, Vector>				g_uvs;					// must start at index 1 !!
extern std::map<int, Vector>				g_vertex;				// must start at index 1 !!
extern std::map<std::string, Material> 	materials;					// list of all material
int			material_parser(std::string	mtl_name);

#endif