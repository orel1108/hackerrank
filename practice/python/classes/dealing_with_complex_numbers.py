#!/usr/bin/env python

from __future__ import division
import math

class Complex:
    def __init__(self, i_re, i_im):
        self.__Re = float(i_re)
        self.__Im = float(i_im)
        
    def __add__(self, i_other):
        res_re = self.__Re + i_other.re
        res_im = self.__Im + i_other.im
        return Complex(res_re, res_im)
    
    def __sub__(self, i_other):
        res_re = self.__Re - i_other.re
        res_im = self.__Im - i_other.im
        return Complex(res_re, res_im)
    
    def __mul__(self, i_other):
        res_re = self.__Re * i_other.re - self.__Im * i_other.im
        res_im = self.__Re * i_other.im + self.__Im * i_other.re
        return Complex(res_re, res_im)
    
    def __truediv__(self, i_other):
        norm = math.pow(i_other.re, 2.0) + math.pow(i_other.im, 2.0)
        res_re = self.__Re * i_other.re + self.__Im * i_other.im
        res_re /= norm
        res_im = self.__Im * i_other.re - self.__Re * i_other.im
        res_im /= norm
        return Complex(res_re, res_im)
    
    @property
    def re(self):
        return self.__Re
    
    @property
    def im(self):
        return self.__Im
    
    def __str__(self):
        s = ''
        res_re = round(self.__Re, 2)
        res_im = round(self.__Im, 2)
        if res_im == 0.0:
            s = '%.2f' % res_re
        elif res_re != 0.0:
            s = '%.2f' % res_re
            if res_im < 0:
                s += ' - %.2fi' % abs(res_im)
            elif res_im > 0:
                s += ' + %.2fi' % res_im
        else:
            s = '%.2fi' % res_im
        return s

def mod(i_complex):
    return '%.2f' % round(math.sqrt(math.pow(i_complex.re, 2.0) + math.pow(i_complex.im, 2.0)), 2)
    
a, b = map(float, raw_input().split())
z1 = Complex(a, b)
x, y = map(float, raw_input().split())
z2 = Complex(x, y)

print z1 + z2
print z1 - z2
print z1 * z2
print z1 / z2
print mod(z1)
print mod(z2)

