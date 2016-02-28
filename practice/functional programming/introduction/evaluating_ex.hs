factorial 0 = 1
factorial n = n * factorial (n - 1)

solve :: Double -> Double
solve x = sum [x ** k / (factorial k) | k <- [0,1..9]]

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words

