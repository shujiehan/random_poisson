#include <pybind11/pybind11.h>
#include "libc/random_poisson.hpp"
// to convert C++ STL containers to python list
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace std;

//PYBIND11_MODULE(random_poisson, m) {
//    py::class_<RandomPoisson>(m, "RandomPoisson")
//        .def(py::init<long long>())
//        .def("setName", &RandomPoisson::setName)
//        .def("getName", &RandomPoisson::getName);
//}

PYBIND11_MODULE(random_poisson, m) {
    m.doc() = "random poisson by pybind11"; // optional module docstring
    py::class_<RandomPoisson>(m, "RandomPoisson")
        //.def(py::init<>())
        .def(py::init<int>())
        .def("setSeed", &RandomPoisson::setSeed)
        .def("getSeed", &RandomPoisson::getSeed)
        //.def_property("seed", &RandomPoisson::setSeed, &RandomPoisson::getSeed);
        .def("next", &RandomPoisson::next)
        .def("nextBytes", &RandomPoisson::nextBytes)
        .def("nextInt", &RandomPoisson::nextInt)
        .def("nextLong", &RandomPoisson::nextLong)
        .def("nextBoolean", &RandomPoisson::nextBoolean)
        .def("nextFloat", &RandomPoisson::nextFloat)
        .def("nextDouble", &RandomPoisson::nextDouble)
        .def("nextGaussian", &RandomPoisson::nextGaussian)
        .def("multiplePoisson", &RandomPoisson::multiplePoisson)
        .def("poisson", &RandomPoisson::poisson);
}
