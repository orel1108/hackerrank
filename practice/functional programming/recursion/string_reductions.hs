f :: [Char] -> [Char]
f [] = []
f (x:xs) = if x `elem` xs then f xs else x : f xs

main = do
    s <- getLine
    putStr $ reverse $ f $ reverse s

