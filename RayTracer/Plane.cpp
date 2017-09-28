#include "Plane.h"

Plane::Plane(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const Eigen::Vector3d& colour)
	: m_point(point), m_normal(normal.normalized()), m_colour(colour)
{
}

Plane::~Plane()
{
}

double Plane::distance(const Ray& ray) const
{
	double den = m_normal.dot(ray.dir());
	if (fabs(den) > 1e-6)
	{
		double num = m_normal.dot(m_point - ray.pos());
		double dist = num / den;
		if (dist > 0.0)
		{
			return dist;
		}
	}

	return HUGE_VAL;
}

Eigen::Vector3d Plane::intersect(const Ray& ray) const
{
	return m_colour;
}
