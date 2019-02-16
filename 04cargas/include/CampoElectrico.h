#ifndef CampoElectrico_H
#define CampoElectrico_H

namespace CampoElectrico{
	const double K = 8.99e9;

	struct Vector2d{
		double x;
		double y;
	};

	class Carga{
		public:
			float x;
			float y;
			double q;

			Carga();
			Carga(float x, float y, double q);
			void set(float x, float y, double q);

	};

	Vector2d getE(float x0, float y0, float qx, float qy, double carga);
	float distancia(float x1, float y1, float x2, float y2);

}
#endif
