lcmArr [a] = a
lcmArr (a:arr) = lcm a $ lcmArr arr

main = do
    n <- readLn :: IO Int
    sa <- getLine
    let a = map (read :: String -> Int) $ words sa
    print $ lcmArr a

