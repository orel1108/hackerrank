f arr = sum (filter (\x -> odd x) arr)

main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata

