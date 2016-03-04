findPrefix [] _ = []
findPrefix _ [] = []
findPrefix (x:xs) (y:ys) = if x == y then x : findPrefix xs ys else []

main = do
    p <- getLine
    q <- getLine
    let pref = findPrefix p q
        n = length pref
    putStrLn $ show n ++ " " ++ pref
    let sp = drop n p
        np = length sp
    putStrLn $ show np ++ " " ++ sp
    let sq = drop n q
        nq = length sq
    putStrLn $ show nq ++ " " ++ sq

