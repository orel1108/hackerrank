module Main where

import qualified Data.Vector as V

solve :: V.Vector Int -> Int -> Int -> Int
solve c n pos
    | pos >= n - 1 = 0
    | otherwise    = solve c n next_pos + 1
    where
        next_pos = if pos < n - 2 && (c V.! (pos + 2) == 0) then pos + 2 else pos + 1

main :: IO ()
main = do
    n  <- readLn :: IO Int
    c' <- getLine
    let c = map (read :: String -> Int) $ words c'
    print $ solve (V.fromList c) n 0

