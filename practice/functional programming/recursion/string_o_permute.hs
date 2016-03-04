change [] = []
change (x:y:l) = y:x:[] ++ (change l)

solve 0 = return ()
solve t = do
    s <- getLine
    putStrLn $ change s
    solve (t - 1)

main = do
    t <- getLine
    solve . (read :: String -> Int) $ t

