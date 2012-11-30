#ifndef VECTOR_H 
#define VECTOR_H 

// Forward Declaration
namespace boost{ namespace python{ class list; } }

class Vector{
    private:
        /// The array of values
        double *vec_;
        /// The length of the array
        int length_;
        /// The name of the array
        const char *name_;
    public:
        Vector(const char *name, const boost::python::list& values);
        Vector();
        ~Vector();
        /// Computes the dot product of this with another vector
        double dot_product(const Vector& rhs);
        /// Prints the values out
        void print() const;
};

#endif
