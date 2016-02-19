insert a n = insert' a (n - 1) (last a) where
    insert' a pos v
        | pos > 0 && a !! (pos - 1) > v = do
            putStrLn $ unwords $ map show na
            insert' na (pos - 1) v
        | otherwise = putStrLn $ unwords $ map show ((take pos a) ++ [v] ++ (drop (pos + 1) a)) where
            na = (take pos a) ++ [a !! (pos - 1)] ++ (drop (pos + 1) a)

main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    insert a n

