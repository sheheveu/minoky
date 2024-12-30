#pragma once

unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;

namespace Maths
{
	double fabs_r(double num) {
		if (num < 0) {
			return -num;
		}
		return num;
	}
	float roundf_r(float x) {
		if (x >= 0.0) {
			if (x - int(x) >= 0.5)
				return int(x) + 1;
			else
				return int(x);
		}
		else {
			if (fabs_r(x - int(x)) >= 0.5)
				return int(x) - 1;
			else
				return int(x);
		}
	}

	
	
	__forceinline float Dot(const Vec3& Vec1, const Vec3& Vec2) {
		return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
	}


	float NormalizeAngle(float angle) {
		while (angle > 360.0f) {
			angle -= 360.0f;
		}
		while (angle < 0.0f) {
			angle += 360.0f;
		}
		return angle;
	}

	Vec3 NormalizeAngles(Vec3 angles) {
		angles.x = NormalizeAngle(angles.x);
		angles.y = NormalizeAngle(angles.y);
		angles.z = NormalizeAngle(angles.z);
		return angles;
	}

	Vec2 CosTanSinLineH(float flAngle, float range, int x, int y, int LineLength) {
		float mainAngle = flAngle;
		mainAngle += 45.f;

		float flYaw = (mainAngle) * (PI / 180.0);

		float viewcosyawzzzzzzz = dxmm::math::cos(flYaw);
		float viewsinyawzzzzzzz = dxmm::math::sin(flYaw);

		float x2 = range * (-viewcosyawzzzzzzz) + range * viewsinyawzzzzzzz;
		float y2 = range * (-viewcosyawzzzzzzz) - range * viewsinyawzzzzzzz;

		int posonscreenX = x + int(x2 / range * (LineLength));
		int posonscreenY = y + int(y2 / range * (LineLength));

		return Vec2(posonscreenX, posonscreenY);
	}

	Vec3 EulerAngles(Quaternion q1) {
		float num = q1.w * q1.w;
		float num2 = q1.x * q1.x;
		float num3 = q1.y * q1.y;
		float num4 = q1.z * q1.z;
		float num5 = num2 + num3 + num4 + num;
		float num6 = q1.x * q1.w - q1.y * q1.z;
		Vec3 vector;
		if (num6 > 0.4995f * num5) {
			vector.y = 2.0f * dxmm::math::atan2(q1.y, q1.x);
			vector.x = 1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		if (num6 < -0.4995f * num5) {
			vector.y = -2.0f * dxmm::math::atan2(q1.y, q1.x);
			vector.x = -1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		Quaternion quaternion = Quaternion(q1.w, q1.z, q1.x, q1.y);
		vector.y = dxmm::math::atan2(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
		vector.x = std::asin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
		vector.z = dxmm::math::atan2(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
		return NormalizeAngles(vector * 57.2958f);
	}
}

