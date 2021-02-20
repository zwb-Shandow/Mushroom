#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Date: 2020/12/2 
import ctypes

so = ctypes.cdll.LoadLibrary
lib = so("./transfer.so")
print(lib)
# dist = 1.4
# p0 = (117.7891748, 38.97784858)
# p1 = (117.7891996, 38.9778322)
# x, y = lib.transfer_to_utm(dist, p0[0], p0[1], p1[0], p1[1])
# print(f"{x}--{y}")