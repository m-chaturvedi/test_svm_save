g++ -w -g -O0 -std=c++11 -fPIC \
-shared -o basics.so -Wno-deprecated-declarations \
-fno-inline-small-functions \
-Wno-strict-prototypes \
-I/home/chaturvedi/workspace/eigen \
-I/home/chaturvedi/workspace/pybind11/include \
-I/usr/include/python2.7_d \
`python2.7-dbg-config --cflags --ldflags` \
test_vec.cpp \
&& python2.7-dbg my_python.py
