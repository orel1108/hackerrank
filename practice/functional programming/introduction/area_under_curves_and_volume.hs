import Text.Printf (printf)

f :: [Int] -> [Int] -> Double -> Double
f a b x = sum [fromIntegral(a !! k) * x ** fromIntegral(b !! k) | k <- [0,1..(length a) - 1]]

solve :: Int -> Int -> [Int] -> [Int] -> [Double]
solve l r a b = [s, v] where
    s = (sum $ map (\x -> f a b x) [fromIntegral l,(fromIntegral l + 0.001)..fromIntegral r]) / 1000
    v = pi * (sum $ map (\x -> (f a b x) ** 2) [fromIntegral l,(fromIntegral l + 0.001)..fromIntegral r]) / 1000

main :: IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\[a, b, [l, r]] -> solve l r a b). map (map read. words). lines

