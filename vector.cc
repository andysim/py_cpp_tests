#include "vector.h"
#include <stdio.h>
#include <exception>
#include <boost/python.hpp>
#include <boost/python/list.hpp>

BOOST_PYTHON_MODULE(vector)
{
    using namespace boost::python;
    // Wrap the Vector class for python
    boost::python::class_<Vector>("Vector")
          .def(init<const char*, const boost::python::list&>())
          .def("print_out", &Vector::print)
          .def("dot_product", &Vector::dot_product);

}


Vector::Vector() :
    vec_(0),
    name_(""),
    length_(0)
{}

Vector::Vector(const char* name, const boost::python::list& values) :
    vec_(0),
    name_(name)
{
    length_ = len(values);
    if(length_){
        vec_ = new double[length_];
        for(int n = 0; n < length_; ++n){
            boost::python::extract<double> fval(values[n]);
            if(fval.check()){
                vec_[n] = boost::python::extract<double>(values[n]);                
            }else{
                throw "Not all elements passed in are floating point numbers!\n";
            }
        }
    }
}

Vector::~Vector()
{
    if(vec_)
        delete [] vec_;
}

void Vector::print() const
{
    for(int n = 0; n < length_; ++n){
        printf("%s[%d] = %20.12f\n", name_, n, vec_[n]);
    }
}
        
double Vector::dot_product(const Vector& rhs)
{
    if(rhs.length_ != length_)
        throw "dot_prodcuct can only be called with vectors of the same length";
    double value = 0.0;
    for(int n = 0; n < length_; ++n){
        value += vec_[n] * rhs.vec_[n];
    }
    return value;
}
