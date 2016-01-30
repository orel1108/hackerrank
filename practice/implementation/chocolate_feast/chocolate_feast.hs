import Control.Applicative
import Control.Monad (forM_)
import System.IO

total money price exch = n + exchange n exch where
    n = money `div` price
    exchange n exch
        | n < exch = 0
        | otherwise = 1 + exchange (n - exch + 1) exch

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        n_temp <- getLine
        let n_t = words n_temp
            money = read $ n_t!!0 :: Int
            price = read $ n_t!!1 :: Int
            exch  = read $ n_t!!2 :: Int
        print $ total money price exch

