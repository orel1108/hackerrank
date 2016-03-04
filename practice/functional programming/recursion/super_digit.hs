import Data.Char (digitToInt)

digit_sum' :: Integer -> Integer
digit_sum' n = sum $ map (fromIntegral.digitToInt) (show n)

digit_sum :: Integer -> Integer
digit_sum d
    | d < 10 = d
    | otherwise = (d `mod` 10) + digit_sum (d `div` 10)

super_digit :: Integer -> Integer
super_digit d
    | d < 10 = d
    | otherwise = super_digit $ digit_sum' d

main = do
    input <- getLine
    let w = words input
        n = (digit_sum' (read (w !! 0) :: Integer)) * (read (w !! 1) :: Integer) in
        print $ super_digit n

