#ifndef EVEC_H
#define EVEC_H

#include <vector>
#include <list>
#include <initializer_list>
#include <iostream>

namespace evec{
	class EuclideanVector{
		private:
			double *vector_;
			unsigned int dimension_;
			double norm_;

		public:
			EuclideanVector();
			EuclideanVector(unsigned int);
			EuclideanVector(unsigned int, double);
			EuclideanVector(const std::vector<double>::iterator&, const std::vector<double>::iterator&);
			EuclideanVector(const std::list<double>::iterator&, const std::list<double>::iterator&);
			EuclideanVector(const std::initializer_list<double>&); 
			EuclideanVector(const EuclideanVector&); 
			EuclideanVector(EuclideanVector&&); 
			~EuclideanVector() noexcept;

			EuclideanVector& operator=(const EuclideanVector&);
			EuclideanVector& operator=(EuclideanVector&&);

			inline unsigned int getNumDimensions() const {
				return dimension_;
			}

			inline double get(unsigned int at) const {
				return vector_[at];
			}

			double getEuclideanNorm();
			EuclideanVector createUnitVector() const;
			//double operator[](unsigned int) const;
			//double& operator[](unsigned int);
			//EuclideanVector& operator+=(const EuclideanVector&);
			//EuclideanVector& operator-=(const EuclideanVector&);
			//EuclideanVector& operator/=(double);
			//EuclideanVector& operator*=(double);
			//operator std::vector<double>() const;
			//operator std::list<double>() const;
			//
			friend std::ostream& operator<<(std::ostream&, const EuclideanVector&);
	};

	//bool operator==(const EuclideanVector&, const EuclideanVector&);
	//bool operator!=(const EuclideanVector&, const EuclideanVector&);
	//EuclideanVector operator+(const EuclideanVector&, const EuclideanVector&);
	//EuclideanVector operator-(const EuclideanVector&, const EuclideanVector&);
	//EuclideanVector operator*(const EuclideanVector&, const EuclideanVector&);
	//EuclideanVector operator*(unsigned int, const EuclideanVector&);
	//EuclideanVector operator*(const EuclideanVector&, unsigned int);
	//EuclideanVector operator/(const EuclideanVector&, unsigned int);
	std::ostream& operator<<(std::ostream&, const EuclideanVector&);
} //evec

#endif
