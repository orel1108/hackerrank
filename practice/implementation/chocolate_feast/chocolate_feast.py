#!/bin/python


t = int(raw_input().strip())
for _ in range(t):
    money, price, exch = map(int, raw_input().strip().split(' '))
    amount = money // price
    total = amount
    while amount >= exch:
        total += 1
        amount -= exch;
        amount += 1
    print total
    

