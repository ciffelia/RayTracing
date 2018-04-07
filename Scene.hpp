#pragma once

#include <Siv3D.hpp>

#include "Sphere.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "HitRec.hpp"
#include "ImagePlane.hpp"

struct Scene
{
	// ���̃��X�g
	Array<Sphere> spheres;

	// �J����
	Camera camera;

	// ���e��
	ImagePlane imagePlane;

	Scene(const Camera _camera, const ImagePlane _imagePlane)
		: camera(_camera)
		, imagePlane(_imagePlane)
	{ }

	// �X�N���[����̍��W�Ɍ�����������Ԃ�
	constexpr Ray rayAt(const Vec2 pos) const
	{
		// �X�N���[�����3�������W
		const Vec3 pos3D(
			imagePlane.center.x - imagePlane.size.x / 2 + pos.x,
			-(imagePlane.center.y - imagePlane.size.y / 2 + pos.y),
			imagePlane.center.z
		);

		return Ray(camera.pos, (pos3D - camera.pos).normalized());
	}

	// �����Ƌ��̏Փ˔���
	// �Փ˂���ꍇ�͌����̎n�_����̋������A�Փ˂��Ȃ��ꍇ��none��Ԃ�
	constexpr Optional<double> intersects(const Ray ray, const Sphere sphere) const
	{
		const auto co = ray.origin - sphere.center;

		const double a = ray.direction.dot(ray.direction);
		const double b = 2 * ray.direction.dot(co);
		const double c = co.dot(co) - sphere.r * sphere.r;

		const double d = b * b - 4 * a * c;

		// ���ʎ���0�ȉ��������ꍇ
		// �������̉���0��1�ł��邩��A�����Ƌ��͌�_�������Ȃ�
		if (d <= 0)
			return none;

		// ���������̉������������ꍇ
		// �J��������߂���_���J�����̕\���ɂ���
		if (-b - Math::Sqrt(d) > 0)
			return (-b - Math::Sqrt(d)) / (2 * a);

		// ���������̉������ŁA�傫�����̉������������ꍇ
		// �J��������߂���_�̓J�����̗����ɂ��邪�A
		// �J�������牓����_���J�����̕\���ɂ���
		if (-b + Math::Sqrt(d) > 0)
			return (-b + Math::Sqrt(d)) / (2 * a);
		
		// ����2�Ƃ����������ꍇ
		// 2�̌�_�͂ǂ�����J�����̗����ɂ���
		return none;
	}
	
	// �������΂�
	// ���̂ɏՓ˂����ꍇ�͂��̏����A���Ȃ������ꍇ��none��Ԃ�
	Optional<HitRec> trace(const Ray ray) const
	{
		Optional<HitRec> closestHit;

		for (const auto& sphere : spheres)
		{
			const auto t = intersects(ray, sphere);

			if (!t)
				continue;
			if (closestHit && closestHit.value().t < t)
				continue;

			const auto p = ray.origin + ray.direction * t.value();
			closestHit = HitRec(t.value(), p, (p - sphere.center).normalized());
		}

		return closestHit;
	}
};
