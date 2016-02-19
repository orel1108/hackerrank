main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
        p = a !! 0
        smaller = filter  (<p) a
        equal   = filter (==p) a
        greater = filter  (>p) a
        total = smaller ++ equal ++ greater
    putStrLn $ unwords $ map show total

