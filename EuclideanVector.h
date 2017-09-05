#ifndef EVEC_H
#define EVEC_H

#include <vector>
#include <list>
#include <initializer_list>

namespace evec{
	class EuclideanVector{
		private:
			double *vector_;
			unsigned int dimension_;
			mutable double norm_;

		public:
			EuclideanVector();
			EuclideanVector(unsigned int);
			EuclideanVector(unsigned int, double);
			EuclideanVector(const std::initializer_list<double>&); 
			EuclideanVector(const EuclideanVector&); 
			EuclideanVector(EuclideanVector&&); 
			template<class It> 
				inline EuclideanVector(It start, It end) : EuclideanVector(std::distance(start, end)) {
					std::copy(start, end, vector_);
				}

			~EuclideanVector() noexcept;

			EuclideanVector& operator=(const EuclideanVector&);
			EuclideanVector& operator=(EuclideanVector&&);

			inline unsigned int getNumDimensions() const { return dimension_; }
			double get(unsigned int at) const;
			double getEuclideanNorm() const;
			EuclideanVector createUnitVector() const;
			double operator[](unsigned int) const;
			double& operator[](unsigned int);
			EuclideanVector& operator+=(const EuclideanVector&);
			EuclideanVector& operator-=(const EuclideanVector&);
			EuclideanVector& operator/=(double);
			EuclideanVector& operator*=(double);
			operator std::vector<double>() const;
			operator std::list<double>() const;
			
			friend bool operator==(const EuclideanVector&, const EuclideanVector&);
	};

	bool operator==(const EuclideanVector&, const EuclideanVector&);
	bool operator!=(const EuclideanVector&, const EuclideanVector&);
	EuclideanVector operator+(const EuclideanVector&, const EuclideanVector&);
	EuclideanVector operator-(const EuclideanVector&, const EuclideanVector&);
	double operator*(const EuclideanVector&, const EuclideanVector&);
	EuclideanVector operator*(double, const EuclideanVector&);
	EuclideanVector operator*(const EuclideanVector&, double);
	EuclideanVector operator/(const EuclideanVector&, double);
	std::ostream& operator<<(std::ostream&, const EuclideanVector&);
} //evec

#endif
