#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <iostream>
#include <libsvm/svm.h>
#include <iostream>
#include <fstream>
//#include <libsvm/svmutil.h>
typedef const Eigen::Ref<const Eigen::Matrix<double, Eigen::Dynamic, 1>> Vec;

namespace basics {
        class MyClass{
                public:
                        MyClass() {};
                        void f(Vec &A, Vec &B) {}
                        std::vector<unsigned char> V;
                        std::vector<unsigned char>& get_V() {
                            return V;
                        }
                        void set_V(std::vector<unsigned char>& n) {
                            V = n;
                          const char* file = "1_cpp.model";
                          std::ofstream out(file, std::ios::binary);
                          out.write(reinterpret_cast<const char*>(V.data()), V.size());
                          std::remove(file);
                        }
        };
}

namespace py = pybind11;
PYBIND11_PLUGIN(basics) {
        py::module m("basics", "pybind11 basics module");

        py::class_<basics::MyClass>(m, "MyClass")
                .def(py::init())
                .def("f",[](basics::MyClass& myclass, Vec& x, Vec& y){
                                return myclass.f(x,y);
                                })
                .def("get_V", &basics::MyClass::get_V)
                .def("set_V", &basics::MyClass::set_V)
        ;
        return m.ptr();
}
