#ifndef CampoElectrico_H
#define CampoElectrico_H

namespace CampoElectrico{
	class Carga{
		public:
			float x;
			float y;
			double q;

			Carga();
			Carga(float x, float y, double q);
			void set(float x, float y, double q);

	};

	double getE(float x, float y, Carga carga[], int size);
	float distancia(float x1, float y1, float x2, float y2);

}
#endif
