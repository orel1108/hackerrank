gcdValArr :: Integer -> [Integer] -> Integer
gcdValArr _ [] = 1
gcdValArr val (a:arr) = d * gcdValArr val' arr where
    d = gcd val a
    val' = val `div` d

gcdValArr' :: Integer -> [Integer] -> [Integer]
gcdValArr' _ [] = []
gcdValArr' val (a:arr) = a' : gcdValArr' val' arr where
    d = gcd val a
    a' = a `div` d
    val' = val `div` d

gcdArrArr :: [Integer] -> [Integer] -> Integer
gcdArrArr [] b = 1
gcdArrArr (a:arr) b = gcdValArr a b * gcdArrArr arr b' where
    b' = gcdValArr' a b

main = do
    n <- readLn :: IO Int
    sa <- getLine
    m <- readLn :: IO Int
    sb <- getLine
    let a = map (read :: String -> Integer) $ words sa
        b = map (read :: String -> Integer) $ words sb
    print $ (gcdArrArr a b) `mod` 1000000007

