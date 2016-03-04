f :: Int -> Int -> Int -> Int
f x a k
    | x < a ^ k = 0
    | x == a ^ k = 1
    | otherwise = sum [f (x - a ^ k) b k | b <- [(a + 1),(a + 2)..32]]
    
solve x k = sum [f x a k | a <- [1,2..32]]

main = do
    x <- getLine
    k <- getLine
    let ix = read x :: Int
    let ik = read k :: Int
    print $ solve ix ik

