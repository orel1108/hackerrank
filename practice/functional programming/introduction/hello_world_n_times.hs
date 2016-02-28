hello_worlds n = putStrLn $ unlines (replicate n "Hello World")

main = do
   n <- readLn :: IO Int
   hello_worlds n

