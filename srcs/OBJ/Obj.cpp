/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obj.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: QFM <quentin.feuillade33@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:21:38 by QFM               #+#    #+#             */
/*   Updated: 2019/12/10 15:40:16 by QFM              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obj.hpp"
#include <string.h>

Obj::Obj(std::string fname)
{
	char		tm[20];
	char		mat_name[2000];

	int			norm;
	int			vert;
	int			uv;

	int			norm_c = 1;
	int			vert_c = 1;
	int			uv_c = 1;

	float		x;
	float		y;
	float		z;	

	bool		s = false;

	char					su[100];
	name = fname.substr(0, fname.find("."));
	FILE					*file = fopen(fname.c_str(), "r");
	Obj_group				tmp;
	std::list<Vector>		poly;
	
	while (std::fscanf(file, "%s", tm) > 0)
	{
		if (strcmp(tm, "f") == 0)
		{
			poly.clear();
			while(std::fscanf(file, "%d/%d/%d", &vert, &uv, &norm) > 0)
			{
				// std::cout << "Normal : " << norm << std::endl;
				// std::cout << "Vertex : " << vert << std::endl;
				// std::cout << "Uvs : " << uv << std::endl << std::endl;
				poly.push_back(Vector(vert, uv, norm));
			}
			tmp.push_back(Polygon(s, poly));
		}
		else if (strcmp(tm, "v") == 0)
		{
			fscanf(file, "%f %f %f", &x, &y, &z);
			g_vertex[vert_c++] = Vector(x, y, z);
		}
		else if (strcmp(tm, "vt") == 0)
		{
			fscanf(file, "%f %f", &x, &y);
			g_uvs[uv_c++] = Vector(x, y, 0);
		}
		else if (strcmp(tm, "vn") == 0)
		{
			fscanf(file, "%f %f %f", &x, &y, &z);
			g_normal[norm_c++] = Vector(x, y, z);
		}
		else if (strcmp(tm, "s") == 0)
		{
			fscanf(file, "%s", su);
			if (strcmp(su, "off") == 0)
				s = false;
			else
				s = true;
		}
		else if (strcmp(tm, "usemtl") == 0)
		{
			if (tmp.get_polys().size() > 0)
			{
				// std::cout << "ok" << std::endl;
				// std::cout << tmp;
				// std::cout << s << std::endl;
				groups.push_back(tmp.copy());
			}
			// else
				// std::cout << "Nope" << std::endl;	
			fscanf(file, "%s", mat_name);
			tmp = Obj_group(materials[mat_name], mat_name);
			// std::cout << "\033[1;31m" << mat_name << "\033[0m" << std::endl;
		}
		// std::cout << tm << std::endl;
	}
	std::cout << name << std::endl;
}

Obj::Obj() {}

Obj::~Obj() {}

Obj::Obj(Obj const & obj)
{
	name = obj.name;
	groups = obj.groups;
}

Obj 		&Obj::operator=(Obj const & obj)
{
	name = obj.name;
	groups = obj.groups;
	return (*this);
}

std::ostream			&operator<<(std::ostream &o, const Obj &b)
{
	std::list<Obj_group> group = b.get_groups();
	std::list<Obj_group>::iterator	it = group.begin();

	for (int i = 0; i < group.size(); i++)
	{
		o << *it;
		std::advance(it, 1);
	}
	return (o);
}

std::list<Obj_group>	Obj::get_groups() const
{
	return (groups);
}
