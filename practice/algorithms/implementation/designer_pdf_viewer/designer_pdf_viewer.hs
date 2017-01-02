module Main where
import Data.Char

getHeight :: String -> [Int] -> Int
getHeight w h = getHeight' w h 0
    where
        getHeight' []    h max_h = max_h
        getHeight' (c:w) h max_h = getHeight' w h (max max_h curr_h)
            where
                pos = ord c - (ord 'a')
                curr_h = h !! pos

main :: IO ()
main = do
    h_temp <- getLine
    word <- getLine
    let h = map read $ words h_temp :: [Int]
        max_h = getHeight word h
        r = length word * max_h
    print r

