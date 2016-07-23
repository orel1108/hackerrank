module Main where

score :: Int -> Int -> (Int, Int)
score ai bi
    | ai > bi   = (1, 0)
    | ai < bi   = (0, 1)
    | otherwise = (0, 0)

main :: IO ()
main = do
    a' <- getLine
    b' <- getLine
    let a = map (read :: String -> Int) $ words a'
        b = map (read :: String -> Int) $ words b'
        c = zipWith score a b
        r = foldr (\pair acc -> (fst pair + (fst acc), snd pair + (snd acc))) (0, 0) c
    putStrLn $ show (fst r) ++ " " ++ (show (snd r))

