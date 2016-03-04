triangle 1 = [[1]]
triangle 2 = [[1], [1, 1]]
triangle n = x ++ [[1] ++ [(y !! k) + (y !! (k + 1)) | k <- [0,1..(length y - 2)]] ++ [1]] where
    x = triangle (n - 1)
    y = last x

print_list [] = putStrLn ""
print_list (x:xs) = do putStr $ show x ++ " "
                       print_list xs

print_triangle [] = return ()
print_triangle (x:xs) = do print_list x
                           print_triangle xs

main = do
    input <- getLine
    print_triangle . triangle . (read :: String -> Int) $ input

