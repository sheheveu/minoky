#include "math.h"

namespace dxmm::math {
	double fabsf(double num) {
		if (num < 0) {
			return -num;
		}
		return num;
	}
	float roundf(float x) {
		if (x >= 0.0) {
			if (x - int(x) >= 0.5)
				return int(x) + 1;
			else
				return int(x);
		}
		else {
			if (fabsf(x - int(x)) >= 0.5)
				return int(x) - 1;
			else
				return int(x);
		}
	}
	float lerp(float a, float b, float t)
	{
		return a + (b - a) * t;
	}
	int abs(int x)
	{
		int s = x >> 31;
		return (x ^ s) - s;
	}

	double floor(double x)
	{
		return (x >= 0) ? (int)x : (x == (int)x ? x : (int)x - 1);
	}

	int xfloor(float value) {
		int fl = static_cast<int>(value);
		return (value < 0 && value != fl) ? fl - 1 : fl;
	}
	double ceil(double x)
	{
		return (x >= 0) ? ((x == (int)x) ? (int)x : (int)x + 1) : ((x == (int)x) ? (int)x + 1 : (int)x);
	}

	float cos(float x)
	{
		if (x < 0)
		{
			int q = -x / DOUBLE_PI;
			q += 1;
			double y = q * DOUBLE_PI;
			x = -(x - y);
		}
		if (x >= DOUBLE_PI)
		{
			int q = x / DOUBLE_PI;
			double y = q * DOUBLE_PI;
			x = x - y;
		}
		int s = 1;
		if (x >= PI)
		{
			s = -1;
			x -= PI;
		}
		if (x > HALF_PI)
		{
			x = PI - x;
			s = -s;
		}
		double z = x * x;
		double r = z * (z * (SIN_CURVE_A - SIN_CURVE_B * z) - 0.5) + 1.0;
		if (r > 1.0)
			r = r - 2.0;
		if (s > 0)
			return r;
		else return -r;
	}

	float sin(float x)
	{
		return cos(x - HALF_PI);
	}

	float pow(float a, float b)
	{
		union
		{
			double d;
			int x[2];
		} u = { a };
		u.x[1] = (int)(b * (u.x[1] - 1072632447) + 1072632447);
		u.x[0] = 0;
		return u.d;
	}

	float sqrt(float a)
	{
		float b = a;
		int* x = (int*)(&b);
		int c = ((*x >> 23) & 255) - 127;
		if (c < 0)
		{
			c = -((-c) >> 1);
		}
		else
		{
			c >>= 1;
		}

		*x &= ~(255 << 23);

		*x |= (c + 127) << 23;

		for (int i = 0; i < 5; i++)
		{
			b = (b + a / b) / 2;
		}

		return b;
	}
	double tan2(double x) {
		double tanValue = 0.0;
		double term = x;
		double numerator = x;
		double denominator = 1.0;
		int i = 1;

		while (term != 0.0) {
			tanValue += term;
			numerator *= x * x;
			denominator = 2 * i + 1;
			term = numerator / denominator;
			i++;
		}

		return tanValue;
	}
	float atan(float v)
	{
		float v2 = v * v;
		return (v * (1.6867629106f + v2 * 0.4378497304f) / (1.6867633134f + v2));
	}

	float atan2(float y, float x)
	{
		if (x >= 0)
		{
			if (y >= 0)
			{
				if (y < x)
				{
					return atan(y / x);
				}
				else
				{
					return HALF_PI - atan(x / y);
				}
			}
			else
			{
				if (-y < x)
				{
					return atan(y / x);
				}
				else
				{
					return -HALF_PI - atan(x / y);
				}
			}
		}
		else
		{
			if (y >= 0)
			{
				if (y < -x)
				{
					return atan(y / x) + PI;
				}
				else
				{
					return HALF_PI - atan(x / y);
				}
			}
			else
			{
				if (-y < -x)
				{
					return atan(y / x) - PI;
				}
				else
				{
					return -HALF_PI - atan(x / y);
				}
			}
		}
	}

	float fmod(float a, float b)
	{
		return (a - b * floor(a / b));
	}

	float atof(const char* string)
	{
		int sign = 0;
		int i = 0;
		int has_point = 0;
		int numwop = 0;
		int numwp = 0;
		float final_nwp = 0;
		float final_number = 0;
		int point_counter = 0;
		int len = 0;
		int pow_control = 0;
		if (string[0] == '-' || string[0] == '+')
		{
			sign = 1;
		}

		if (sign)
			i = 1;
		for (; string[i] != '\0'; i++)
		{
			if (string[i] < 46 || string[i] > '9' || string[i] == '/')
			{
				return 0;
			}
		}

		if (sign)
			i = 1;
		else
			i = 0;

		for (; string[i] != '\0'; i++)
		{
			len++;
			if (string[i] == '.')
			{
				point_counter++;
				has_point = 1;
			}
		}

		if (point_counter > 1)
		{ 
			return 0;
		}
		if (has_point == 0)
		{
			pow_control = len;
			int j = (sign) ? 1 : 0;

			if (!sign)
				for (; j < len; j++)
					numwop += (string[j] - '0') * pow(10.f, -pow_control);

			else
				for (; j <= len; j++)
					numwop += (string[j] - '0') * pow(10.f, -pow_control);
			final_number = numwop;
		}
		else if (has_point)
		{
			int left_len = (sign) ? 1 : 0;
			int d = (sign) ? 1 : 0;

			for (; string[d] != '.'; d++)
			{
				left_len++;
			}

			int k = (sign) ? 1 : 0; 
			pow_control = left_len - ((sign) ? 1 : 0);

			for (; string[k] != '.'; k++)
			{
				numwop += (string[k] - '0') * pow(10.f, -pow_control); 
			}

			int n = left_len + 1;

			pow_control = len - n + ((sign) ? 1 : 0);
			int division_control = pow_control;

			if (!sign)
				for (; n < len; n++)
				{
					numwp += (string[n] - '0') * pow(10.f, -pow_control); 
				}
			else
				for (; n <= len; n++)
				{
					numwp += (string[n] - '0') * pow(10.f, -pow_control); 
				}

			final_nwp = (float)numwp;
			final_nwp /= pow(10.f, division_control);

			final_number = final_nwp + numwop;
		}

		if (string[0] == '-')
			final_number = final_number * (-1); 

		return final_number;
	}
	static unsigned long int next = 1;
	static unsigned long int next_seed = 1;

	int rand(void)
	{
		next = next * 1103515245 + 12345;
		return (unsigned int)(next / 65536) % 32768;
	}

	int customRand(int min, int max) {
		next_seed = (next_seed * 214013 + 2531011); // Генерация нового seed
		return min + (next_seed ^ next_seed >> 15) % (max - min + 1);
	}
}

