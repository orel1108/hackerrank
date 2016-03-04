gcd' :: Integral a => a -> a -> a
gcd' n m = if n == m 
            then n 
            else if n > m 
                then gcd' (n - m) m 
                else gcd' m n

main = do
  input <- getLine
  print . uncurry gcd' . listToTuple . convertToInt . words $ input
 where
  listToTuple (x:xs:_) = (x,xs)
  convertToInt = map (read :: String -> Int)

