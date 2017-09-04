#include <limits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
#include "EuclideanVector.h"

namespace evec{
	EuclideanVector::EuclideanVector() : EuclideanVector(0) { }

	EuclideanVector::EuclideanVector(unsigned int dim) 
		: vector_{new double[dim]()}, dimension_{dim}, norm_{std::numeric_limits<double>::quiet_NaN()} { }

	EuclideanVector::EuclideanVector(unsigned int dim, double mag) : EuclideanVector(dim) {
		std::fill_n(vector_, dim, mag);
	}

	EuclideanVector::EuclideanVector(const std::initializer_list<double>& list) : EuclideanVector(list.begin(), list.end()) { }

	EuclideanVector::EuclideanVector(const EuclideanVector& other) : EuclideanVector(other.dimension_) {
		std::copy(other.vector_, other.vector_ + other.dimension_, vector_);
	}

	EuclideanVector::EuclideanVector(EuclideanVector&& other) 
		: vector_{other.vector_}, dimension_{other.dimension_}, norm_{std::numeric_limits<double>::quiet_NaN()} {

		other.vector_ = nullptr;
		other.dimension_ = 0;
		other.norm_ = std::numeric_limits<double>::quiet_NaN();
	}

	EuclideanVector::~EuclideanVector() noexcept {
		if(vector_ != nullptr){
			delete [] vector_;
			vector_ = nullptr;
		}
	}


	EuclideanVector& EuclideanVector::operator=(const EuclideanVector& other) {
		if(this != &other) {
			if(other.vector_ == nullptr){
				if(vector_ != nullptr){
					delete [] vector_;
					vector_ = nullptr;
				}
				dimension_ = 0;
				norm_ = std::numeric_limits<double>::quiet_NaN();
			}
			else{
				if(vector_ == nullptr || dimension_ != other.dimension_){
					if(vector_ != nullptr){
						delete [] vector_;
					}
					vector_ = new double[other.dimension_];
					dimension_ = other.dimension_;
				}

				norm_ = other.norm_;
				std::copy(other.vector_, other.vector_ + dimension_, vector_);
			}
		}
		return *this;
	}

	EuclideanVector& EuclideanVector::operator=(EuclideanVector&& other) {
		if(this != &other) {
			if(vector_ != nullptr){
				delete [] vector_;
			}
			dimension_ = other.dimension_;
			vector_ = other.vector_;
			norm_ = other.norm_;

			other.vector_ = nullptr;
			other.dimension_ = 0;
			other.norm_ = std::numeric_limits<double>::quiet_NaN();
		}
		return *this;
	}

	double EuclideanVector::get(unsigned int at) const {
		return (*this)[at];
	}

	double EuclideanVector::getEuclideanNorm() {
		if(std::isnan(norm_)) {
			if(dimension_) {
				norm_ = sqrt(std::accumulate(vector_, vector_ + dimension_, 0.0, 
							[](double x, double y) { return x + y * y; }));
			}
			else {
				norm_ = 0;
			}
		}
		return norm_;
	}

	EuclideanVector EuclideanVector::createUnitVector() {
		return *this / getEuclideanNorm();
	}

	double EuclideanVector::operator[](unsigned int at) const {
		return vector_[at];
	}

	double& EuclideanVector::operator[](unsigned int at) {
		return vector_[at];
	}

	EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& other) {
		std::transform(vector_, vector_ + dimension_, other.vector_, vector_, std::plus<double>());
		return *this;
	}

	EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& other) {
		std::transform(vector_, vector_ + dimension_, other.vector_, vector_, std::minus<double>());
		return *this;
	}

	EuclideanVector& EuclideanVector::operator/=(double div) {
		std::transform(vector_, vector_ + dimension_, vector_, [&](double in) {return in / div;});
		return *this;
	}

	EuclideanVector& EuclideanVector::operator*=(double mult) {
		std::transform(vector_, vector_ + dimension_, vector_, [&](double in) {return in * mult;});
		return *this;
	}

	EuclideanVector::operator std::vector<double>() const {
		return {vector_, vector_ + dimension_};
	}

	EuclideanVector::operator std::list<double>() const {
		return {vector_, vector_ + dimension_};
	}


	bool operator==(const EuclideanVector& one, const EuclideanVector& two) {
		return one.dimension_ == two.dimension_ && std::equal(one.vector_, one.vector_ + one.dimension_, two.vector_);
	}

	bool operator!=(const EuclideanVector& one, const EuclideanVector& two) {
		return !(one == two);
	}

	EuclideanVector operator+(const EuclideanVector& one, const EuclideanVector& two) {
		auto out = one;
		out += two;
		return std::move(out);
	}

	EuclideanVector operator-(const EuclideanVector& one, const EuclideanVector& two) {
		auto out = one;
		out -= two;
		return std::move(out);
	}

	double operator*(const EuclideanVector& one, const EuclideanVector& two) {
		double out = 0;
		for(unsigned int i = 0; i < one.getNumDimensions(); i++){
			out += one.get(i) * two.get(i);
		}
		return out;
	}

	EuclideanVector operator*(unsigned int mult, const EuclideanVector& vec) {
		return vec * mult;
	}

	EuclideanVector operator*(const EuclideanVector& vec, unsigned int mult) {
		auto out = vec;
		out /= mult;
		return std::move(out);
	}

	EuclideanVector operator/(const EuclideanVector& vec, double div) {
		auto out = vec;
		out /= div;
		return std::move(out);
	}

	std::ostream& operator<<(std::ostream& os, const EuclideanVector& vec) {
		os << '[';

		if(vec.getNumDimensions()) {
			os << vec.get(0);
			for(unsigned int i = 1; i < vec.getNumDimensions(); i++){
				os << ' ' << vec.get(i);
			}
		}

		return os << ']';
	}
} //evec
