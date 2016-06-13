module Main where

normalize :: [Integer] -> Integer -> Integer
normalize [] d = d
normalize (v:a) d
    | d == 1    = 1
    | otherwise = normalize a (gcd v d)

solve' :: Integer -> [Integer] -> [Integer]
solve' x k = map (+x) k

solve'' :: Integer -> [Integer] -> [Integer]
solve'' d k = foldr (\v acc -> gcd d v : acc) [] k

main :: IO ()
main = do
    nq <- getLine
    a' <- getLine
    k' <- getContents
    let [n, q] = map (read :: String -> Integer) $ words nq
        a      = map (read :: String -> Integer) $ words a'
        k      = map (read :: String -> Integer) $ lines k'
        d      = normalize a (a !! 0)
    if minimum a == maximum a
        then putStr $ unlines $ map show $ solve' (a !! 0) k
        else putStr $ unlines $ map show $ solve'' d k

