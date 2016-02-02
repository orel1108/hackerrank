duplicate :: String -> Int -> String
duplicate string n = concat $ replicate n string

staircase :: Int -> [String]
staircase n = [duplicate " " (n - k) ++ (duplicate "#" k) | k <- [1..n]]

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    putStr $ unlines $ staircase n

