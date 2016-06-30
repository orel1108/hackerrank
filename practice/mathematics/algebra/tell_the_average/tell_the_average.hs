module Main where

m :: Integer
m = 10 ^ 9 + 7

main :: IO ()
main = do
    n <- readLn :: IO Int
    a' <- getContents
    let a = map (read :: String -> Integer) $ words a'
        b = map (+1) a
        r = foldr (\x acc -> x * acc `mod` m) 1 b
    print $ r - 1

