len :: [a] -> Int
len [] = 0
len lst = 1 + len (tail lst)

