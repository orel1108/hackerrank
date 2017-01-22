module Main where

import Control.Monad (forM_)
import qualified Data.Set as S

solutions :: Integer -> Integer -> S.Set (Integer, Integer)
solutions x d = S.fromList $ map (roots x d) [(-1, -1), (-1, 1), (1, -1), (1, 1)]
    where
        roots :: Integer -> Integer -> (Integer, Integer) -> (Integer, Integer)
        roots x d (c0, c1) = (b - c0 * d, b)
            where
                b = (c0 * d + c1 * x) `div` 2

solve :: Integer -> Integer -> Int
solve d p
    | disc < 0 = 0
    | (x * x) /= disc = 0
    | otherwise = S.size $ solutions x d
    where
        disc = d * d + 4 * p
        x    = round . sqrt . fromIntegral $ disc

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        dp <- getLine
        let [d, p] = map (read :: String -> Integer) $ words dp
        if d < 0
            then print 0
            else print $ solve d p

