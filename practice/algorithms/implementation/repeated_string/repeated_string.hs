module Main where

count :: Char -> String -> Integer
count a = foldr (\x acc -> if x == a then acc + 1 else acc) 0

main :: IO ()
main = do
    s <- getLine
    n <- readLn :: IO Int
    let (q, r) = divMod n (length s)
    print $ (toInteger q) * (count 'a' s) + (count 'a' (take r s))

