#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division
import math

degree_sign= u"\N{DEGREE SIGN}"

AB = float(raw_input().strip())
BC = float(raw_input().strip())
print str(int(round(math.degrees(math.atan(AB / BC))))) + degree_sign.encode("utf-8")

