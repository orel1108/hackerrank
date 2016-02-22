#!/usr/bin/env python

from __future__ import division
import math

class Vector:
    def __init__(self, i_head, i_tail):
        self.__Coord = [i_head[POS] - i_tail[POS] for POS in range(3)]
    
    def dot_product(self, i_other):
        return sum([self.__Coord[POS] * i_other.coords[POS] for POS in range(3)])
    
    def cross_product(self, i_other):
        res = [
            self.__Coord[1] * i_other.coords[2] - self.__Coord[2] * i_other.coords[1],
            self.__Coord[2] * i_other.coords[0] - self.__Coord[0] * i_other.coords[2],
            self.__Coord[0] * i_other.coords[1] - self.__Coord[1] * i_other.coords[0]]
        return Vector(res, [0.0, 0.0, 0.0])
    
    def norm(self):
        return math.sqrt(self.dot_product(self))
    
    @property
    def coords(self):
        return self.__Coord
    
A = map(float, raw_input().split())
B = map(float, raw_input().split())
C = map(float, raw_input().split())
D = map(float, raw_input().split())

AB = Vector(A, B)
BC = Vector(B, C)
CD = Vector(C, D)

X = AB.cross_product(BC)
Y = BC.cross_product(CD)

cos_phi = X.dot_product(Y) / (X.norm() * Y.norm())
print '%.2f' % round(math.degrees(math.acos(cos_phi)), 2)

