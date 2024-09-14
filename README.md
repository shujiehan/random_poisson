### Random Poisson Library

This library is used for [ScaleDFP](https://github.com/shujiehan/ScaleDFP) to accelerate the generation of Poisson sampling weights in disk failure prediction. To make the results consistent with those in [StreamDFP](https://github.com/shujiehan/StreamDFP), we re-implement the generation of random numbers in C to be aligned with that in Java. Also, we optimize this process with `pybind11`.

#### Preprequisite

- Install pybind11: `pip install pybind11`
- Modify `CMakeLists.txt` to adapt to your pybind11 path
  - `set(pybind11_DIR [YOUR_PYBIND11_PATH])`

#### Usage

- Go to this repo directory `random_possion/`.

- Run `python setup.py install` or `pip install .` to install random_poisson.

- You can use this library as other popular python libraries by `import random_poisson`.
