def is_leap(year):
    leap = False
    if year % 400 == 0:
        leap = True
    elif year % 4 == 0:
        if year % 100 == 0:
            leap = False
        else:
            leap = True
    return leap

