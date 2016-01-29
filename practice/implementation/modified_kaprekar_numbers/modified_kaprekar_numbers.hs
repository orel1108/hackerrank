import Control.Monad (forM_)

numDigits 0 = 0
numDigits n = 1 + numDigits (n `div` 10)

isKaprekar value = (left + right) == value where
    nd = numDigits value
    base = 10 ^ nd
    sqr = value ^ 2
    right = sqr `mod` base
    left  = sqr `div` base

main = do
    p <- readLn :: IO Integer
    q <- readLn :: IO Integer
    let s = filter isKaprekar [p..q]
    if null s
        then putStr "INVALID RANGE"
        else putStr $ unwords $ map show s
