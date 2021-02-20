import ctypes
so = ctypes.cdll.LoadLibrary
lib = so("./libpycallclass.so")
print(lib)
print('display()')
lib.display()
print('display1()')
lib.display1(100)