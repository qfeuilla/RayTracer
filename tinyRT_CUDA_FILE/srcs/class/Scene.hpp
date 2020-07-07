#ifndef SCENE_HPP
#define SCENE_HPP

#define DEVICE  __host__ __device__

#include "Object.hpp"
#include "BVH_node.hpp"

#define eps 1e-6

class Scene {
	Object** objects;
	int list_size;

public:
	DEVICE Scene() {}

	DEVICE Scene(Object** objs, int size) {
		objects = objs;
		list_size = size;
	}

	DEVICE Intersection intersect(const Ray& ray) const{
		Intersection closestIntersection;
		// intersect all objects, one after the other
		for (int i = 0; i < list_size; i++) {
			Intersection inter = objects[i]->intersect(ray);
			if (inter.t > eps && inter.t < closestIntersection.t) {
				closestIntersection = inter;
			}
		}

		return closestIntersection;
	}
};

#endif