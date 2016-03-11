import Control.Monad (forM_)
import Data.List

primesTo n = eratos [2..n] where
    eratos []     = []
    eratos (p:xs) = p : eratos (xs Data.List.\\ [p, p+p..n])

primes = primesTo 1100

isPrime' _ [] = True
isPrime' n (p:plist) = do
    if p < n
        then if n `mod` p == 0
            then False
            else isPrime' n plist
        else True
        
isPrime n = n > 1 && isPrime' n primes

isDead n = not (isPrime n) || '0' `elem` (show n)

isLeft n = do
    all isPrime $ map (read :: String -> Int) [drop k sn | k <- [0..d]] where
        sn = show n
        d = length sn - 1
        
isRight n = do
    all isPrime $ map (read :: String -> Int)[take k sn | k <- [1..d]] where
        sn = show n
        d = length sn

classify n
    | isDead n = "DEAD"
    | isLeft n && isRight n = "CENTRAL"
    | isLeft n = "LEFT"
    | isRight n = "RIGHT"
    | otherwise = "DEAD"

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        n <- readLn :: IO Int
        putStrLn $ classify n

