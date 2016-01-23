get_fine [d1, m1, y1] [d2, m2, y2]
    | y1 > y2 = 10000
    | y1 < y2 = 0
    | m1 > m2 = (m1 - m2) * 500
    | m1 < m2 = 0
    | d1 > d2 = (d1 - d2) * 15
    | otherwise = 0

main :: IO ()
main = do
    date_1 <- getLine
    date_2 <- getLine
    let [d1, m1, y1] = map (read :: String -> Int) $ words date_1
        [d2, m2, y2] = map (read :: String -> Int) $ words date_2
    print $ get_fine [d1, m1, y1] [d2, m2, y2] 
