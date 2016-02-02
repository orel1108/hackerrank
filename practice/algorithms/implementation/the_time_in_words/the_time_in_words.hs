import Control.Applicative
import Control.Monad
import System.IO

toWord value
    | value == 1  = "one"
    | value == 2  = "two"
    | value == 3  = "three"
    | value == 4  = "four"
    | value == 5  = "five"
    | value == 6  = "six"
    | value == 7  = "seven"
    | value == 8  = "eight"
    | value == 9  = "nine"
    | value == 10 = "ten"
    | value == 11 = "eleven"
    | value == 12 = "twelve"
    | value == 13 = "thirteen"
    | value == 14 = "fourteen"
    | value == 15 = "fifteen"
    | value == 16 = "sixteen"
    | value == 17 = "seventeen"
    | value == 18 = "eighteen"
    | value == 19 = "nineteen"
    | value == 20 = "twenty"
    
timeInWords h m
    | m == 0  =  toWord h ++ " o' clock"
    | m == 1  = "one minute past " ++ toWord h
    | m == 15 = "quarter past " ++ toWord h
    | m < 21  = toWord m ++ " minutes past " ++ toWord h
    | m < 30  = "twenty " ++ (toWord $ m `mod` 10) ++ " minutes past " ++ toWord h
    | m == 30 = "half past " ++ toWord h
    | m == 59 = "one to " ++ toWord (h + 1)
    | m == 45 = "quarter to " ++ toWord (h + 1)
    | m > 39  = toWord (60 - m) ++ " minutes to " ++ toWord (h + 1)
    | m > 30  = "twenty " ++ (toWord $ (60 - m) `mod` 10) ++ " minutes to " ++ toWord (h + 1)

main :: IO ()
main = do
    h <- readLn :: IO Int
    m <- readLn :: IO Int
    putStr $ timeInWords h m

