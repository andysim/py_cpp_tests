#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include "helloworld.h"


const char* greeting()
{
    return "Hello world?";
}



BOOST_PYTHON_MODULE(helloworld)
{
    using namespace boost::python;

    // Wrap the function defined above
    def("greeting", greeting);
    
    // Wrap the HelloWorld class
    boost::python::class_<HelloWorld>("HelloWorld")
          .def("greet", &HelloWorld::greet);

}
