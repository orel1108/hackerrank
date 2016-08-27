module Main where

solve :: [Int] -> Int -> Int -> Int -> Int
solve cloud energy steps k = solve' cloud energy steps k 1
    where
        solve' cloud energy steps k pos
            | pos < steps = solve' cloud (energy - 2 * d) steps k (pos + 1)
            | otherwise   = energy
            where
                d = cloud !! (pos * k)

main :: IO ()
main = do
    params <- getLine
    cloud' <- getLine
    let [n, k] = map (read :: String -> Int) $ words params
        cloud  = map (read :: String -> Int) $ words cloud'
        steps  = n `div` k
        init_e = if cloud !! 0 == 1 then 2 else 0
        energy = 100 - steps - init_e
    print $ solve cloud energy steps k

