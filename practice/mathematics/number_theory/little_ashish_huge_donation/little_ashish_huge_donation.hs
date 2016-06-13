module Main where

import qualified Data.Map as Map
import Control.Monad (forM_)
import Data.Maybe

mx :: Integer
mx = 10000000000000001

gen_seq :: Integer -> [(Integer, Integer)] -> [(Integer, Integer)]
gen_seq n s
    | m >= mx   = s
    | otherwise = gen_seq (n + 1) (v : s)
    where
        m = n * (n + 1) * (2 * n + 1) `div` 6
        v = (fst (head s) + n * n, n)

main :: IO ()
main = do
    t <- readLn :: IO Int
    let m = Map.fromList $ gen_seq 1 [(0, 0)]
    forM_ [1..t] $ \_ -> do
        x <- readLn :: IO Integer
        print $ (snd $ fromJust $ Map.lookupGT x m) - 1

