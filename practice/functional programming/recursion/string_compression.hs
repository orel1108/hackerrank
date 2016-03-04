aux :: Int -> [Char]
aux n = if n == 1 then [] else show n

compress :: Char -> Int -> String -> String
compress _ 0 (x:xs) = compress x 1 xs
compress c n [] = [c] ++ aux n
compress c n (x:xs) = if x == c 
                        then compress c (n + 1) xs
                        else [c] ++ aux n ++ compress x 1 xs

main = do
    s <- getLine
    putStrLn $ compress '0' 0 s

