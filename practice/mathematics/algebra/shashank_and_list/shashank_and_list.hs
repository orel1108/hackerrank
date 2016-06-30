module Main where

m :: Integer
m = 10 ^ 9 + 7

pow_mod :: Integer -> Integer
pow_mod v = pow_mod' v 2 1
    where
        pow_mod' v a r
            | v == 0         = r
            | v `mod` 2 == 1 = pow_mod' (v `div` 2) (a * a `mod` m) (r * a `mod` m)
            | otherwise      = pow_mod' (v `div` 2) (a * a `mod` m) r

solve :: [Integer] -> Integer
solve a = foldr (\d acc -> acc * (1 + d) `mod` m) 1 $ map pow_mod a

main :: IO ()
main = do
    n  <- readLn :: IO Int
    a' <- getContents
    let a = map (read :: String -> Integer) $ words a'
    print $ solve a - 1

