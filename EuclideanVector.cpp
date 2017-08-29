#include <algorithm>
#include "EuclideanVector.h"

namespace evec{
	EuclideanVector::EuclideanVector(unsigned int dim) {
		vector_ = new double[dim]();
		dimension_ = dim;
	}

	EuclideanVector::EuclideanVector(unsigned int dim, double mag) {
		vector_ = new double[dim];
		dimension_ = dim;
		std::fill_n(vector_, dim, mag);
	}

	EuclideanVector::EuclideanVector(const std::vector<double>::iterator& first, const std::vector<double>::iterator& last) {
		(void)first;
		(void)last;
	}

	EuclideanVector::EuclideanVector(const std::list<double>::iterator& first, const std::list<double>::iterator& last) {
		(void)first;
		(void)last;
	}

	EuclideanVector::EuclideanVector(const std::initializer_list<double>& list) {
		(void)list;
	}

	EuclideanVector::EuclideanVector(const EuclideanVector& other) {
		(void)other;
	}

	EuclideanVector::EuclideanVector(EuclideanVector&& other) {
		(void)other;
	}

	EuclideanVector::~EuclideanVector() noexcept {
		if(vector_ != nullptr){
			delete vector_;
			vector_ = nullptr;
		}
	}


	//EuclideanVector::EuclideanVector& operator=(const EuclideanVector& other) {
	//	(void)other;
	//	return *this;
	//}

	//EuclideanVector::EuclideanVector& operator=(EuclideanVector&& other) {
	//	(void)other;
	//	return *this;
	//}

	//EuclideanVector::unsigned int getNumDimensions() const {
	//	return 0;
	//}

	//EuclideanVector::double get(unsigned int at) const {
	//	(void)at;
	//	return 0.0;
	//}

	//EuclideanVector::double getEuclideanNorm() const {
	//	return 0.0;
	//}

	//EuclideanVector::EuclideanVector createUnitVector() const {
	//	return {0};
	//}

	//EuclideanVector::double operator[](unsigned int at) const {
	//	(void)at;
	//	return 0;
	//}

	//EuclideanVector::double& operator[](unsigned int at) {
	//	return a;
	//}

	//EuclideanVector::EuclideanVector& operator+=(const EuclideanVector& other) {
	//	(void)other;
	//}

	//EuclideanVector::EuclideanVector& operator-=(const EuclideanVector& other) {
	//	(void)other;
	//}

	//EuclideanVector::EuclideanVector& operator/=(double div) {
	//	(void)div;
	//}

	//EuclideanVector::EuclideanVector& operator*=(double mult) {
	//	(void)mult;
	//}

	//EuclideanVector::operator std::vector<double>() const {
	//	return {};
	//}

	//EuclideanVector::operator std::list<double>() const {
	//	return {};
	//}


	//bool operator==(const EuclideanVector& one, const EuclideanVector& two) {
	//	(void)one;
	//	(void)two;
	//	return false;
	//}

	//bool operator!=(const EuclideanVector& one, const EuclideanVector& two) {
	//	(void)one;
	//	(void)two;
	//	return true;
	//}

	//EuclideanVector operator+(const EuclideanVector& one, const EuclideanVector& two) {
	//	(void)one;
	//	(void)two;
	//	return {0};
	//}

	//EuclideanVector operator-(const EuclideanVector& one, const EuclideanVector& two) {
	//	(void)one;
	//	(void)two;
	//	return {0};
	//}

	//EuclideanVector operator*(const EuclideanVector& one, const EuclideanVector& two) {
	//	(void)one;
	//	(void)two;
	//	return {0};
	//}

	//EuclideanVector operator*(unsigned int mult, const EuclideanVector& vec) {
	//	(void)vec;
	//	(void)mult;
	//	return {0};
	//}

	//EuclideanVector operator*(const EuclideanVector& vec, unsigned int mult) {
	//	(void)vec;
	//	(void)mult;
	//	return {0};
	//}

	//EuclideanVector operator/(const EuclideanVector& vec, unsigned int div) {
	//	(void)vec;
	//	(void)div;
	//	return {0};
	//}

	std::ostream& operator<<(std::ostream& os, const EuclideanVector& vec) {
		os << '[';

		if(vec.vector_ != nullptr && vec.dimension_) {
			os << vec.vector_[0];
			for(unsigned int i = 1; i < vec.dimension_; i++){
				os << ' ' << vec.vector_[i];
			}
		}

		return os << ']';
	}

} //evec
