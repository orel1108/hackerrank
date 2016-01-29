import Control.Applicative
import Control.Monad
import System.IO

getHeight :: Int -> Int
getHeight ncycles
    | ncycles == 0 = 1
    | otherwise = 
        if odd ncycles
            then 2 * getHeight (ncycles - 1)
            else 1 + getHeight (ncycles - 1)

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        n <- readLn :: IO Int
        print $ getHeight n

