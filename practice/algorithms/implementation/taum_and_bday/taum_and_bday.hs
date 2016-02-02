import Control.Applicative
import Control.Monad
import System.IO

solve b w x y z
    | x + z < y = x * (b + w) + z * w
    | y + z < x = y * (b + w) + z * b
    | otherwise = x * b + y * w

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        b_temp <- getLine
        let b_t = words b_temp
            b = read $ b_t!!0 :: Integer
            w = read $ b_t!!1 :: Integer
        x_temp <- getLine
        let x_t = words x_temp
            x = read $ x_t!!0 :: Integer
            y = read $ x_t!!1 :: Integer
            z = read $ x_t!!2 :: Integer
        print $ solve b w x y z
