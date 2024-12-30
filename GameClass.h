#pragma once
#include "il2cpp.h"
#include "math.h"
#include "offest.h"

class Vec3
{
public:
	float x, y, z;

	Vec3() {
		x = y = z = 0.0f;
	}

	Vec3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	float operator[](int i) const {
		return ((float*)this)[i];
	}

	Vec3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	Vec3 operator*(float v) const {
		return Vec3(x * v, y * v, z * v);
	}

	Vec3 operator/(float v) const
	{
		return Vec3(x / v, y / v, z / v);
	}

	Vec3& operator+=(const Vec3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	Vec3 operator-(const Vec3& v) const {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}
	bool operator==(const Vec3& b) const {
		return x == b.x && y == b.y && z == b.z;
	}
	Vec3& operator-=(const Vec3& v) {
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	Vec3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}

	Vec3 operator+(const Vec3& v) const {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}
	bool Invalid() const
	{
		return ((x > -1.f && x < 1.f) && (y > -1.f && y < 1.f) &&
			(z > -1.f && z < 1.f)) ||
			(x == 0.f && z == 0.f);
	}
	static inline bool IsNaN(float f)
	{
		return (*(int*)(&f) & 2147483647) > 2139095040;
	}

	static inline bool IsInfinity(float f)
	{
		return (*(int*)(&f) & 2147483647) == 2139095040;
	}

	static inline bool IsNaNOrInfinity(Vec3 v)
	{
		return IsNaN(v.x) || IsNaN(v.y) || IsNaN(v.z) || IsInfinity(v.x) || IsInfinity(v.y) || IsInfinity(v.z);
	}
	bool IsZero() const
	{
		return (x == 0.f &&
			y == 0.f &&
			z == 0.f);
	}
	static Vec3 Zero() {
		return Vec3(0.0f, 0.0f, 0.0f);
	}
	static float my_sqrt(float number) {
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y; // floating point bit level hacking [sic]
		i = 0x5f3759df - (i >> 1); // Newton's approximation
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y)); // 1st iteration
		y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

