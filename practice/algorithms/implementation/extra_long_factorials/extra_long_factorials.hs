import Control.Applicative
import Control.Monad
import System.IO

factorial :: Integer -> Integer
factorial n
    | n == 0 = 1
    | otherwise = n * factorial (n - 1)

main :: IO ()
main = do
    n <- readLn :: IO Integer
    print $ factorial n
