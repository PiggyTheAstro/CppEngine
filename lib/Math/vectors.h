#pragma once
#include <cmath>
namespace Vectors
{
	class Vector2 
	{
	public:
		float x;
		float y;
		Vector2();
		Vector2(float x, float y);

		Vector2 operator + (float val);
		void operator += (float val);
		Vector2 operator + (Vector2 vec);
		void operator += (Vector2 vec);

		Vector2 operator - (float val);
		void operator -= (float val);
		Vector2 operator - (Vector2 vec);
		void operator -= (Vector2 vec);

		Vector2 operator * (float val);
		void operator *= (float val);
		Vector2 operator * (Vector2 vec);
		void operator *= (Vector2 vec);

		Vector2 operator / (float val);
		void operator /= (float val);
		Vector2 operator / (Vector2 vec);
		void operator /= (Vector2 vec);

		float Distance(Vector2 secondVec);
		float Magnitude();
		void Normalize();
		float Dot(Vector2 secondVec);
		Vector2 Reflect(Vector2 secondVec);
		void Rotate(float eulerAngle);
	};
}