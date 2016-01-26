import Data.Char

caesar :: Int -> String -> String
caesar k message = map f message
    where 
        f c
            | isAsciiLower c = tr 'a' k c
            | isAsciiUpper c = tr 'A' k c
            | otherwise = c
 
tr :: Char -> Int -> Char -> Char
tr base offset char = let ob = fromIntegral $ ord base
                          oc = fromIntegral $ ord char in
                          chr $ fromIntegral (ob + (oc - ob + offset) `mod` 26)
                          
main = do
    n <- getLine
    s <- getLine
    k <- readLn :: IO Int
    putStr $ caesar k s
