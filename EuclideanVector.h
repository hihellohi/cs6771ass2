#ifndef EVEC_H
#define EVEC_H

#include <vector>
#include <list>
#include <initializer_list>

namespace evec{
	class EuclideanVector{
		private:
			
		public:
			EuclideanVector(unsigned int);
			EuclideanVector(unsigned int, double);
			EuclideanVector(const std::vector<double>::iterator&, const std::vector<double>::iterator&);
			EuclideanVector(const std::list<double>::iterator&, const std::list<double>::iterator&);
			EuclideanVector(const std::initializer_list<double>&); 
			EuclideanVector(const EuclidianVector&); 
			EuclideanVector(const EuclidianVector&&); 
			~EuclidianVector();

			void operator=(const EuclidianVector&);
			void operator=(const EuclidianVector&&);
			unsigned int getNumDimensions() const;
			double get(unsigned int) const;
			double getEuclideanNorm() const;

	};
} //evec

#endif