		return 1 / y;
	}
	float UnityMagnitude()
	{
		return (float)my_sqrt((double)(this->x * this->x + this->y * this->y + this->z * this->z));
	}
	template<typename T>
	T get_remainder(T val, T min, T max)
	{
		while (val > max)
			val -= max * 2;
		while (val < min)
			val += max * 2;
		return val;
	}

	static float Clamp(float value, float min, float max) {
		bool flag = value < min;
		if (flag) {
			value = min;
		}
		else {
			bool flag2 = value > max;
			if (flag2) {
				value = max;
			}
		}
		return value;
	}


	static float Clamp01(float value)
	{
		float result;
		if (value < 0.f)
		{
			result = 0.f;
		}
		else if (value > 1.f)
		{
			result = 1.f;
		}
		else
		{
			result = value;
		}
		return result;
	}
	float lerp()
	{
		return x + (y - x) * Clamp01(z);
	}
	static Vec3 Lerp(Vec3 a, Vec3 b, float t)
	{
		t = Clamp01(t);
		return Vec3(
			a.x + (b.x - a.x) * t,
			a.y + (b.y - a.y) * t,
			a.z + (b.z - a.z) * t
		);
	}
	static float InverseLerp(float a, float b, float value)
	{
		float result;
		if (a != b)
		{
			result = Clamp01((value - a) / (b - a));
		}
		else
		{
			result = 0.f;
		}
		return result;
	}
	float length_sqr() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	float length() const
	{
		float lenSqr = length_sqr();
		if (lenSqr <= 0.f)
			return 0.f;

		return dxmm::math::sqrt(lenSqr);
	}
	float Magnitude()
	{
		return dxmm::math::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	float MagnitudeXZ()
	{
		return dxmm::math::sqrt(this->x * this->x + this->z * this->z);
	}
	inline float Length()
	{
		return my_sqrt((x * x) + (y * y) + (z * z));
	}
	bool Empty() { return x == 0 && y == 0 && z == 0; }
	Vec3 Normalized()
	{
		float num = this->Magnitude();
		if (num > 1.192092896e-07F)
		{
			return { this->x / num, this->y / num, this->z / num };
		}
		return Vec3{};
	}


	float Magnitude2D()
	{
		return my_sqrt(this->x * this->x + this->z * this->z);
	}

	Vec3 Normalize()
	{
		Vec3 out = *this;
		auto l = Length();
		if (l == 0)
			return *this;

		out.x /= l;
		out.y /= l;
		out.z /= l;
		return out;
	}
	Vec3 Cross(Vec3 rhs)
	{
		return Vec3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}


	Vec3 UnityNormalize2()
	{
		Vec3 tis(x, y, z);
		float num = Vec3(x, y, z).Magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vec3(0, 0, 0);
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;

		return { x,y,z };
	}

	void UnityNormalize()
	{
		Vec3 tis(x, y, z);
		float num = Vec3(x, y, z).Magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vec3().Zero();
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;
	}

	Vec3 midPoint(Vec3 v2)
	{
		return Vec3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
	}

	float distance(Vec3 input) const {
		return (*this - input).length();
	}
	inline float Dot(const Vec3& input) {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}

	inline float UnityDot(Vec3 lhs, Vec3 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	float Distance(const Vec3& vector)
	{
		return my_sqrt(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}
	static double my_acos(double x) {
		if (x < -1 || x > 1) {
			return 0;
		}

		if (x == -1) {
			return PI;
		}

		if (x == 1) {
			return 0.0;
		}

		double result = dxmm::math::atan(dxmm::math::sqrt(1 - x * x) / x);
		if (x < 0) {
			result += PI;
		}

		return result;
	}
	static float Angle(Vec3 from, Vec3 to)
	{
		float num = dxmm::math::sqrt((from.Magnitude() * to.Magnitude()));
		bool  flag = num < 1E-15f;
		float result;
		if (flag)
			result = 0.f;
		else
		{
			float num2 = dxmm::math::clamp(from.Dot(to) / num, -1.f, 1.f);
			result = my_acos(num2) * 57.29578f;
		}
		return result;
	}
	float distancesqr(Vec3 input) const
	{
		Vec3 dif = { x - input.x, y - input.y, z - input.z };
		return dif.x * dif.x + dif.y * dif.y + dif.z * dif.z;
	}

	float DistanceXZ(const Vec3& vector)
	{
		return my_sqrt((x - vector.x) * (x - vector.x) + 0 + (z - vector.z) * (z - vector.z));
	}

	static Vec3 MoveTowards(Vec3 current, Vec3 target, float maxDistanceDelta)
	{
		float num = target.x - current.x;
		float num2 = target.y - current.y;
		float num3 = target.z - current.z;
		float num4 = num * num + num2 * num2 + num3 * num3;
		bool flag = num4 == 0.f || (maxDistanceDelta >= 0.f && num4 <= maxDistanceDelta * maxDistanceDelta);
		Vec3 result;
		if (flag)
		{
			result = target;
		}
		else
		{
			float num5 = (float)my_sqrt((double)num4);
			result = Vec3(current.x + num / num5 * maxDistanceDelta, current.y + num2 / num5 * maxDistanceDelta, current.z + num3 / num5 * maxDistanceDelta);
		}
		return result;
	}

	Vec3 XZ3D()
	{
		return Vec3(this->x, 0.f, this->z);
	}
};
class Vec4
{
public:
	float x, y, z, w;
};
class Vec2 {
public:
	float x, y;

	Vec2() {
		x = y = 0.0f;
	}

	Vec2 operator*(float v) const {
		return Vec2(x * v, y * v);
	}
	Vec2& operator*=(float input)
	{
		x *= input;
		y *= input;
		return *this;
	}
	Vec2 operator/(float v) const {
		return Vec2(x / v, y / v);
	}
	Vec2(float X, float Y) {
		x = X; y = Y;
	}

	Vec2 operator-(const Vec2& v) const {
		return Vec2(x - v.x, y - v.y);
	}

	Vec2 operator+(const Vec2& v) const {
		return Vec2(x + v.x, y + v.y);
	}

	Vec2& operator+=(const Vec2& v) {
		x += v.x; y += v.y; return *this;
	}

	bool empty() const {
		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}

	float distance_2d(const Vec2& other) const {
		return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

	static Vec2 Zero() {
		return Vec2(0.0f, 0.0f);
	}

	float length() const
	{
		return dxmm::math::sqrt((x * x) + (y * y));
	}

	Vec2 normalized() const
	{
		return { x / length(), y / length() };
	}
	void NormalizePredict()
	{

		if (x < -89)
			x = -89;

		else if (x > 89)
			x = 89;

		if (y < -360)
			y += 360;

		else if (y > 360)
			y -= 360;

	}
	static float normalize_angle(float angle)
	{
		while (angle > 360)
			angle -= 360;
		while (angle < 0)
			angle += 360;
		return angle;
	}

	static float my_sqrt(float number) {
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y; // floating point bit level hacking [sic]
		i = 0x5f3759df - (i >> 1); // Newton's approximation
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y)); // 1st iteration
		y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

		return 1 / y;
	}

	Vec2 RotateVertex(const Vec2& v, float angle) {
		float c = dxmm::math::cos(DEG2RAD(angle));
		float s = dxmm::math::sin(DEG2RAD(angle));
		return { this->x + (v.x - this->x) * c - (v.y - this->y) * s, this->y + (v.x - this->x) * s + (v.y - this->y) * c };
	}
	static Vec2 RotatePoint(Vec2 pointToRotate, Vec2 centerPoint, float angle, bool angleInRadians = false)
	{
		float rad = DEG2RAD(normalize_angle(angle));
		float s = (float)-dxmm::math::sin(rad);
		float c = (float)dxmm::math::cos(rad);
		pointToRotate.x -= centerPoint.x;
		pointToRotate.y -= centerPoint.y;
		float xnew = pointToRotate.x * c - pointToRotate.y * s;
		float znew = pointToRotate.x * s + pointToRotate.y * c;
		pointToRotate.x = xnew + centerPoint.x;
		pointToRotate.y = znew + centerPoint.y;
		return pointToRotate;
	}

private:
	float sqrLength() {
		return (x * x + y * y);
	}

};
class Quaternion {
public:
	float x, y, z, w;

	Quaternion() {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion operator*(Quaternion rhs) {
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z
		);
	}

	float Dot(Quaternion b) {
		return x * x + y * y + z * z + w * w;
	}

	Vec3 operator*(Vec3 point) {
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vec3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};
struct Rect_ {
	Vec2 Min;
	Vec2 Max;
	Rect_(const Vec2& min, const Vec2& max) : Min(min), Max(max) {}
	Rect_(float x1, float y1, float x2, float y2) : Min(x1, y1), Max(x2, y2) {}
};
struct HSV {
	float h;
	float s;
	float v;
	float a;
	HSV() {
		h = 0;
		s = 0;
		v = 0;
		a = 255;
	}
	HSV(float h_, float s_, float v_, float a_) {
		h = h_;
		s = s_;
		v = v_;
		a = a_;
	}
};
class color_t {
public:
	float r, g, b, a;
	color_t(int r, int g, int b) : r(r / 255.f), g(g / 255.f), b(b / 255.f), a(255.f) { }
	color_t(int r, int g, int b, int a) : r(r / 255.f), g(g / 255.f), b(b / 255.f), a(a / 255.f) { }
	color_t(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) { }
	color_t(float r, float g, float b) : r(r), g(g), b(b), a(255.f) { }
	color_t() : r(0.f), g(0.f), b(0.f), a(0.f) { }
	color_t unity()
	{
		return color_t(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}
	color_t newunity()
	{
		return color_t(r * 255.0f, g * 255.0f, b * 255.0f, a * 255.0f);
	}
	color_t alpha(int value) {
		return color_t(
			static_cast<int>(r * 255),
			static_cast<int>(g * 255),
			static_cast<int>(b * 255),
			value
		);
	}
	color_t darker(int amount = 20) {
		return color_t(
			static_cast<int>(r * 255) - amount,
			static_cast<int>(g * 255) - amount,
			static_cast<int>(b * 255) - amount,
			static_cast<int>(a * 255)
		);
	}
	color_t lighter(int amount = 20) {
		return color_t(
			static_cast<int>(r * 255) + amount,
			static_cast<int>(g * 255) + amount,
			static_cast<int>(b * 255) + amount,
			static_cast<int>(a * 255)
		);
	}
	Vec3 to_hsv() {
		auto swap_float = [](float& a, float& b) {
			float tmp = a;
			a = b;
			b = tmp;
			};
		float k = 0.f;
		if (g < b) {
			swap_float(g, b);
			k = -1.f;
		}
		if (r < g) {
			swap_float(r, g);
			k = -2.f / 6.f - k;
		}
		float chroma = r - (g < b ? g : b);
		return Vec3(dxmm::math::fabsf(k + (g - b) / (6.f * chroma + 1e-20f)), chroma / (r + 1e-20f), r);
	}
	static color_t hsv(float h, float s, float v, float a = 1.f) {
		float r, g, b;
		auto hsv_to_rgb = [](float h, float s, float v, float& out_r, float& out_g, float& out_b) {
			if (s == 0.0f) {
				// gray
				out_r = out_g = out_b = v;
				return;
			}
			h = dxmm::math::fmod(h, 1.0f) / (60.0f / 360.0f);
			int   i = (int)h;
			float f = h - (float)i;
			float p = v * (1.0f - s);
			float q = v * (1.0f - s * f);
			float t = v * (1.0f - s * (1.0f - f));
			switch (i) {
			case 0: out_r = v; out_g = t; out_b = p; break;
			case 1: out_r = q; out_g = v; out_b = p; break;
			case 2: out_r = p; out_g = v; out_b = t; break;
			case 3: out_r = p; out_g = q; out_b = v; break;
			case 4: out_r = t; out_g = p; out_b = v; break;
			case 5: default: out_r = v; out_g = p; out_b = q; break;
			}
			};
		hsv_to_rgb(h, s, v, r, g, b);
		return color_t(r, g, b, a);
	}
	static color_t FromHSB(float hue, float saturation, float brightness, float alpha = 255) {
		hue = dxmm::math::clamp(hue, 0.f, 1.f);
		saturation = dxmm::math::clamp(saturation, 0.f, 1.f);
		brightness = dxmm::math::clamp(brightness, 0.f, 1.f);
		float h = (hue == 1.f) ? 0.f : (hue * 6.f);
		float f = h - static_cast<int>(h);
		float p = brightness * (1.f - saturation);
		float q = brightness * (1.f - saturation * f);
		float t = brightness * (1.f - (saturation * (1.f - f)));
		if (h < 1.f) return color_t(brightness * 255, t * 255, p * 255, alpha);
		else
			if (h < 2.f) return color_t(q * 255, brightness * 255, p * 255, alpha);
			else
				if (h < 3.f) return color_t(p * 255, brightness * 255, t * 255, alpha);
				else
					if (h < 4) return color_t(p * 255, q * 255, brightness * 255, alpha);
					else
						if (h < 5) return color_t(t * 255, p * 255, brightness * 255, alpha);
						else return color_t(brightness * 255, p * 255, q * 255, alpha);
	}
};
struct CColor {
	float RGBA[4];
	CColor() {
		RGBA[0] = 255;
		RGBA[1] = 255;
		RGBA[2] = 255;
		RGBA[3] = 255;
	}
	CColor(int r, int g, int b, int a = 255) {
		RGBA[0] = r;
		RGBA[1] = g;
		RGBA[2] = b;
		RGBA[3] = a;
	}
	inline int r() const {
		return RGBA[0];
	}
	inline int g() const {
		return RGBA[1];
	}
	inline int b() const {
		return RGBA[2];
	}
	inline int a() const {
		return RGBA[3];
	}
	bool operator!=(CColor color) {
		return RGBA[0] != color.RGBA[0] || RGBA[1] != color.RGBA[1] || RGBA[2] != color.RGBA[2] || RGBA[3] != color.RGBA[3];
	}
	bool operator==(CColor color) {
		return RGBA[0] == color.RGBA[0] && RGBA[1] == color.RGBA[1] && RGBA[2] == color.RGBA[2] && RGBA[3] == color.RGBA[3];
	}

	static float Base(const unsigned char col) {
		return col / 255.f;
	}

	static CColor Inverse(const CColor color) {
		return CColor(255 - color.RGBA[0], 255 - color.RGBA[1], 255 - color.RGBA[2]);
	}

	static float Hue(const CColor color) {
		float R = Base(color.RGBA[0]);
		float G = Base(color.RGBA[1]);
		float B = Base(color.RGBA[2]);
		float mx = max(R, max(G, B));
		float mn = min(R, min(G, B));
		if (mx == mn) return 0.f;
		float delta = mx - mn;
		float hue = 0.f;
		if (mx == R) hue = (G - B) / delta;
		else
			if (mx == G) hue = 2.f + (B - R) / delta;
			else hue = 4.f + (R - G) / delta;

		hue *= 60.f;
		if (hue < 0.f) hue += 360.f;
		return hue / 360.f;
	}
	static float Saturation(const CColor color) {
		float R = Base(color.RGBA[0]);
		float G = Base(color.RGBA[1]);
		float B = Base(color.RGBA[2]);
		float mx = max(R, max(G, B));
		float mn = min(R, min(G, B));
		float delta = mx - mn;
		if (mx == 0.f) return delta;
		return delta / mx;
	}
	static float Brightness(const CColor color) {
		float R = Base(color.RGBA[0]);
		float G = Base(color.RGBA[1]);
		float B = Base(color.RGBA[2]);
		return max(R, max(G, B));
	}
	float Hue() const {
		return Hue(*this);
	}
	float Saturation() const {
		return Saturation(*this);
	}
	float Brightness() const {
		return Brightness(*this);
	}
	static CColor FromHSB(float hue, float saturation, float brightness, int alpha = 255) {
		hue = dxmm::math::clamp(hue, 0.f, 1.f);
		saturation = dxmm::math::clamp(saturation, 0.f, 1.f);
		brightness = dxmm::math::clamp(brightness, 0.f, 1.f);
		float h = (hue == 1.f) ? 0.f : (hue * 6.f);
		float f = h - static_cast<int>(h);
		float p = brightness * (1.f - saturation);
		float q = brightness * (1.f - saturation * f);
		float t = brightness * (1.f - (saturation * (1.f - f)));

		if (h < 1.f) return CColor(brightness * 255, t * 255, p * 255, alpha);
		else
			if (h < 2.f) return CColor(q * 255, brightness * 255, p * 255, alpha);
			else
				if (h < 3.f) return CColor(p * 255, brightness * 255, t * 255, alpha);
				else
					if (h < 4) return CColor(p * 255, q * 255, brightness * 255, alpha);
					else
						if (h < 5) return CColor(t * 255, p * 255, brightness * 255, alpha);
						else return CColor(brightness * 255, p * 255, q * 255, alpha);
	}
};
class Rect {
public:
	float x; // 0x10
	float y; // 0x14
	float wid; // 0x18
	float hei; // 0x1C
	Rect(float x, float y/*top left*/, float x_rightsize, float y_downsize) {
		this->x = x;
		this->y = y;
		wid = x_rightsize;
		hei = y_downsize;
	}
	Rect() {
		this->x = 0;
		this->y = 0;
		wid = 0;
		hei = 0;
	}
	bool Contains(Vec2 point)
	{
		return point.x >= x && point.x < (x + wid) && point.y >= y && point.y < (y + hei);
	}
	bool Contains(Vec3 point)
	{
		return point.x >= this->x && point.x < (this->wid + this->x) && point.y >= this->y &&
			point.y < (this->hei + this->y);
	}
};
enum class ScaleMode
{
	StretchToFill = 0,
	ScaleAndCrop = 1,
	ScaleToFit = 2,
};
enum class render_type {
	line = 1,
	fov,
	box,
	boxoutline,
	triangle,
	gradient
};
enum class TextureColorSpace : int32_t  // TypeDefIndex: 11315
{
	Linear = 0,
	sRGB = 1,
};
enum class TextureCreationFlags : int32_t  // TypeDefIndex: 11855
{
	// Fields
	None = 0,
	MipChain = 1,
	DontInitializePixels = 4,
	Crunch = 64,
	DontUploadUponCreate = 1024,
	IgnoreMipmapLimit = 2048,
};
enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};
enum class KeyCode
{

	Backspace = 8,
	Delete = 127,
	Tab = 9,
	Clear = 12,
	Return = 13,
	Pause = 19,
	Escape = 27,
	Space = 32,
	Keypad0 = 256,
	Keypad1 = 257,
	Keypad2 = 258,
	Keypad3 = 259,
	Keypad4 = 260,
	Keypad5 = 261,
	Keypad6 = 262,
	Keypad7 = 263,
	Keypad8 = 264,
	Keypad9 = 265,
	KeypadPeriod = 266,
	KeypadDivide = 267,
	KeypadMultiply = 268,
	KeypadMinus = 269,
	KeypadPlus = 270,
	KeypadEnter = 271,
	KeypadEquals = 272,
	UpArrow = 273,
	DownArrow = 274,
	RightArrow = 275,
	LeftArrow = 276,
	Insert = 277,
	Home = 278,
	End = 279,
	PageUp = 280,
	PageDown = 281,
	F1 = 282,
	F2 = 283,
	F3 = 284,
	F4 = 285,
	F5 = 286,
	F6 = 287,
	F7 = 288,
	F8 = 289,
	F9 = 290,
	F10 = 291,
	F11 = 292,
	F12 = 293,
	F13 = 294,
	F14 = 295,
	F15 = 296,
	Alpha0 = 48,
	Alpha1 = 49,
	Alpha2 = 50,
	Alpha3 = 51,
	Alpha4 = 52,
	Alpha5 = 53,
	Alpha6 = 54,
	Alpha7 = 55,
	Alpha8 = 56,
	Alpha9 = 57,
	Exclaim = 33,
	DoubleQuote = 34,
	Hash = 35,
	Dollar = 36,
	Percent = 37,
	Ampersand = 38,
	Quote = 39,
	LeftParen = 40,
	RightParen = 41,
	Asterisk = 42,
	Plus = 43,
	Comma = 44,
	Minus = 45,
	Period = 46,
	Slash = 47,
	Colon = 58,
	Semicolon = 59,
	Less = 60,
	Equals = 61,
	Greater = 62,
	Question = 63,
	At = 64,
	LeftBracket = 91,
	Backslash = 92,
	RightBracket = 93,
	Caret = 94,
	Underscore = 95,
	BackQuote = 96,
	A = 97,
	B = 98,
	C = 99,
	D = 100,
	E = 101,
	F = 102,
	G = 103,
	H = 104,
	I = 105,
	J = 106,
	K = 107,
	L = 108,
	M = 109,
	N = 110,
	O = 111,
	P = 112,
	Q = 113,
	R = 114,
	S = 115,
	T = 116,
	U = 117,
	V = 118,
	W = 119,
	X = 120,
	Y = 121,
	Z = 122,
	LeftCurlyBracket = 123,
	Pipe = 124,
	RightCurlyBracket = 125,
	Tilde = 126,
	Numlock = 300,
	CapsLock = 301,
	ScrollLock = 302,
	RightShift = 303,
	LeftShift = 304,
	RightControl = 305,
	LeftControl = 306,
	RightAlt = 307,
	LeftAlt = 308,
	LeftCommand = 310,
	LeftApple = 310,
	LeftWindows = 311,
	RightCommand = 309,
	RightApple = 309,
	RightWindows = 312,
	AltGr = 313,
	Help = 315,
	Pr = 316,
	SysReq = 317,
	Break = 318,
	Menu = 319,
	Mouse0 = 323,
	Mouse1 = 324,
	Mouse2 = 325,
	Mouse3 = 326,
	Mouse4 = 327,
	Mouse5 = 328,
	Mouse6 = 329,
	nothing = 0
};
enum class GraphicsFormat : int32_t // TypeDefIndex: 11858
{
	None = 0,
	R8_SRGB = 1,
	R8G8_SRGB = 2,
	R8G8B8_SRGB = 3,
	R8G8B8A8_SRGB = 4,
	R8_UNorm = 5,
	R8G8_UNorm = 6,
	R8G8B8_UNorm = 7,
	R8G8B8A8_UNorm = 8,
	R8_SNorm = 9,
	R8G8_SNorm = 10,
	R8G8B8_SNorm = 11,
	R8G8B8A8_SNorm = 12,
	R8_UInt = 13,
	R8G8_UInt = 14,
	R8G8B8_UInt = 15,
	R8G8B8A8_UInt = 16,
	R8_SInt = 17,
	R8G8_SInt = 18,
	R8G8B8_SInt = 19,
	R8G8B8A8_SInt = 20,
	R16_UNorm = 21,
	R16G16_UNorm = 22,
	R16G16B16_UNorm = 23,
	R16G16B16A16_UNorm = 24,
	R16_SNorm = 25,
	R16G16_SNorm = 26,
	R16G16B16_SNorm = 27,
	R16G16B16A16_SNorm = 28,
	R16_UInt = 29,
	R16G16_UInt = 30,
	R16G16B16_UInt = 31,
	R16G16B16A16_UInt = 32,
	R16_SInt = 33,
	R16G16_SInt = 34,
	R16G16B16_SInt = 35,
	R16G16B16A16_SInt = 36,
	R32_UInt = 37,
	R32G32_UInt = 38,
	R32G32B32_UInt = 39,
	R32G32B32A32_UInt = 40,
	R32_SInt = 41,
	R32G32_SInt = 42,
	R32G32B32_SInt = 43,
	R32G32B32A32_SInt = 44,
	R16_SFloat = 45,
	R16G16_SFloat = 46,
	R16G16B16_SFloat = 47,
	R16G16B16A16_SFloat = 48,
	R32_SFloat = 49,
	R32G32_SFloat = 50,
	R32G32B32_SFloat = 51,
	R32G32B32A32_SFloat = 52,
	B8G8R8_SRGB = 56,
	B8G8R8A8_SRGB = 57,
	B8G8R8_UNorm = 58,
	B8G8R8A8_UNorm = 59,
	B8G8R8_SNorm = 60,
	B8G8R8A8_SNorm = 61,
	B8G8R8_UInt = 62,
	B8G8R8A8_UInt = 63,
	B8G8R8_SInt = 64,
	B8G8R8A8_SInt = 65,
	R4G4B4A4_UNormPack16 = 66,
	B4G4R4A4_UNormPack16 = 67,
	R5G6B5_UNormPack16 = 68,
	B5G6R5_UNormPack16 = 69,
	R5G5B5A1_UNormPack16 = 70,
	B5G5R5A1_UNormPack16 = 71,
	A1R5G5B5_UNormPack16 = 72,
	E5B9G9R9_UFloatPack32 = 73,
	B10G11R11_UFloatPack32 = 74,
	A2B10G10R10_UNormPack32 = 75,
	A2B10G10R10_UIntPack32 = 76,
	A2B10G10R10_SIntPack32 = 77,
	A2R10G10B10_UNormPack32 = 78,
	A2R10G10B10_UIntPack32 = 79,
	A2R10G10B10_SIntPack32 = 80,
	A2R10G10B10_XRSRGBPack32 = 81,
	A2R10G10B10_XRUNormPack32 = 82,
	R10G10B10_XRSRGBPack32 = 83,
	R10G10B10_XRUNormPack32 = 84,
	A10R10G10B10_XRSRGBPack32 = 85,
	A10R10G10B10_XRUNormPack32 = 86,
	D16_UNorm = 90,
	D24_UNorm = 91,
	D24_UNorm_S8_UInt = 92,
	D32_SFloat = 93,
	D32_SFloat_S8_UInt = 94,
	S8_UInt = 95,
	RGB_DXT1_SRGB = 96,
	RGBA_DXT1_SRGB = 96,
	RGB_DXT1_UNorm = 97,
	RGBA_DXT1_UNorm = 97,
	RGBA_DXT3_SRGB = 98,
	RGBA_DXT3_UNorm = 99,
	RGBA_DXT5_SRGB = 100,
	RGBA_DXT5_UNorm = 101,
	R_BC4_UNorm = 102,
	R_BC4_SNorm = 103,
	RG_BC5_UNorm = 104,
	RG_BC5_SNorm = 105,
	RGB_BC6H_UFloat = 106,
	RGB_BC6H_SFloat = 107,
	RGBA_BC7_SRGB = 108,
	RGBA_BC7_UNorm = 109,
	RGB_PVRTC_2Bpp_SRGB = 110,
	RGB_PVRTC_2Bpp_UNorm = 111,
	RGB_PVRTC_4Bpp_SRGB = 112,
	RGB_PVRTC_4Bpp_UNorm = 113,
	RGBA_PVRTC_2Bpp_SRGB = 114,
	RGBA_PVRTC_2Bpp_UNorm = 115,
	RGBA_PVRTC_4Bpp_SRGB = 116,
	RGBA_PVRTC_4Bpp_UNorm = 117,
	RGB_ETC_UNorm = 118,
	RGB_ETC2_SRGB = 119,
	RGB_ETC2_UNorm = 120,
	RGB_A1_ETC2_SRGB = 121,
	RGB_A1_ETC2_UNorm = 122,
	RGBA_ETC2_SRGB = 123,
	RGBA_ETC2_UNorm = 124,
	R_EAC_UNorm = 125,
	R_EAC_SNorm = 126,
	RG_EAC_UNorm = 127,
	RG_EAC_SNorm = 128,
	RGBA_ASTC4X4_SRGB = 129,
	RGBA_ASTC4X4_UNorm = 130,
	RGBA_ASTC5X5_SRGB = 131,
	RGBA_ASTC5X5_UNorm = 132,
	RGBA_ASTC6X6_SRGB = 133,
	RGBA_ASTC6X6_UNorm = 134,
	RGBA_ASTC8X8_SRGB = 135,
	RGBA_ASTC8X8_UNorm = 136,
	RGBA_ASTC10X10_SRGB = 137,
	RGBA_ASTC10X10_UNorm = 138,
	RGBA_ASTC12X12_SRGB = 139,
	RGBA_ASTC12X12_UNorm = 140,
	YUV2 = 141,
	DepthAuto = 142,
	ShadowAuto = 143,
	VideoAuto = 144,
	RGBA_ASTC4X4_UFloat = 145,
	RGBA_ASTC5X5_UFloat = 146,
	RGBA_ASTC6X6_UFloat = 147,
	RGBA_ASTC8X8_UFloat = 148,
	RGBA_ASTC10X10_UFloat = 149,
	RGBA_ASTC12X12_UFloat = 150,
	D16_UNorm_S8_UInt = 151,
};
class Str {
    char zpad[0x10]; // 可能是为了内存对齐
public:
    int size;
    wchar_t str[MAX_STRING_LEN + 1]; // 存储宽字符字符串

    // 默认构造函数
    Str() : size(0) {
        str[0] = L'\0'; // 初始化为空字符串
    }

    // 通过宽字符字符串构造
    Str(const wchar_t* st) {
        if (st) {
            size = dxmm::string::wcsnlen(st, MAX_STRING_LEN);
            for (int i = 0; i < size; i++) {
                str[i] = st[i];
            }
            str[size] = L'\0'; // 确保字符串以 '\0' 结尾
        } else {
            size = 0;
            str[0] = L'\0'; // 空字符串
        }
    }
};

struct Matrix4x4Line
{
	float m00; float m10; float m20; float m30;
	float m01; float m11; float m21; float m31;
	float m02; float m12; float m22; float m32;
	float m03; float m13; float m23; float m33;

	Matrix4x4Line Identity() {
		this->m00 = 1.f;
		this->m11 = 1.f;
		this->m22 = 1.f;
		this->m33 = 1.f;
		return *this;
	}
};

class Type {
public:
	static Type* FromClass(const char* name, const char* namespaze)
	{
		auto klass = Il2cpp::InitClass(name, namespaze);

		if (!klass)
			return nullptr;

		auto type = Il2cpp::class_get_type(klass);

		if (!type)
			return nullptr;

		return (Type*)Il2cpp::type_get_object(type);
	}

	static Type* GetType(Str qualified_name) {
		return reinterpret_cast<Type * (__cdecl*)(Str)>(g_Base + 0x9426b40)(qualified_name);
	}
	static Type* SkinnedMeshRenderer() {
		Type* type = GetType(xor (L"UnityEngine.SkinnedMeshRenderer, UnityEngine.CoreModule"));
		return type;
	}
	static Type* Renderer() {
		Type* type = GetType(xor (L"UnityEngine.Renderer, UnityEngine.CoreModule"));
		return type;
	}
	static Type* Shader() {
		Type* type = GetType(xor (L"UnityEngine.Shader, UnityEngine.CoreModule"));
		return type;
	}
	static Type* Projectile() {
		Type* type = GetType(xor (L"Projectile, Assembly-CSharp"));
		return type;
	}
	static Type* ItemModProjectile() {
		Type* type = GetType(xor (L"ItemModProjectile, Assembly-CSharp"));
		return type;
	}
};
namespace UnityEngine {

	class Shader {
	public:
		static Shader* Find(Str name) {
			return reinterpret_cast<Shader * (*)(Str)>(g_Base + 0xb82eb20)(name);
		}
	};

	class Material {
	public:
		static void CreateWithShader(Material* self, Shader* shader) {
			return reinterpret_cast<void(*)(Material*, Shader*)>(g_Base + 0xb830590)(self, shader);
		}
		void SetInt(Str* property, std::int32_t value) {
			return reinterpret_cast<void(*)(void*, Str*, std::int32_t)>(g_Base + 0xb832840)(this, property, value);
		}
		void SetPass(std::int32_t pass) {
			return reinterpret_cast<void(*)(void*, std::int32_t)>(g_Base + 0xb831e90)(this, pass);
		}
	};

	class Rect {
	public:
		float x, y, w, h;
	public:
		explicit Rect(float l, float t, float r, float b) : x(l), y(t), w(r), h(b) { }
	};

	class Color {
	public:
		float R, G, B, A;
	public:
		explicit Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(a) { }
	};

	class Vector2 {
	public:
		float x, y;
	public:
		Vector2() : x(0.f), y(0.f) { }
		explicit Vector2(float x, float y) : x(x), y(y) { }
	};
	class Vector3 {
	public:
		float x, y, z;
	public:
		Vector3() : x(0.f), y(0.f), z(0.f) { }
		explicit Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
	};

	class Vector4 {
	public:
		float x, y, z, w;
	public:
		Vector4() : x(0.f), y(0.f), z(0.f), w(0.f) { }
		explicit Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
	};
	class Object {
	public:
		static __int64 FindObjectFromInstanceID(int object) {
			return reinterpret_cast<__int64(*)(int)>(g_Base + 0xb864a30)(object);
		}
		static int GetInstanceID(void* object) {
			return reinterpret_cast<int(*)(void*)>(g_Base + 0xb8629f0)(object);
		}
		static void DontDestroyOnLoad(void* object) {
			return reinterpret_cast<void(*)(void*)>(g_Base + 0xb863d80)(object);
		}
	};
	class GameObject : public Object {
	public:
		static void Internal_CreateGameObject(void* il2cppObject, Str name) {
			return reinterpret_cast<void(*)(void*, Str)>(g_Base + 0xb85ed80)(il2cppObject, name);
		}
		class Component* AddComponent(void* classType) {
			return reinterpret_cast<Component * (*)(void*, void*)>(g_Base + 0xb85e350)(this, classType);
		}
	};
	
	class GUIContent {
	public:
		static GUIContent* Temp(Str* str) {
			return reinterpret_cast<GUIContent * (*)(Str*)>(g_Base + 0xb8a5f40)(str);
		}
	};

	class GUIStyle {
	public:
		int get_fontSize() {
			return reinterpret_cast<std::int32_t(*)(GUIStyle*)>(g_Base + 0xb8b1650)(this);
		}
		void set_fontSize(std::int32_t value) {
			return reinterpret_cast<void(*)(GUIStyle*, std::int32_t)>(g_Base + 0xb8b16a0)(this, value);
		}
		Vec2 CalcSize(Str* text) {
			const auto content = GUIContent::Temp(text);
			Vec2 size{ };
			reinterpret_cast<void(*)(void*, GUIContent*, Vec2&)>(g_Base + 0xb8b4660)(this, content, size);
			return size;
		}
		__declspec(property(get = get_fontSize, put = set_fontSize)) std::int32_t fontSize;
	};

	class Texture2D {
	public:
		static UnityEngine::Texture2D* get_whiteTexture() {
			return reinterpret_cast<UnityEngine::Texture2D * (*)()>(g_Base + 0xb841f90)();
		}

		void Apply(bool a1) {
			return reinterpret_cast<void(*)(Texture2D*, bool)>(g_Base + 0xb844110)(this, a1);
		}
		void SetPixel(int a1, int a2, color_t a3) {
			return reinterpret_cast<void(*)(Texture2D*, int, int, color_t)>(g_Base + 0xb843900)(this, a1, a2, a3);
		}

		static void Create(Texture2D* a0, int w, int h, int mipCount, GraphicsFormat format, TextureColorSpace colorSpace, TextureCreationFlags flags, __int64 nativeTex, Str mipmapLimitGroupName) {
			return reinterpret_cast<void(*)(Texture2D*, int, int, int, GraphicsFormat, TextureColorSpace, TextureCreationFlags, __int64, Str)>(g_Base + 0xb842250)(a0, w, h, mipCount, format, colorSpace, flags, nativeTex, mipmapLimitGroupName);
		}
	};

	class Screen {
	public:
		static int get_height() {
			return reinterpret_cast<int(*)()>(g_Base + 0x77880d0)();
		}
		static int get_width() {
			return reinterpret_cast<int(*)()>(g_Base + 0x77883f0)();
		}
	};

	class Input {
	public:
		static Vec2 get_mouseScrollDelta() {
			auto get_mouse_scroll_delta = reinterpret_cast<void(*)(Vec2&)>(g_Base + 0xb8c7570);
			Vec2 out;
			get_mouse_scroll_delta(out);
			return out;
		}
		static Vector3 get_mousePosition() {
			auto get_mouse_position = reinterpret_cast<void(*)(Vector3&)>(g_Base + 0xb8c7520);
			Vector3 out;
			get_mouse_position(out);
			return out;
		}
		static bool GetMouseButton(int button) {
			return reinterpret_cast<bool(*)(int)>(g_Base + 0xb8c6be0)(button);
		}
		static bool GetKeyInt(int button) {
			return reinterpret_cast<bool(*)(int)>(g_Base + 0xb8c6af0)(button);
		}

		static float GetAxis(Str* axis) {
			return reinterpret_cast<float(*)(Str*)>(g_Base + 0xb8c6ea0)(axis);
		}
	};
	class Event {
	public:
		enum class EventType : int32_t {
			MouseDown = 0,
			MouseUp = 1,
			MouseDrag = 3,
			KeyDown = 4,
			KeyUp = 5,
			Repaint = 7
		};
		static Event* get_current() {
			return reinterpret_cast<Event * (*)()>(g_Base + 0xb898400)();
		}
		EventType get_type() {
			return reinterpret_cast<EventType(*)(void*)>(g_Base + 0xb897a80)(this);
		}
		static KeyCode get_keyCode() {
			return reinterpret_cast<KeyCode(*)()>(g_Base + 0xb8979c0)();
		}
		__declspec(property(get = get_type)) EventType type;
	};


	class GUIClip {
	public:
		static void Push(UnityEngine::Rect screenRect, UnityEngine::Vector2 scrollOffset, UnityEngine::Vector2 renderOffset, bool resetOffset) {
			auto push = reinterpret_cast<void(*)(UnityEngine::Rect&, UnityEngine::Vector2&, UnityEngine::Vector2&, bool)>(g_Base + 0xb8a5770);
			return push(screenRect, scrollOffset, renderOffset, resetOffset);
		}
		static void Pop() {
			auto pop = reinterpret_cast<void(*)()>(g_Base + 0xb8a53d0);
			return pop();
		}
	};

	class GUISkin {
	public:
		FIELD(0x18, font, void*);
		GUIStyle* get_label() {
			return reinterpret_cast<GUIStyle * (*)(decltype(this))>(g_Base + 0xb8adf80)(this);
		}
		void set_font(void* skintesterbyafamose1) {
			return reinterpret_cast<void(*)(GUISkin*, void*)>(g_Base + 0xb8add50)(this, skintesterbyafamose1);
		}
		void* get_font() {
			return reinterpret_cast<void* (*)(GUISkin*)>(g_Base + 0xb875820)(this);
		}
		__declspec(property(get = get_label)) UnityEngine::GUIStyle* label;
	};


	class GUI {
	public:

		static GUISkin* get_skin() {
			return reinterpret_cast<UnityEngine::GUISkin * (*)()>(g_Base + 0xb89bf30)();
		}
		static void set_color(UnityEngine::Color value) {
			return reinterpret_cast<void(*)(UnityEngine::Color)>(g_Base + 0xb89b310)(value);
		}
		static void DrawTexture(UnityEngine::Rect position, void* image) {
			return reinterpret_cast<void(*)(UnityEngine::Rect, void*)>(g_Base + 0xb89c880)(position, image);
		}
		static void DrawTexture2(UnityEngine::Rect Position, UnityEngine::Texture2D* Texture, int32_t ScaleMode, bool AlphaBlend, float ImageAspect, UnityEngine::Color Color, float BorderWidth, float BorderRadius) {
			return reinterpret_cast<void(*)(UnityEngine::Rect, UnityEngine::Texture2D*, int32_t, bool, float, UnityEngine::Color, float, float)>(g_Base + 0xb89cec0)(Position, Texture, ScaleMode, AlphaBlend, ImageAspect, Color, BorderWidth, BorderRadius);
		}
		static void DrawTexture3(UnityEngine::Rect Position, UnityEngine::Texture2D* Texture, int32_t ScaleMode, bool AlphaBlend, float ImageAspect, UnityEngine::Color Color, Vector4 BorderWidths, Vector4 BorderRadiuses, bool DrawSmoothCorners) {
			return reinterpret_cast<void (*)(UnityEngine::Rect, UnityEngine::Texture2D*, int32_t, bool, float, UnityEngine::Color, Vector4, Vector4, bool)>(g_Base + 0xb89d600)(Position, Texture, ScaleMode, AlphaBlend, ImageAspect, Color, BorderWidths, BorderRadiuses, DrawSmoothCorners);
		}
		static void Label(UnityEngine::Rect rect, GUIContent* text, void* style) {
			return reinterpret_cast<void(*)(UnityEngine::Rect, GUIContent*, void*)>(g_Base + 0xB89C7D0)(rect, text, style);
		}
	}; 

	class GL {
	public:
		enum Mode : std::int32_t {
			Lines = 1,
			LineStrip = 2,
			Triangles = 4,
			TriangleStrip = 5,
			Quads = 7
		};
		static void MultMatrix(Matrix4x4Line pizedc) {
			return reinterpret_cast<void(*)(Matrix4x4Line)>(g_Base + 0xb828720)(pizedc);
		}

		static void PushMatrix() {
			return reinterpret_cast<void(*)()>(g_Base + 0xb828810)();
		}

		static void PopMatrix() {
			return reinterpret_cast<void(*)()>(g_Base + 0xb828860)();
		}

		static void Begin(Mode mode) {
			return reinterpret_cast<void(*)(Mode)>(g_Base + 0xb828c80)(mode);
		}

		static void End() {
			return reinterpret_cast<void(*)()>(g_Base + 0xb828cd0)();
		}

		static void Color(UnityEngine::Color color) {
			return reinterpret_cast<void(*)(UnityEngine::Color)>(g_Base + 0xb828490)(color);
		}

		static void Vertex3(float x, float y, float z) {
			return reinterpret_cast<void(*)(float, float, float)>(g_Base + 0xb8281d0)(x, y, z);
		}
	};

	class AssetBundle {
	public:
		void UnloadBundle(bool UnloadAssets = true) {
			auto Unload_Bundle = reinterpret_cast<void(*)(AssetBundle*, bool)>(g_Base + 0xb8055d0);
			return Unload_Bundle(this, UnloadAssets);
		}
		static AssetBundle* LoadFromFile(Str path) {
			auto load_from_file = reinterpret_cast<AssetBundle * (*)(Str)>(g_Base + 0xb804eb0);
			return load_from_file(path);
		}
		template<typename T>
		T LoadAsset(Str name, Type* type) {
			auto load_asset = reinterpret_cast<T(*)(void*, Str, Type*)>(g_Base + 0xb804f70);
			return load_asset(this, name, type);
		}
	};
}

struct matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
};

enum PlayerFlags : int32_t
{
	admin = 4,
	snapshot = 8,
	sleeping = 16,
	spectating = 32,
	wounded = 64,
	developer = 128,
	connected = 256,
	thirdperson = 1024,
	eyesviewmode = 2048,
	muted = 4096,
	nosprint = 8192,
	aiming = 16384,
	sash = 32768,
	relaxed = 65536,
	safezone = 131072,
	serverfall = 262144,
	workbench1 = 1048576,
	workbench2 = 2097152,
	workbench3 = 4194304
};

template<typename T = void*>
struct List {
public:
	char pad_0000[0x10];
	void* buffer;
	uint32_t size;

	T* get(uint32_t idx) {
		if (!this) return nullptr;
		if (idx > this->size) return nullptr;
		void* items = this->buffer;
		if (!items) return nullptr;
		return *reinterpret_cast<T**>((uint64_t)items + (0x20 + (idx * 0x8)));
	}
};

class Transform{
public:
	Vec3 Position()
	{
		if (!this) return Vec3::Zero();
		return reinterpret_cast<Vec3(*)(Transform*)>(g_Base + 0xb86cf60)(this);
	}

};

class PlayerInput
{
public:
	FIELD(offsets::Player_Input::bodyAngles, bodyAngles, Vec3);

};

class Phrase {
public:
	const wchar_t* english() {
		if (!this) return xor (L"");
		if (!(*reinterpret_cast<System::String**>(this + 0x18)) || !(*reinterpret_cast<System::String**>(this + 0x18))->buffer) return xor (L"");
		return (*reinterpret_cast<System::String**>(this + 0x18))->buffer;
	}
};

class ItemDefinition  {
public:
	FIELD(offsets::ItemDefinition::displayName, displayName, Phrase*);
	FIELD(offsets::ItemDefinition::itemid, itemid, int);
	//FIELD(offsets::ItemDefinition::category, category, ItemCategory);
	FIELD(offsets::ItemDefinition::iconSprite, iconSprite, void*);
	const wchar_t* shortname() {
		if (!this) return xor (L"");
		return (*reinterpret_cast<System::String**>(this + offsets::ItemDefinition::shortname))->buffer;
	}
};

class Item {
public:
	FIELD(offsets::item::uid, uid, uint32_t);
	FIELD(offsets::item::info, info, ItemDefinition*);
	template<typename T = void*>
	T* heldEntity() {
		if (!this) return nullptr;
		return *reinterpret_cast<T**>(this + offsets::item::heldEntity);
	}
};

class ItemContainer {
public:
	FIELD(offsets::item::ItemList, itemList, List<Item*>*);
};

class PlayerInventory {
public:
	FIELD(offsets::player_inventory::containerBelt, containerBelt, ItemContainer*);
	FIELD(offsets::player_inventory::containerWearing, containerWear, ItemContainer*);
};

class BaseEntity
{
public:
	FIELD(offsets::prefabID, prefabID, uint32_t);


	Transform* get_transform() {
		if (!this || !dxmm::memory::IsValidCheck(this)) {
			return 0;
		}
		return reinterpret_cast<Transform * (*)(void*)>(g_Base + 0x3c22090)(this);
	}

	Vec3 GetOriginPosition()
	{
		return this->get_transform()->Position();
	}

};
class BasePlayer
{
public:
	enum class LifeState {
		Alive = 0,
		Dead = 1
	};
	FIELD(offsets::base_player::lifestate, lifestate, LifeState);

	FIELD(offsets::base_player::CurrentTeam, currentTeam, uint32_t);
	FIELD(offsets::base_player::PlayerInput, input, PlayerInput*);
	FIELD(offsets::base_player::PlayerInventory, inventory, PlayerInventory*);
	FIELD(offsets::base_player::clActiveItem, clActiveItem, uint32_t);

	const wchar_t* _displayName() {
		if (!this) return xor (L"");
		System::String* name = (System::String*)dxmm::memory::Read<__int64>((__int64)this + offsets::base_player::_displayName);
		if (name) {
			wchar_t* end = name->buffer;
			if (end) return end;
		}
	}

	Transform* get_transform() {
		if (!this || !dxmm::memory::IsValidCheck(this)) {
			return 0;
		}
		return reinterpret_cast<Transform * (*)(void*)>(g_Base + 0x3c22090)(this);
	}

	Vec3 GetOriginPosition()
	{
		return this->get_transform()->Position();
	}

	bool isSleeping() {

		int flags = dxmm::memory::Read<int>(this + offsets::base_player::playerFlags);
		PlayerFlags flag = static_cast<PlayerFlags>(flags);
		return (flags & sleeping);
	}

	Transform* GetTransform(int bone) {
		if (!this) return 0;
		__int64 player_model = dxmm::memory::Read<__int64>((__int64)this + offsets::base_player::model);
		__int64 boneTransforms = dxmm::memory::Read<__int64>(player_model + offsets::model::boneTransforms);
		Transform* BoneValue = dxmm::memory::Read<Transform*>(boneTransforms + 0x20 + bone * 0x8);
		return BoneValue;
	}

	uint32_t clActiveItem_() 
	{
		return decrypt::decrypt_uint32(this->clActiveItem());
	}

	PlayerInventory* Get_inventory()
	{
		return (PlayerInventory*)decrypt::inventory_key((uint64_t)this->inventory());
	}

	Item* GetHeldItem() {
		if (!this) return nullptr;
		auto inventory = Get_inventory();
		if (!inventory) return nullptr;
		auto belt = inventory->containerBelt();
		if (!belt) return nullptr;
		auto item_list = belt->itemList();
		if (!item_list) return nullptr;
		for (int i = 0; i < item_list->size; i++) {
			auto item = reinterpret_cast<Item*>(item_list->get(i));
			if (!item) continue;
			if (item->uid() == clActiveItem_()) return item;
		}
		return nullptr;
	}

};

class RaycastHit {
public:
	Vec3 point = Vec3(); // 0x0
	Vec3 normal = Vec3(); // 0xC
	unsigned int faceID; // 0x18
	float distance; // 0x1C
	Vec2 uv; // 0x20
	int collider; // 0x28

	RaycastHit() {
		point = Vec3::Zero();
		normal = Vec3::Zero();
		faceID = 0;
		distance = 0;
		uv = Vec2();
		collider = 0;
	}
};

struct Ray {
public:
	Vec3 m_Origin;
	Vec3 m_Direction;
	Ray() {
		this->m_Origin = Vec3(0, 0, 0);
		this->m_Direction = Vec3(0, 0, 0);
	}
	Ray(Vec3 origin, Vec3 direction) {
		this->m_Origin = origin;
		this->m_Direction = direction;
	}
	Vec3 ClosestPoint(Vec3 pos) {
		return this->m_Origin + this->m_Direction * (pos - this->m_Origin).Dot(this->m_Direction);
	}
};

class GamePhysics {
public:
	enum QueryTriggerInteraction
	{
		UseGlobal,
		Ignore,
		Collide
	};
};

enum class Layers
{
	z = 1503731969,
	Terrain = 8388608,
	World = 65536,
	Ragdolls = 512,
	Construction = 2097152,
	ConstructionSocket = 4194304,
	Craters = 1,
	GameTrace = 16384,
	Trigger = 262144,
	VehiclesDetailed = 8192,
	RainFall = 1101070337,
	Deploy = 1235288065,
	DefaultDeployVolumeCheck = 537001984,
	BuildLineOfSightCheck = 2097152,
	ProjectileLineOfSightCheck = 2162688,
	ProjectileLineOfSightCheckTerrain = 10551296,
	MeleeLineOfSightCheck = 2162688,
	EyeLineOfSightCheck = 2162688,
	EntityLineOfSightCheck = 1218519041,
	PlayerBuildings = 18874624,
	PlannerPlacement = 161546496,
	Solid = 1218652417,
	VisCulling = 10551297,
	AltitudeCheck = 1218511105,
	HABGroundEffect = 1218511105,
	AILineOfSight = 1218519297,
	DismountCheck = 1486946561,
	AIPlacement = 278986753,
	WheelRay = 1235321089,
};

class Physics {
public:
	static bool Raycast(Ray ray, RaycastHit* hitInfo, float maxDistance, int32_t layerMask,
		GamePhysics::QueryTriggerInteraction triggerInteraction)
	{
		return reinterpret_cast<bool(*)(Ray, RaycastHit*, float, int32_t, GamePhysics::QueryTriggerInteraction)>(g_Base + 0xb8d4f20)(ray, hitInfo, maxDistance, layerMask, triggerInteraction);

	}
	static bool Raycast(Ray a1, float maxDistance, int32_t layerMask,
		GamePhysics::QueryTriggerInteraction triggerInteraction) {
		return reinterpret_cast<bool(*)(Ray, float, int32_t, GamePhysics::QueryTriggerInteraction)>(g_Base + 0xb8d4c30)(a1, maxDistance, layerMask, triggerInteraction);
	}
	static bool is_visible(Vec3 p1, Vec3 p2)
	{
		auto local = p1;
		auto pos2 = p2;

		auto direction = pos2 - local;
		float dist = direction.Magnitude() * 0.9f;
		auto ray = Ray(local, direction);
		return !Raycast(ray, dist, (int32_t)Layers::EntityLineOfSightCheck, GamePhysics::QueryTriggerInteraction::UseGlobal);
	}
};


namespace Unity {
	UnityEngine::AssetBundle* MyFont = 0;
	bool CanOverWriteAssets = false;
}
