module Main where

import Control.Monad (forM_)
import qualified Data.Vector as V

triangle :: V.Vector (V.Vector Int) -> Int -> V.Vector (V.Vector Int)
triangle tr 0 = tr
triangle tr n = triangle (V.snoc tr r) (n - 1)
    where
        h  = V.last tr
        r' = V.fromList [((h V.! k) + (h V.! (k + 1))) `mod` 1000000000 | k <- [0..(V.length h - 2)]]
        r  = V.snoc (V.cons 1 r') 1

main :: IO ()
main = do
    t <- readLn :: IO Int
    let pascal = triangle (V.fromList [V.fromList [1, 1]]) 2000
    
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        k <- readLn :: IO Int
        print $ (pascal V.! (k + n - 2)) V.! (n - 1)
    
