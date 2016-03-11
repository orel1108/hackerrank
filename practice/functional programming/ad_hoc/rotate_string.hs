import Control.Monad (forM_)
import Data.List

rotations s n = [(drop k s) ++ (take k s) | k <- [1,2..n]]

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_ -> do
        s <- getLine
        let n = length s
            r = rotations s n
        putStrLn $ intercalate " " r

