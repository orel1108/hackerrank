rev l = rev' l [] where
    rev' (x:xs) a = rev' xs (x:a)
    rev' [] a = a

