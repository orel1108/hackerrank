module Main where

main :: IO ()
main = do
    nm <- getLine
    da <- getContents
    let [n, m] = map (read :: String -> Int) $ words nm
        d = map ((map (read :: String -> Int)) . words) $ lines da
        r = foldl (\acc [a, b, k] -> (b - a + 1) * k + acc) 0 d
    print $ r `div` n

