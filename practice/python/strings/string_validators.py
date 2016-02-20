#!/usr/bin/env python

s = raw_input().strip()

def has_alnum(i_s):
    for c in i_s:
        if c.isalnum():
            return True
    return False

def has_alpha(i_s):
    for c in i_s:
        if c.isalpha():
            return True
    return False

def has_digit(i_s):
    for c in i_s:
        if c.isdigit():
            return True
    return False

def has_lower(i_s):
    for c in i_s:
        if c.islower():
            return True
    return False

def has_upper(i_s):
    for c in i_s:
        if c.isupper():
            return True
    return False

print has_alnum(s)
print has_alpha(s)
print has_digit(s)
print has_lower(s)
print has_upper(s)

