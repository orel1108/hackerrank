module Main where

solve :: Integer -> Integer
solve t = solve' t 3 3 - t + 1
    where
        solve' t add_t next_t
            | next_t < t = solve' t new_add_t new_next_t
            | otherwise  = next_t
            where
                new_add_t  = 2 * add_t
                new_next_t = next_t + new_add_t

main :: IO ()
main = do
    t <- readLn :: IO Integer
    print $ solve t

