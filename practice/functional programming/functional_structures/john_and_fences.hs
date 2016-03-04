area xs pos = h * (lr + lw) where
    left = reverse $ take pos xs
    right = drop pos xs
    h = xs !! pos
    lw = length $ takeWhile (>=h) left
    lr = length $ takeWhile (>=h) right

maxArea xs = maximum [area xs pos | pos <- [0,1..(length xs - 1)]]

index [] _ = 0
index (x:xs) a = do
    if x /= a
        then 1 + index xs a
        else 0

maxArea' [] = 0
maxArea' xs = maximum [h * w, maxArea' left, maxArea' right] where
    h = minimum xs
    w = length xs
    pos = index xs h
    left = take pos xs
    right = drop (pos + 1) xs

main = do
    n <- readLn :: IO Int
    sa <- getLine
    let a = map (read :: String -> Int) $ words sa
    print $ maxArea' a

