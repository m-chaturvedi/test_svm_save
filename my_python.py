import numpy as np
from basics import *
import pdb
import svm
import svmutil
import filecmp

def create_and_save_model():
    y, x = [1,-1], [{0:1, 1:2, 2:-2}, {0:2, 1:-2, 2:2}]
    prob  = svm.svm_problem(y, x, isKernel=True)
    param = svm.svm_parameter('-t 4 -c 4 -b 1')
    m = svmutil.svm_train(prob, param)
    svmutil.svm_save_model('1.model', m)

def read_from_model():
    with open('1.model', "r") as model_file:
        f = model_file.read()
        b = bytearray(f)
        return b

def write_from_byte_array(b):
    with open('2.model', "wb") as file:
        file.write(b)

def set_vector():
    b = read_from_model()
    my_class.set_V(b)

if(__name__ == "__main__"):
    my_class = MyClass();
    create_and_save_model()
    read_from_model()
    set_vector()
    assert(filecmp.cmp("1.model", "1_cpp.model") == True)

    # a = np.ones((7,1))
    #b = np.ones((7,1))
    #x.f(a, b)
