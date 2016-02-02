import Control.Applicative
import Control.Monad
import System.IO

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

encrypt message h w n = [[message !! (row + col * w) | col <- [0..(h - 1)], row + col * w < n] | row <- [0..(w - 1)]]

main :: IO ()
main = do
    s <- getLine
    let n = length s
        a = isqrt n
        w = if a * a == n
            then a
            else a + 1
        h' = n `div` w
        h = if w * h' >= n
                then h'
                else h' + 1
    putStr $ unwords $ encrypt s h w n

