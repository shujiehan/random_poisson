/*
 * Copyright 2024 Northwestern Polytechnical University
 * @author Shujie Han
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,

 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
        .def("poisson", &RandomPoisson::poisson)
        .def(py::pickle(
            [](RandomPoisson &p) { // __get_state__
                return py::make_tuple(p.getSeed(), p.getNextGaussian());
            },
            [](py::tuple t) { // __set_state__
                if (t.size() != 2) {
                    throw std::runtime_error("Invalid state in random poisson.");
                }
                RandomPoisson p;
                // Directly restore the internal state
                p.setSeed(t[0].cast<long long>()); 
                p.setNextGaussian(t[1].cast<double>());
                return p;
            }
        ));
}
