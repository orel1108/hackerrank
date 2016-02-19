import Control.Monad

findPos a = length $ dropWhile (> (last a)) (reverse $ init a)

insert a = take n a ++ [last a] ++ (init $ drop n a) where
    n = findPos a
    
insertSort a n = insertSort' a 1 n where
    insertSort' a k n
        | k < n  = do
            putStrLn $ unwords $ map show (insert (take (k + 1) a)++ (drop (k + 1) a))
            insertSort' (insert (take (k + 1) a) ++ (drop (k + 1) a)) (k + 1) n
        | k == n = return ()

main = do
    n <- readLn :: IO Int
    ar <- getLine
    let a = map (read :: String -> Int) $ words ar
    insertSort a n

