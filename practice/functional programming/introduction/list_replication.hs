f :: Int -> [Int] -> [Int]
f n [] = []
f n (x:arr) = (replicate n x) ++ (f n arr)

main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words

