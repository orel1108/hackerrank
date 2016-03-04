solve [] [] = []
solve (x:p) (y:q) = x:y:[] ++ (solve p q)
    

main = do
    p <- getLine
    q <- getLine
    putStrLn $ solve p q

