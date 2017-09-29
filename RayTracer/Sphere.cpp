#include "Sphere.h"
#include "ObjectMaker.h"
#include "JsonEigen.h"

#include <cmath>

REGISTER_OBJECT(Sphere);

Sphere::Sphere(const Eigen::Vector3d& point, double radius, const Eigen::Vector3d& colour)
	: m_point(point), m_radius(radius), m_colour(colour)
{
}

Sphere::Sphere(const nlohmann::json& dict)
	: m_point(json_array2eigen(dict["point"])), m_radius(dict["radius"]), m_colour(json_array2eigen(dict["colour"]))
{
}

Sphere::~Sphere()
{
}

double Sphere::distance(const Ray& ray) const
{
	Eigen::Vector3d l = ray.dir();
	Eigen::Vector3d OC = m_point - ray.pos();

	// a*d^2 + b*d + c = 0
	// double a = 1;
	double b = l.dot(OC);
	double c = OC.dot(OC) - m_radius*m_radius;

	if (b > 0.0) // ray pointing towards the sphere
	{
		double det2 = b*b - c; // de
		if (det2 > 0.0)
		{
			double dist = b - sqrt(det2);
			return dist;
		}
	}

	return HUGE_VAL;
}

Eigen::Vector3d Sphere::intersect(const Ray& ray) const
{
	if (distance(ray) > 0.0)
	{
		return m_colour;
	}

	return Eigen::Vector3d::Zero();
}
