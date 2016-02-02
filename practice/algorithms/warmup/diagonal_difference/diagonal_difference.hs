import qualified Data.Matrix as Matrix

diag_sum :: Matrix.Matrix Int -> Int -> Int
diag_sum matrix n = sum [Matrix.getElem k k matrix | k <- [1..n]]

codiag_sum :: Matrix.Matrix Int -> Int -> Int
codiag_sum matrix n = sum [Matrix.getElem (n + 1 - k) k matrix | k <- [1..n]]

main :: IO ()
main = do
    n_temp <- getLine
    m_temp <- getContents
    let n = read n_temp :: Int
        matrix = Matrix.fromLists $ map (map (read :: String -> Int) . words) $ lines m_temp
        diag = diag_sum matrix n
        codiag = codiag_sum matrix n
    print $ abs (diag - codiag)

