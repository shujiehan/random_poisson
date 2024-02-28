#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(random_poisson, m) {
    m.doc() = "random poisson by pybind11"; // optional module docstring
    py::class_<Random>(m, "Random")
        .def(py::init<>())
        .def(py::init<long long>())
        .def_property("seed", &Random::setSeed, &Random::getSeed)
        .def("next", &Random::next)
        .def("nextBytes", &Random::nextBytes)
        .def("nextInt", &Random::nextInt)
        .def("nextBytes", &Random::nextBytes);
}
