import Control.Applicative
import Control.Monad
import System.IO
import qualified Data.Matrix as Matrix
import Data.List

getMultipleLines :: Int -> IO [String]

getMultipleLines n
    | n <= 0 = return []
    | otherwise = do          
        x <- getLine         
        xs <- getMultipleLines (n-1)    
        let ret = (x:xs)    
        return ret

contains mgrid mpattern rg cg rp cp = do
    any (==True) [Matrix.submatrix r (r + rp - 1) c (c + cp - 1) mgrid ==  mpattern | r <- [1..(rg - rp + 1)], c <- [1..(cg - cp + 1)]]

main :: IO ()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \_  -> do
        g_temp <- getLine
        let g_t = words g_temp
            rg = read $ g_t!!0 :: Int
            cg = read $ g_t!!1 :: Int
        grid <- getMultipleLines rg
        
        r_temp <- getLine
        let r_t = words r_temp
            rp = read $ r_t!!0 :: Int
            cp = read $ r_t!!1 :: Int
        pattern <- getMultipleLines rp    
        let ans = contains (Matrix.fromLists grid) (Matrix.fromLists pattern) rg cg rp cp
        if ans
            then putStrLn "YES"
            else putStrLn "NO"


