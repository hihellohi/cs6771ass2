#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "EuclideanVector.h"

namespace evec{
	EuclideanVector::EuclideanVector() : EuclideanVector(0) { }

	EuclideanVector::EuclideanVector(unsigned int dim) : vector_{new double[dim]()}, dimension_{dim}, norm_{std::numeric_limits<double>::quiet_NaN()} { }

	EuclideanVector::EuclideanVector(unsigned int dim, double mag) : EuclideanVector(dim) {
		std::fill_n(vector_, dim, mag);
	}

	EuclideanVector::EuclideanVector(const std::vector<double>::iterator& first, const std::vector<double>::iterator& last) : EuclideanVector(last - first) {
		std::copy(first, last, vector_);
	}

	EuclideanVector::EuclideanVector(const std::list<double>::iterator& first, const std::list<double>::iterator& last) : norm_{std::numeric_limits<double>::quiet_NaN()} {
		unsigned dim = 0;
		for(auto it = first; it != last; it++){
			dim++;
		}

		vector_ = new double[dim]();
		dimension_ = dim;
		std::copy(first, last, vector_);
	}

	EuclideanVector::EuclideanVector(const std::initializer_list<double>& list) : EuclideanVector(list.size()) {
		std::copy(list.begin(), list.end(), vector_);
	}

	EuclideanVector::EuclideanVector(const EuclideanVector& other) : EuclideanVector(other.dimension_) {
		std::copy(other.vector_, other.vector_ + other.dimension_, vector_);
	}

	EuclideanVector::EuclideanVector(EuclideanVector&& other) : vector_{other.vector_}, dimension_{other.dimension_}, norm_{std::numeric_limits<double>::quiet_NaN()} {
		other.vector_ = nullptr;
		other.dimension_ = 0;
	}

	EuclideanVector::~EuclideanVector() noexcept {
		if(vector_ != nullptr){
			delete vector_;
			vector_ = nullptr;
		}
		dimension_ = 0;
	}


	EuclideanVector& EuclideanVector::operator=(const EuclideanVector& other) {
		if(this != &other) {
			if(other.vector_ == nullptr){
				this->~EuclideanVector();
			}
			else{
				if(vector_ == nullptr || dimension_ != other.dimension_){
					this->~EuclideanVector();
					vector_ = new double[other.dimension_];
					dimension_ = other.dimension_;
				}

				std::copy(other.vector_, other.vector_ + dimension_, vector_);
			}
		}

		return *this;
	}

	EuclideanVector& EuclideanVector::operator=(EuclideanVector&& other) {
		if(this != &other) {
			this->~EuclideanVector();
			dimension_ = other.dimension_;
			vector_ = other.vector_;

			other.vector_ = nullptr;
			other.dimension_ = 0;
		}
		return *this;
	}

	double squares(double x, double y) { return x + y * y; }

	double EuclideanVector::getEuclideanNorm() {
		if(std::isnan(norm_)){
			norm_ = sqrt(std::accumulate(vector_, vector_ + dimension_, 0, squares));
		}
		return norm_;
	}

	EuclideanVector EuclideanVector::createUnitVector() const {
		return (0);
	}

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
