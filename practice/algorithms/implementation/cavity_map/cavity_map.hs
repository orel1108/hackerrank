import Control.Applicative
import Control.Monad
import System.IO

getMultipleLines :: Int -> IO [String]

getMultipleLines n
    | n <= 0 = return []
    | otherwise = do          
        x <- getLine         
        xs <- getMultipleLines (n-1)    
        let ret = (x:xs)    
        return ret

findCavityUtil grid row col n
    | row == 0 || row == n - 1 = (grid !! row) !! col
    | col == 0 || col == n - 1 = (grid !! row) !! col
    | (grid !! (row - 1)) !! col >= (grid !! row) !! col = (grid !! row) !! col
    | (grid !! (row + 1)) !! col >= (grid !! row) !! col = (grid !! row) !! col
    | (grid !! row) !! (col - 1) >= (grid !! row) !! col = (grid !! row) !! col
    | (grid !! row) !! (col + 1) >= (grid !! row) !! col = (grid !! row) !! col
    | otherwise = 'X'

findCavity grid n = [[findCavityUtil grid row col n | col <- [0..(n - 1)]] | row <- [0..(n - 1)]]

main :: IO ()
main = do
    n <- readLn :: IO Int
    grid <- getMultipleLines n
    putStr $ unlines $ findCavity grid n

